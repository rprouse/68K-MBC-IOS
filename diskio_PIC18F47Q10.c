/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for Petit FatFs (C)ChaN, 2014      */
/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/
/* Modified for the PIC18F47Q10 (MPLABX + MCC) by Just4Fun, 2020         */
/*                                                                       */
/* MPLABX Info:                                                          */
/*                                                                       */
/* Tested with MPLABX v5.40 + XC8 v2.20 + MCC v3.95.0                    */
/*-----------------------------------------------------------------------*/

#include "diskio.h"

/*-----------------------------------------------------------------------*/
/* Platform dependent macros and functions for:                          */
/* HW ref: A091020 (68k-MBC) - PIC18F47Q10                   */
/*-----------------------------------------------------------------------*/

#include "mcc_generated_files/mcc.h"
#include "diskio_PIC18F47Q10.h"

#define SS_LOW()	SS__SetLow()     /* Set CS low */
#define	SS_HIGH()	SS__SetHigh()    /* Set CS high */
#define	IS_SS_LOW	!SS__GetValue()  /* Test if CS is low */
#define	FORWARD(d)	xmit(d)			 /* Data forwarding function (to null) */



static BYTE send_singlecmd (
	BYTE cmd,                   // 1st byte (Start + Index)
	DWORD arg                   // Argument (32 bits)
);

static void xmit(char d) {}     // Dummy write console


static void init_spi (void)		/* Initialize SPI port */
{
    // Initialize the PIC18F47Q10 MSSP1 as SPI1 using MCC functions
    SPI1_Initialize();
    SPI1_Open(SPI1_DEFAULT);
}

static void dly_100us (void)	/* Delay 100 microseconds */
{
    __delay_us(100);
}

static void xmit_spi (BYTE d)	/* Send a byte to the SDC/MMC */
{
	SSP1BUF = d;                /* Start an SPI transaction */
    while (!SSP1STATbits.BF);   /* Wait for end of the transaction */
	d = SSP1BUF;				/* Discard received byte and clear SSP1STATbits.BF */
}

static BYTE rcv_spi (void)		/* Send a 0xFF to the SDC/MMC and get the received byte */
{
	SSP1BUF = 0xFF;             /* Start an SPI transaction */
	while (!SSP1STATbits.BF) ;	/* Wait for end of the transaction */
	return (BYTE)SSP1BUF;       /* Get received byte */
}


/*--------------------------------------------------------------------------

   Module Private Functions

---------------------------------------------------------------------------*/


/* Definitions for MMC/SDC command */
#define CMD0	(0x40+0)        /* GO_IDLE_STATE */
#define CMD1	(0x40+1)        /* SEND_OP_COND (MMC) */
#define	ACMD41	(0xC0+41)       /* SEND_OP_COND (SDC) */
#define CMD8	(0x40+8)        /* SEND_IF_COND */
#define CMD16	(0x40+16)       /* SET_BLOCKLEN */
#define CMD17	(0x40+17)       /* READ_SINGLE_BLOCK */
#define CMD24	(0x40+24)       /* WRITE_BLOCK */
#define CMD55	(0x40+55)       /* APP_CMD */
#define CMD58	(0x40+58)       /* READ_OCR */

/* Card type flags (CardType) */
#define CT_MMC		0x01        /* MMC ver 3 */
#define CT_SD1		0x02        /* SD ver 1 */
#define CT_SD2		0x04        /* SD ver 2 */
#define CT_BLOCK	0x08        /* Block addressing */

static BYTE CardType;           /* Detected card type */


/*-----------------------------------------------------------------------*/
/* Send a command packet to the SDC/MMC                                  */
/*-----------------------------------------------------------------------*/


static BYTE send_cmd (
	BYTE cmd,                   /* 1st byte (Start + Index) */
	DWORD arg                   /* Argument (32 bits) */
)
{
	BYTE res;

	if (cmd & 0x80) {           /* ACMD<n> is the command sequence of CMD55-CMD<n> */
		cmd &= 0x7F;
		res = send_singlecmd(CMD55, 0);
		if (res > 1) return res;
	}

    res = send_singlecmd(cmd, arg);
	return res;                 /* Return with the response value */
}

static BYTE send_singlecmd (
	BYTE cmd,                   /* 1st byte (Start + Index) */
	DWORD arg                   /* Argument (32 bits) */
)
{
    BYTE  n, res;
    
    /* Select the card */
	SS_HIGH();
	rcv_spi();
	SS_LOW();
	rcv_spi();

	/* Send a command packet */
	xmit_spi(cmd);						/* Start + Command index */
	xmit_spi((BYTE)(arg >> 24));		/* Argument[31..24] */
	xmit_spi((BYTE)(arg >> 16));		/* Argument[23..16] */
	xmit_spi((BYTE)(arg >> 8));			/* Argument[15..8] */
	xmit_spi((BYTE)arg);				/* Argument[7..0] */
	n = 0x01;							/* Dummy CRC + Stop */
	if (cmd == CMD0) n = 0x95;			/* Valid CRC for CMD0(0) */
	if (cmd == CMD8) n = 0x87;			/* Valid CRC for CMD8(0x1AA) */
	xmit_spi(n);

	/* Receive a command response */
	n = 10;                     /* Wait for a valid response in timeout of 10 attempts */
	do {
		res = rcv_spi();
	} while ((res & 0x80) && --n);

	return res;                 /* Return with the response value */
}


/*-----------------------------------------------------------------------*/
/* Initialize Disk Drive                                                 */
/*-----------------------------------------------------------------------*/


DSTATUS disk_initialize (void)
{
	BYTE n, cmd, ty, ocr[4];
	UINT tmr;

#if PF_USE_WRITE
	if (CardType && IS_SS_LOW) disk_writep(0, 0);	/* Finalize write process if it is in progress */
#endif
	init_spi();                 /* Initialize ports to control SDC/MMC */
	SS_HIGH();
	for (n = 10; n; n--) rcv_spi();                 /* 80 Dummy clocks with CS=H */

	ty = 0;
	if (send_cmd(CMD0, 0) == 1) {                   /* Enter Idle state */
		if (send_cmd(CMD8, 0x1AA) == 1) {           /* SDv2 */
			for (n = 0; n < 4; n++) ocr[n] = rcv_spi();		/* Get trailing return value of R7 resp */
			if (ocr[2] == 0x01 && ocr[3] == 0xAA) {			/* The card can work at vdd range of 2.7-3.6V */
				for (tmr = 10000; tmr && send_cmd(ACMD41, 1UL << 30); tmr--) dly_100us();	/* Wait for leaving idle state (ACMD41 with HCS bit) */
				if (tmr && send_cmd(CMD58, 0) == 0) {		/* Check CCS bit in the OCR */
					for (n = 0; n < 4; n++) ocr[n] = rcv_spi();
					ty = (ocr[0] & 0x40) ? CT_SD2 | CT_BLOCK : CT_SD2;	/* SDv2 (HC or SC) */
				}
			}
		} else {							/* SDv1 or MMCv3 */
			if (send_cmd(ACMD41, 0) <= 1) 	{
				ty = CT_SD1; cmd = ACMD41;	/* SDv1 */
			} else {
				ty = CT_MMC; cmd = CMD1;	/* MMCv3 */
			}
			for (tmr = 10000; tmr && send_cmd(cmd, 0); tmr--) dly_100us();	/* Wait for leaving idle state */
			if (!tmr || send_cmd(CMD16, 512) != 0) {		/* Set R/W block length to 512 */
				ty = 0;
			}
		}
	}
	CardType = ty;
	SS_HIGH();
	rcv_spi();

	return ty ? 0 : STA_NOINIT;
}


/*-----------------------------------------------------------------------*/
/* Read Partial Sector                                                   */
/*-----------------------------------------------------------------------*/


DRESULT disk_readp (
	BYTE *buff,		/* Pointer to the read buffer (NULL:Read bytes are forwarded to the stream) */
	DWORD sector,	/* Sector number (LBA) */
	UINT offset,	/* Byte offset to read from (0..511) */
	UINT count		/* Number of bytes to read (ofs + cnt mus be <= 512) */
)
{
	DRESULT res;
	BYTE rc;
	UINT bc;


	if (!(CardType & CT_BLOCK)) sector *= 512;	/* Convert to byte address if needed */

	res = RES_ERROR;
	if (send_cmd(CMD17, sector) == 0) {         /* READ_SINGLE_BLOCK */

		bc = 40000;
		do {                                    /* Wait for data packet */
			rc = rcv_spi();
		} while (rc == 0xFF && --bc);

		if (rc == 0xFE) {                       /* A data packet arrived */
			bc = 514 - offset - count;

			/* Skip leading bytes */
			if (offset) {
				do rcv_spi(); while (--offset);
			}

			/* Receive a part of the sector */
			if (buff) {                         /* Store data to the memory */
				do {
					*buff++ = rcv_spi();
				} while (--count);
			} else {                            /* Forward data to the outgoing stream (depends on the project) */
				do {
					FORWARD(rcv_spi());
				} while (--count);
			}

			/* Skip remaining bytes and CRC */
			do { rcv_spi(); } while (--bc);

			res = RES_OK;
		}
	}

	SS_HIGH();
	rcv_spi();

	return res;
}


/*-----------------------------------------------------------------------*/
/* Write Partial Sector                                                  */
/*-----------------------------------------------------------------------*/


#if PF_USE_WRITE
DRESULT disk_writep (
	const BYTE *buff,	/* Pointer to the bytes to be written (NULL:Initiate/Finalize sector write) */
	DWORD sc			/* Number of bytes to send, Sector number (LBA) or zero */
)
{
	DRESULT res;
	UINT bc;
	static WORD wc;

	res = RES_ERROR;

	if (buff) {                 /* Send data bytes */
		bc = (WORD)sc;
		while (bc && wc) {		/* Send data bytes to the card */
			xmit_spi(*buff++);
			wc--; bc--;
		}
		res = RES_OK;
	} else {
		if (sc) {                                   /* Initiate sector write process */
			if (!(CardType & CT_BLOCK)) sc *= 512;	/* Convert to byte address if needed */
			if (send_cmd(CMD24, sc) == 0) {			/* WRITE_SINGLE_BLOCK */
				xmit_spi(0xFF); xmit_spi(0xFE);		/* Data block header */
				wc = 512;							/* Set byte counter */
				res = RES_OK;
			}
		} else {                /* Finalize sector write process */
			bc = wc + 2;
			while (bc--) xmit_spi(0);               /* Fill left bytes and CRC with zeros */
			if ((rcv_spi() & 0x1F) == 0x05) {       /* Receive data resp and wait for end of write process in timeout of 500ms */
				for (bc = 5000; rcv_spi() != 0xFF && bc; bc--) dly_100us();	/* Wait ready */
				if (bc) res = RES_OK;
			}
			SS_HIGH();
			rcv_spi();
		}
	}

	return res;
}
#endif


/*-----------------------------------------------------------------------*/
/* Set SPI speed                                                 */
/*-----------------------------------------------------------------------*/


void setSpiSpeed(spiSpeed_t speed)
{
    switch (speed)
    {
        case SPI_LOW:
            // Set SPI1 @ 100kHz
            SSP1ADD = 0x9f;
            SSP1CON1bits.SSPM = 0b1010;  // SPI Master mode: Clock = FOSC/(4*(SSPxADD+1))
        break;
        
        case SPI_NORMAL:
            // Set SPI1 @ 4MHz
            SSP1CON1bits.SSPM = 0b0001;  // SPI Master mode: Clock = Fosc/16     
        break;
        
        case SPI_HIGH:
            // Set SPI1 @ 8MHz
            SSP1ADD = 0x01;
            SSP1CON1bits.SSPM = 0b1010;  // SPI Master mode: Clock = FOSC/(4*(SSPxADD+1))
        break;
    }
}