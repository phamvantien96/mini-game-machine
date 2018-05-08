/** @file lcd_driver.c
 *  @author Tung.T.T
 *  @date 24-Apr-2018
 *  @brief The file contains the prototype of lcd driver
 */

#ifndef SRC_LCD_DRIVER_H_
#define SRC_LCD_DRIVER_H_


///****************************************************************************
///
/// HEADER INCLUDE
///
///****************************************************************************
#include <stdbool.h>
#include <stdint.h>
#include <inc/tm4c123gh6pm.h>
#include "registers.h"

#ifdef __cplusplus
extern "C"
{
#endif

///****************************************************************************
///
/// DEFINITION
///
///****************************************************************************
/*!
 *  Parameter for TFT LCD
 */
#define TFTWIDTH   		240
#define TFTHEIGHT  		320

/*!
 *  Connection of circuit
 */
#define RD_PORT 		GPIO_PORTE_DATA_R
#define WR_PORT 		GPIO_PORTE_DATA_R
#define CD_PORT 		GPIO_PORTE_DATA_R
#define CS_PORT 		GPIO_PORTE_DATA_R
#define RS_PORT 		GPIO_PORTE_DATA_R
#define DATA_PORT		GPIO_PORTB_DATA_R

/*!
 *  Masks for all control pins
 */
#define RD_MASK 		0x01
#define WR_MASK 		0x02
#define CD_MASK 		0x04
#define CS_MASK 		0x08
#define RS_MASK 		0x10

/*!
 *  Set or clear control pins
 */
#define RD_ACTIVE  		RD_PORT &= ~RD_MASK
#define RD_IDLE   		RD_PORT |=  RD_MASK
#define WR_ACTIVE  		WR_PORT &= ~WR_MASK
#define WR_IDLE    		WR_PORT |=  WR_MASK
#define CD_COMMAND 		CD_PORT &= ~CD_MASK
#define CD_DATA    		CD_PORT |=  CD_MASK
#define CS_ACTIVE  		CS_PORT &= ~CS_MASK
#define CS_IDLE    		CS_PORT |=  CS_MASK
#define RS_SET 		 	RS_PORT |= RS_MASK
#define RS_CLEAR   		RS_PORT &= ~RS_MASK
#define WR_STROBE 		{ 					\
							WR_ACTIVE; 		\
							WR_IDLE; 		\
						}

/*!
 *  Common color
 */
#define	BLACK   		0x0000
#define	BLUE   			0x001F
#define	RED    			0xF800
#define	GREEN   		0x07E0
#define CYAN    		0x07FF
#define MAGENTA 		0xF81F
#define YELLOW  		0xFFE0
#define WHITE   		0xFFFF

///****************************************************************************
///
/// MARCO
///
///****************************************************************************
/*!
 *  \def DELAY(c)
 *  Delay some cycles
 */
#define DELAY(c) 		{						 \
							unsigned char i = c; \
							while(i--);			 \
						}

/*!
 *  Write 8-bit value to LCD data lines
 */
#define write8(d) {  \
	GPIO_PORTB_DATA_R = d;	 \
	WR_STROBE; }

/*!
 *
 */
#define writeRegister8(a, d) { \
  CD_COMMAND; write8(a); CD_DATA; write8(d); }

/*!
 *
 */
#define writeRegister16(a, d) { \
  uint8_t hi, lo; \
  hi = (uint8_t) (a) >> 8; lo = (uint8_t) (a); CD_COMMAND; write8(hi); write8(lo); \
  hi = (uint8_t) (d) >> 8; lo = (uint8_t) (d); CD_DATA   ; write8(hi); write8(lo); }

/*!
 *
 */
#define writeRegisterPair(aH, aL, d) { \
  uint8_t hi = (d) >> 8, lo = (d); \
  CD_COMMAND; write8(aH); CD_DATA; write8(hi); \
  CD_COMMAND; write8(aL); CD_DATA; write8(lo); }

/*!
 *
 */
#ifndef pgm_read_byte
 #define pgm_read_byte(addr) (*(const unsigned char *)(addr))
#endif
#ifndef pgm_read_word
 #define pgm_read_word(addr) (*(const unsigned short *)(addr))
#endif
#ifndef pgm_read_dword
 #define pgm_read_dword(addr) (*(const unsigned long *)(addr))
#endif

///****************************************************************************
///
/// PROTOTYPE
///
///****************************************************************************
void SysTick_Init(void);
void SysTick_Wait(unsigned long);
void SysTick_Wait1ms(unsigned long delay);
void GPIO_Init(void);

void setAddrWindow(int x1, int y1, int x2, int y2);
void LCD_init(void);
void LCD_begin(void);
void LCD_reset(void);
void writeRegister32(uint8_t, uint32_t);
void drawPixel(int16_t x, int16_t y, uint16_t color);
void drawFastHLine(int16_t x0, int16_t y0, int16_t w, uint16_t color);
void drawFastVLine(int16_t x0, int16_t y0, int16_t h, uint16_t color);
void drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[], int16_t w, int16_t h);
void setLR(void);
void flood(uint16_t color, uint32_t len);
void pushColors(const uint16_t *data, uint32_t len, bool first);
void setRotation(uint8_t x);
void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t c);
void fillScreen(uint16_t color);

#ifdef __cplusplus
}
#endif

#endif /* SRC_LCD_DRIVER_H_ */
