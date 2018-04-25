/** @file lcd_driver.c
 *  @author Tung.T.T
 *  @date 24-Apr-2018
 *  @breif The file contains the prototype of lcd driver
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
#define write8inline(d) {  \
	GPIO_PORTB_DATA_R = d;	 \
	WR_STROBE; }
#define write8 write8inline

/*!
 *
 */
#define read8inline(result) {   \
	RD_ACTIVE;                    \
	DELAY(7);                     \
	result = GPIO_PORTB_DATA_R; 	\
	RD_IDLE; }
#define read8             read8inline

/*!
 *
 */
#define writeRegister8inline(a, d) { \
  CD_COMMAND; write8(a); CD_DATA; write8(d); }
#define writeRegister8    writeRegister8inline

/*!
 *
 */
#define writeRegister16inline(a, d) { \
  uint8_t hi, lo; \
  hi = (uint8_t) (a) >> 8; lo = (uint8_t) (a); CD_COMMAND; write8(hi); write8(lo); \
  hi = (uint8_t) (d) >> 8; lo = (uint8_t) (d); CD_DATA   ; write8(hi); write8(lo); }
#define writeRegister16    writeRegister16inline

/*!
 *
 */
#define writeRegisterPairInline(aH, aL, d) { \
  uint8_t hi = (d) >> 8, lo = (d); \
  CD_COMMAND; write8(aH); CD_DATA; write8(hi); \
  CD_COMMAND; write8(aL); CD_DATA; write8(lo); }
#define writeRegisterPair writeRegisterPairInline

///****************************************************************************
///
/// PROTOTYPE
///
///****************************************************************************
/** @breif SysTick_Init
 *
 *  This function use for initial the SysTick
 *
 *  @param void
 *  @return void
 */
void SysTick_Init(void);


/** @breif
 *
 *  @param void
 *  @return void
 */
void SysTick_Wait(unsigned long);

/** @breif
 *
 *  @param void
 *  @return void
 */
void SysTick_Wait1ms(unsigned long delay);

/** @breif
 *
 *  @param void
 *  @return void
 */
void SysTick_Wait10ms(unsigned long);

/** @breif
 *
 *  @param void
 *  @return void
 */
void GPIO_Init(void);

/** @breif
 *
 *  @param void
 *  @return void
 */
void setAddrWindow(int x1, int y1, int x2, int y2);

/** @breif
 *
 *  @param void
 *  @return void
 */
void LCD_init(void);

/** @breif
 *
 *  @param void
 *  @return void
 */
void LCD_begin(void);

/** @breif
 *
 *  @param void
 *  @return void
 */
void LCD_reset(void);

/** @breif
 *
 *  @param void
 *  @return void
 */
void writeRegister32(uint8_t, uint32_t);

/** @breif
 *
 *  @param void
 *  @return void
 */
void drawPixel(int16_t x, int16_t y, uint16_t color);

/** @breif
 *
 *  @param void
 *  @return void
 */
void drawFastHLine(int16_t x0, int16_t y0, int16_t w, uint16_t color);

/** @breif
 *
 *  @param void
 *  @return void
 */
void drawFastVLine(int16_t x0, int16_t y0, int16_t h, uint16_t color);

/** @breif
 *
 *  @param void
 *  @return void
 */
void setLR(void);

/** @breif
 *
 *  @param void
 *  @return void
 */
void flood(uint16_t color, uint32_t len);

/** @breif
 *
 *  @param void
 *  @return void
 */
void setRotation(uint8_t x);


#endif /* SRC_LCD_DRIVER_H_ */
