
// 68008 executable binary images into flash and related constants

#ifndef ROMFILE_H
#define	ROMFILE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
const uint32_t  image_A_StrAddr = 0x7c000;     // Binary image A starting address
  
const uint8_t  image_A_[]  = {                 // Binary image A (S180221-R150521 sLoad)
  0x4F, 0xF9, 0x00, 0x07, 0xFF, 0xFA, 0x43, 0xFA, 0x04, 0x80, 0x61, 0x00, 0x02, 0xE0, 0x61, 0x00, 
  0x03, 0xF8, 0xB0, 0x3C, 0x00, 0x02, 0x66, 0x00, 0x00, 0x38, 0x20, 0x3C, 0x00, 0x00, 0x05, 0xA8, 
  0x41, 0xF9, 0x00, 0x07, 0xC0, 0x44, 0x43, 0xF9, 0x00, 0x0F, 0x80, 0x00, 0x12, 0xD8, 0x51, 0xC8, 
  0xFF, 0xFC, 0x4F, 0xF9, 0x00, 0x0F, 0xBF, 0xFE, 0x24, 0x7C, 0x00, 0x0F, 0x7F, 0xFF, 0x4E, 0xF9, 
  0x00, 0x0F, 0x80, 0x00, 0x43, 0xFA, 0x04, 0xD3, 0x61, 0x00, 0x02, 0xA2, 0x60, 0x00, 0x00, 0x2A, 
  0xB0, 0x3C, 0x00, 0x01, 0x66, 0x00, 0x00, 0x14, 0x43, 0xFA, 0x04, 0xB9, 0x61, 0x00, 0x02, 0x8E, 
  0x24, 0x7C, 0x00, 0x07, 0xBF, 0xFF, 0x60, 0x00, 0x00, 0x10, 0x43, 0xFA, 0x04, 0xA1, 0x61, 0x00, 
  0x02, 0x7C, 0x24, 0x7C, 0x00, 0x01, 0xBF, 0xFF, 0x10, 0x3A, 0x04, 0x0A, 0xB0, 0x3C, 0x00, 0x01, 
  0x67, 0x00, 0x00, 0x0E, 0x43, 0xFA, 0x04, 0xB5, 0x61, 0x00, 0x02, 0x62, 0x60, 0x00, 0x00, 0x0A, 
  0x43, 0xFA, 0x04, 0x8E, 0x61, 0x00, 0x02, 0x56, 0x43, 0xFA, 0x04, 0x1A, 0x61, 0x00, 0x02, 0x4E, 
  0x61, 0x00, 0x03, 0x2E, 0x42, 0x85, 0x61, 0x00, 0x02, 0x30, 0x61, 0x00, 0x02, 0x60, 0xB0, 0x3C, 
  0x00, 0x53, 0x67, 0x00, 0x00, 0x58, 0x7A, 0x03, 0x60, 0x00, 0x00, 0x2C, 0xB0, 0x3C, 0x00, 0x0A, 
  0x66, 0x00, 0x00, 0x40, 0x70, 0x0D, 0x61, 0x00, 0x02, 0x44, 0x60, 0x00, 0x00, 0x36, 0x61, 0x00, 
  0x02, 0x08, 0x61, 0x00, 0x02, 0x38, 0xB0, 0x3C, 0x00, 0x0D, 0x66, 0xE0, 0x70, 0x0A, 0x61, 0x00, 
  0x02, 0x2C, 0x4A, 0x05, 0x67, 0xC0, 0xBA, 0x3C, 0x00, 0x01, 0x67, 0x00, 0x02, 0x40, 0xBA, 0x3C, 
  0x00, 0x02, 0x67, 0x00, 0x02, 0x48, 0xBA, 0x3C, 0x00, 0x03, 0x67, 0x00, 0x02, 0x50, 0x60, 0x00, 
  0x02, 0xE8, 0xB0, 0x3C, 0x00, 0x53, 0x67, 0x00, 0x00, 0x04, 0x60, 0xC2, 0x61, 0x00, 0x01, 0xCA, 
  0x61, 0x00, 0x01, 0xFA, 0xB0, 0x3C, 0x00, 0x30, 0x67, 0xB4, 0xB0, 0x3C, 0x00, 0x31, 0x67, 0x00, 
  0x00, 0x1C, 0xB0, 0x3C, 0x00, 0x32, 0x67, 0x00, 0x00, 0x5C, 0xB0, 0x3C, 0x00, 0x35, 0x67, 0x9E, 
  0xB0, 0x3C, 0x00, 0x38, 0x67, 0x00, 0x00, 0xAC, 0x60, 0x00, 0x01, 0xE2, 0x42, 0x84, 0x74, 0x01, 
  0x61, 0x00, 0x01, 0x28, 0xD8, 0x01, 0x36, 0x01, 0x59, 0x43, 0x74, 0x03, 0x61, 0x00, 0x01, 0x1C, 
  0xD8, 0x01, 0xE0, 0x59, 0xD8, 0x01, 0xE0, 0x59, 0x20, 0x41, 0x74, 0x01, 0x61, 0x00, 0x01, 0x0C, 
  0xD8, 0x01, 0x10, 0x81, 0xB2, 0x18, 0x67, 0x00, 0x00, 0x04, 0x7A, 0x01, 0x51, 0xCB, 0xFF, 0xEC, 
  0x46, 0x04, 0x74, 0x01, 0x61, 0x00, 0x00, 0xF4, 0xB8, 0x01, 0x67, 0x00, 0xFF, 0x52, 0x7A, 0x02, 
  0x60, 0x00, 0xFF, 0x4C, 0x42, 0x84, 0x34, 0x3C, 0x00, 0x01, 0x61, 0x00, 0x00, 0xDE, 0xD8, 0x01, 
  0x36, 0x01, 0x5B, 0x43, 0x34, 0x3C, 0x00, 0x05, 0x61, 0x00, 0x00, 0xD0, 0xD8, 0x01, 0xE0, 0x99, 
  0xD8, 0x01, 0xE0, 0x99, 0xD8, 0x01, 0xE0, 0x99, 0xE0, 0x99, 0x20, 0x41, 0x34, 0x3C, 0x00, 0x01, 
  0x61, 0x00, 0x00, 0xB8, 0xD8, 0x01, 0x61, 0x00, 0x01, 0xF0, 0x10, 0x81, 0xB2, 0x18, 0x67, 0x00, 
  0x00, 0x06, 0x1A, 0x3C, 0x00, 0x01, 0x51, 0xCB, 0xFF, 0xE4, 0x46, 0x04, 0x34, 0x3C, 0x00, 0x01, 
  0x61, 0x00, 0x00, 0x98, 0xB8, 0x01, 0x67, 0x00, 0xFE, 0xF6, 0x1A, 0x3C, 0x00, 0x02, 0x60, 0x00, 
  0xFE, 0xEE, 0x42, 0x84, 0x34, 0x3C, 0x00, 0x01, 0x61, 0x00, 0x00, 0x80, 0xD8, 0x01, 0x36, 0x01, 
  0x5B, 0x43, 0x34, 0x3C, 0x00, 0x05, 0x61, 0x00, 0x00, 0x72, 0xD8, 0x01, 0xE0, 0x99, 0xD8, 0x01, 
  0xE0, 0x99, 0xD8, 0x01, 0xE0, 0x99, 0xE0, 0x99, 0x20, 0x41, 0x46, 0x04, 0x34, 0x3C, 0x00, 0x01, 
  0x61, 0x00, 0x00, 0x58, 0xB8, 0x01, 0x67, 0x00, 0x00, 0x0A, 0x1A, 0x3C, 0x00, 0x02, 0x60, 0x00, 
  0xFE, 0xAE, 0x43, 0xFA, 0x02, 0xAB, 0x61, 0x00, 0x00, 0xC4, 0x43, 0xFA, 0x02, 0xC2, 0x61, 0x00, 
  0x00, 0xBC, 0x61, 0x00, 0x01, 0x9C, 0x43, 0xFA, 0x02, 0xCF, 0x61, 0x00, 0x00, 0xB0, 0x43, 0xFA, 
  0x02, 0x8F, 0x61, 0x00, 0x00, 0xA8, 0x43, 0xFA, 0x02, 0x91, 0x61, 0x00, 0x00, 0xA0, 0x2C, 0x08, 
  0x61, 0x00, 0x01, 0x42, 0x43, 0xFA, 0x02, 0x2F, 0x61, 0x00, 0x00, 0x92, 0x61, 0x00, 0x01, 0x4A, 
  0x43, 0xFA, 0x02, 0x23, 0x61, 0x00, 0x00, 0x86, 0x4E, 0xD0, 0x42, 0x81, 0x61, 0x6A, 0x61, 0x00, 
  0x00, 0x9C, 0x61, 0x18, 0xB0, 0x3C, 0x00, 0xFF, 0x66, 0x00, 0x00, 0x08, 0x7A, 0x03, 0x60, 0x00, 
  0xFE, 0x66, 0xE9, 0x89, 0xD2, 0x00, 0x51, 0xCA, 0xFF, 0xE4, 0x4E, 0x75, 0xB0, 0x3C, 0x00, 0x66, 
  0x62, 0x00, 0x00, 0x2A, 0xB0, 0x3C, 0x00, 0x60, 0x62, 0x00, 0x00, 0x38, 0xB0, 0x3C, 0x00, 0x46, 
  0x62, 0x00, 0x00, 0x1A, 0xB0, 0x3C, 0x00, 0x40, 0x62, 0x00, 0x00, 0x18, 0xB0, 0x3C, 0x00, 0x39, 
  0x62, 0x00, 0x00, 0x0A, 0xB0, 0x3C, 0x00, 0x2F, 0x62, 0x00, 0x00, 0x10, 0x70, 0xFF, 0x60, 0x00, 
  0x00, 0x16, 0x04, 0x00, 0x00, 0x37, 0x60, 0x00, 0x00, 0x0E, 0x04, 0x00, 0x00, 0x30, 0x60, 0x00, 
  0x00, 0x06, 0x04, 0x00, 0x00, 0x57, 0x4E, 0x75, 0x10, 0x39, 0x00, 0x0F, 0xFF, 0xFE, 0x08, 0x00, 
  0x00, 0x02, 0x67, 0xF4, 0x10, 0x39, 0x00, 0x0F, 0xFF, 0xFD, 0x4E, 0x75, 0x2F, 0x00, 0x10, 0x19, 
  0xB0, 0x3C, 0x00, 0x00, 0x67, 0x00, 0x00, 0x12, 0x13, 0xFC, 0x00, 0x01, 0x00, 0x0F, 0xFF, 0xFD, 
  0x13, 0xC0, 0x00, 0x0F, 0xFF, 0xFC, 0x60, 0xE6, 0x20, 0x1F, 0x4E, 0x75, 0x13, 0xFC, 0x00, 0x01, 
  0x00, 0x0F, 0xFF, 0xFD, 0x13, 0xC0, 0x00, 0x0F, 0xFF, 0xFC, 0x4E, 0x75, 0x43, 0xFA, 0x01, 0xB1, 
  0x61, 0xCA, 0x43, 0xFA, 0x02, 0x6D, 0x61, 0xC4, 0x60, 0x00, 0x00, 0xBE, 0x43, 0xFA, 0x01, 0xA1, 
  0x61, 0xBA, 0x43, 0xFA, 0x02, 0x76, 0x61, 0xB4, 0x60, 0x00, 0x00, 0xAE, 0x43, 0xFA, 0x01, 0x91, 
  0x61, 0xAA, 0x43, 0xFA, 0x02, 0x81, 0x61, 0xA4, 0x60, 0x00, 0x00, 0x9E, 0x43, 0xFA, 0x01, 0x81, 
  0x61, 0x9A, 0x43, 0xFA, 0x02, 0x83, 0x61, 0x94, 0x60, 0x00, 0x00, 0x8E, 0x02, 0x47, 0x00, 0x0F, 
  0xBE, 0x3C, 0x00, 0x09, 0x65, 0x00, 0x00, 0x04, 0x5E, 0x07, 0x06, 0x47, 0x00, 0x30, 0x13, 0xFC, 
  0x00, 0x01, 0x00, 0x0F, 0xFF, 0xFD, 0x13, 0xC7, 0x00, 0x0F, 0xFF, 0xFC, 0x4E, 0x75, 0x1E, 0x06, 
  0xE8, 0x1F, 0x61, 0xD8, 0x1E, 0x06, 0x61, 0xD4, 0x4E, 0x75, 0xE0, 0x9E, 0x61, 0xF0, 0xE1, 0x9E, 
  0x61, 0xEC, 0x4E, 0x75, 0x48, 0x46, 0x61, 0xE6, 0x48, 0x46, 0x61, 0xEE, 0x4E, 0x75, 0x48, 0x46, 
  0x61, 0xE8, 0x48, 0x46, 0x61, 0xE4, 0x4E, 0x75, 0xB1, 0xCA, 0x62, 0x00, 0x00, 0x04, 0x4E, 0x75, 
  0x43, 0xFA, 0x01, 0x1D, 0x61, 0x00, 0xFF, 0x36, 0x43, 0xFA, 0x01, 0x9C, 0x61, 0x00, 0xFF, 0x2E, 
  0x2C, 0x08, 0x61, 0xD0, 0x43, 0xFA, 0x00, 0xBF, 0x61, 0x00, 0xFF, 0x22, 0x60, 0x00, 0x00, 0x1A, 
  0x10, 0x39, 0x00, 0x0F, 0xFF, 0xFE, 0x08, 0x00, 0x00, 0x02, 0x67, 0x00, 0x00, 0x0A, 0x10, 0x39, 
  0x00, 0x0F, 0xFF, 0xFD, 0x60, 0xEA, 0x4E, 0x75, 0x43, 0xFA, 0x01, 0x7F, 0x61, 0x00, 0xFE, 0xFE, 
  0x23, 0xFC, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x20, 0x23, 0xFC, 0x00, 0x00, 0x00, 0x01, 
  0x00, 0x00, 0x00, 0x0C, 0x4E, 0x72, 0x07, 0x00, 0x10, 0x39, 0x00, 0x0F, 0xFF, 0xFE, 0x08, 0x00, 
  0x00, 0x03, 0x66, 0x00, 0x00, 0x3A, 0x41, 0xFA, 0x00, 0x6C, 0x42, 0x10, 0x13, 0xFC, 0x00, 0x55, 
  0x00, 0x0F, 0xBF, 0xF0, 0x10, 0x39, 0x00, 0x0F, 0xBF, 0xF0, 0xB0, 0x3C, 0x00, 0x55, 0x66, 0x00, 
  0x00, 0x1E, 0x13, 0xFC, 0x00, 0xAA, 0x00, 0x0F, 0xBF, 0xF0, 0x10, 0x39, 0x00, 0x0F, 0xBF, 0xF0, 
  0xB0, 0x3C, 0x00, 0xAA, 0x66, 0x00, 0x00, 0x08, 0x10, 0x3C, 0x00, 0x02, 0x4E, 0x75, 0x13, 0xFC, 
  0x00, 0x55, 0x00, 0x01, 0xAF, 0xF0, 0x10, 0x39, 0x00, 0x07, 0xAF, 0xF0, 0xB0, 0x3C, 0x00, 0x55, 
  0x66, 0x00, 0x00, 0x1C, 0x13, 0xFC, 0x00, 0xAA, 0x00, 0x01, 0xAF, 0xF0, 0x10, 0x39, 0x00, 0x07, 
  0xAF, 0xF0, 0xB0, 0x3C, 0x00, 0xAA, 0x66, 0x00, 0x00, 0x06, 0x42, 0x00, 0x4E, 0x75, 0x10, 0x3C, 
  0x00, 0x01, 0x4E, 0x75, 0x01, 0x0D, 0x0A, 0x00, 0x73, 0x4C, 0x6F, 0x61, 0x64, 0x20, 0x2D, 0x20, 
  0x53, 0x2D, 0x72, 0x65, 0x63, 0x6F, 0x72, 0x64, 0x20, 0x4C, 0x6F, 0x61, 0x64, 0x65, 0x72, 0x20, 
  0x2D, 0x20, 0x53, 0x31, 0x38, 0x30, 0x32, 0x32, 0x31, 0x2D, 0x52, 0x31, 0x35, 0x30, 0x35, 0x32, 
  0x31, 0x0D, 0x0A, 0x00, 0x57, 0x61, 0x69, 0x74, 0x69, 0x6E, 0x67, 0x20, 0x69, 0x6E, 0x70, 0x75, 
  0x74, 0x20, 0x73, 0x74, 0x72, 0x65, 0x61, 0x6D, 0x2E, 0x2E, 0x2E, 0x0D, 0x0A, 0x0A, 0x00, 0x0D, 
  0x0A, 0x73, 0x4C, 0x6F, 0x61, 0x64, 0x3A, 0x20, 0x00, 0x53, 0x74, 0x61, 0x72, 0x74, 0x69, 0x6E, 
  0x67, 0x20, 0x41, 0x64, 0x64, 0x72, 0x65, 0x73, 0x73, 0x3A, 0x20, 0x30, 0x78, 0x00, 0x46, 0x6C, 
  0x75, 0x73, 0x68, 0x69, 0x6E, 0x67, 0x20, 0x69, 0x6E, 0x70, 0x75, 0x74, 0x20, 0x62, 0x75, 0x66, 
  0x66, 0x65, 0x72, 0x2E, 0x2E, 0x2E, 0x00, 0x20, 0x64, 0x6F, 0x6E, 0x65, 0x00, 0x31, 0x32, 0x38, 
  0x4B, 0x42, 0x00, 0x35, 0x31, 0x32, 0x4B, 0x42, 0x00, 0x31, 0x30, 0x32, 0x34, 0x4B, 0x42, 0x00, 
  0x20, 0x2D, 0x20, 0x4C, 0x69, 0x74, 0x65, 0x20, 0x48, 0x57, 0x20, 0x63, 0x6F, 0x6E, 0x66, 0x69, 
  0x67, 0x75, 0x72, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x0D, 0x0A, 0x00, 0x20, 0x2D, 0x20, 0x46, 0x75, 
  0x6C, 0x6C, 0x20, 0x48, 0x57, 0x20, 0x63, 0x6F, 0x6E, 0x66, 0x69, 0x67, 0x75, 0x72, 0x61, 0x74, 
  0x69, 0x6F, 0x6E, 0x0D, 0x0A, 0x00, 0x49, 0x6C, 0x6C, 0x65, 0x67, 0x61, 0x6C, 0x20, 0x41, 0x64, 
  0x64, 0x72, 0x65, 0x73, 0x73, 0x20, 0x30, 0x78, 0x00, 0x73, 0x4C, 0x6F, 0x61, 0x64, 0x3A, 0x20, 
  0x4C, 0x6F, 0x61, 0x64, 0x65, 0x72, 0x20, 0x61, 0x62, 0x6F, 0x72, 0x74, 0x65, 0x64, 0x20, 0x2D, 
  0x20, 0x53, 0x79, 0x73, 0x74, 0x65, 0x6D, 0x20, 0x68, 0x61, 0x6C, 0x74, 0x65, 0x64, 0x0D, 0x0A, 
  0x00, 0x49, 0x6C, 0x6C, 0x65, 0x67, 0x61, 0x6C, 0x20, 0x53, 0x2D, 0x72, 0x65, 0x63, 0x6F, 0x72, 
  0x64, 0x20, 0x74, 0x79, 0x70, 0x65, 0x21, 0x0D, 0x0A, 0x00, 0x52, 0x41, 0x4D, 0x20, 0x77, 0x72, 
  0x69, 0x74, 0x65, 0x20, 0x76, 0x65, 0x72, 0x69, 0x66, 0x79, 0x20, 0x66, 0x61, 0x69, 0x6C, 0x65, 
  0x64, 0x21, 0x0D, 0x0A, 0x00, 0x43, 0x68, 0x65, 0x63, 0x6B, 0x73, 0x75, 0x6D, 0x20, 0x65, 0x72, 
  0x72, 0x6F, 0x72, 0x21, 0x0D, 0x0A, 0x00, 0x49, 0x6C, 0x6C, 0x65, 0x67, 0x61, 0x6C, 0x20, 0x63, 
  0x68, 0x61, 0x72, 0x61, 0x63, 0x74, 0x65, 0x72, 0x21, 0x0D, 0x0A, 0x00
  };

#ifdef	__cplusplus
}
#endif

#endif	/* ROMFILE_H */
