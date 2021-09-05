/*-----------------------------------------------------------------------*/
/* Header for the PIC18F47Q10 (MPLABX + MCC) by Just4Fun, 2020         */
/*                                                                       */
/* MPLABX Info:                                                          */
/*                                                                       */
/* Tested with MPLABX v5.40 + XC8 v2.20 + MCC v3.95.0                    */
/*-----------------------------------------------------------------------*/

#ifndef _DISKIO_18f_DEFINED
#define	_DISKIO_18f_DEFINED

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
    

// SPI speed selector definition
typedef enum {
	SPI_LOW,        // Low speed (100kHz) for initialization only
	SPI_NORMAL,		// Normal speed (4MHz)
    SPI_HIGH,       // High speed (8MHz)
} spiSpeed_t;

void setSpiSpeed(spiSpeed_t speed);


#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* _DISKIO_18f_DEFINED */
