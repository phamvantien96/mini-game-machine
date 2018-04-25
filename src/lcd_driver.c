/** @file lcd_driver.c
 *  @author Tung.T.T
 *  @date 24-Apr-2018
 *  @breif The file contains the implementations of lcd driver
 *
 *  In this file, we implement functions that communicate with TFT LCD
 *  Arduino Sheld 2.4"
 */


///****************************************************************************
///
/// HEADER INCLUDE
///
///****************************************************************************
#include "lcd_driver.h"

///****************************************************************************
///
/// GLOBAL VARIABLE
///
///****************************************************************************
static int16_t _width, _height, cursor_x, cursor_y;
static uint16_t textcolor, textbgcolor;
static uint8_t	textsize,	rotation;
static bool
	wrap,   // If set, 'wrap' text at right edge of display
	_cp437; // If set, use correct CP437 charset (default is off)

///****************************************************************************
///
/// FUNCTION IMPLEMENT
///
///****************************************************************************
void GPIO_Init() {
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB | SYSCTL_RCGC2_GPIOE;
	delay = SYSCTL_RCGC2_R;

	//Init Port B
	GPIO_PORTB_AMSEL_R &= ~0xFF;
	GPIO_PORTB_PCTL_R &= ~0xFF00FFFF;
	GPIO_PORTB_DIR_R |= 0xFF;
	GPIO_PORTB_AFSEL_R &= ~0xFF;
	GPIO_PORTB_DEN_R |= 0xFF;

	GPIO_PORTE_AMSEL_R &= ~0xFF;
	GPIO_PORTE_PCTL_R &= ~0xFFFFFFFF;
	GPIO_PORTE_DIR_R |= 0xFF;
	GPIO_PORTE_AFSEL_R &= ~0xFF;
	GPIO_PORTE_DEN_R |= 0xFF;
	GPIO_PORTE_DATA_R |= 0x1F;
}

void SysTick_Init(void) {
	NVIC_ST_CTRL_R = 0;               // disable SysTick during setup
	NVIC_ST_CTRL_R = 0x00000005;      // enable SysTick with core clock
}
// The delay parameter is in units of the 80 MHz core clock. (12.5 ns)
void SysTick_Wait(unsigned long delay) {
	NVIC_ST_RELOAD_R = delay - 1;  // number of counts to wait
	NVIC_ST_CURRENT_R = 0;       // any value written to CURRENT clears
	while ((NVIC_ST_CTRL_R & 0x00010000) == 0) { // wait for count flag
	}
}
// 800000*12.5ns equals 10ms
void SysTick_Wait1ms(unsigned long delay) {
	unsigned long i;
	for (i = 0; i < delay; i++) {
		SysTick_Wait(80000);  // wait 10ms
	}
}

void SysTick_Wait1us(unsigned long delay) {
	unsigned long i;
	for (i = 0; i < delay; i++) {
		SysTick_Wait(80);  // wait 10ms
	}
}

void LCD_init(void) {
	CS_IDLE; // Set all control bits to idle state
	WR_IDLE;
	RD_IDLE;
	CD_DATA;

	RS_SET;
	rotation = 0;
	cursor_y = cursor_x = 0;
	textsize = 1;
	textcolor = 0xFFFF;
	_width = TFTWIDTH;
	_height = TFTHEIGHT;
}

void LCD_begin(void) {
	// uint16_t a, d;
	LCD_reset();
	SysTick_Wait1ms(200);
	CS_ACTIVE;
	writeRegister8(ILI9341_SOFTRESET, 0)
	;
	//delay(50);
	SysTick_Wait1ms(50);
	writeRegister8(ILI9341_DISPLAYOFF, 0)
	;

	writeRegister8(ILI9341_POWERCONTROL1, 0x23)
	;
	//writeRegister8(ILI9341_POWERCONTROL1, 0x07);
	writeRegister8(ILI9341_POWERCONTROL2, 0x10)
	;
	writeRegister16(ILI9341_VCOMCONTROL1, 0x2B2B)
	;
	writeRegister8(ILI9341_VCOMCONTROL2, 0xC0)
	;
	writeRegister8(ILI9341_MEMCONTROL, ILI9341_MADCTL_MY | ILI9341_MADCTL_BGR)
	;
	writeRegister8(ILI9341_PIXELFORMAT, 0x55)
	;
	writeRegister16(ILI9341_FRAMECONTROL, 0x001B)
	;

	writeRegister8(ILI9341_ENTRYMODE, 0x07)
	;
	/* writeRegister32(ILI9341_DISPLAYFUNC, 0x0A822700);*/

	writeRegister8(ILI9341_SLEEPOUT, 0)
	;
	//delay(150);
	SysTick_Wait1ms(150);
	writeRegister8(ILI9341_DISPLAYON, 0)
	;
	//delay(500);
	SysTick_Wait1ms(500);
	setAddrWindow(0, 0, TFTWIDTH - 1, TFTHEIGHT - 1);
	return;
}

void LCD_reset(void) {
	uint8_t i;

	CS_IDLE;
//  CD_DATA;
	WR_IDLE;
	RD_IDLE;

	RS_CLEAR;
	SysTick_Wait1ms(2);
	RS_SET;

	// Data transfer sync
	CS_ACTIVE;
	CD_COMMAND;
	write8(0x00)
	;
	for (i = 0; i < 3; i++)
		WR_STROBE; // Three extra 0x00s
	CS_IDLE;
}

void setAddrWindow(int x1, int y1, int x2, int y2) {
	uint32_t t;
	CS_ACTIVE;

	t = x1;
	t <<= 16;
	t |= x2;
	writeRegister32(ILI9341_COLADDRSET, t);  // HX8357D uses same registers!
	t = y1;
	t <<= 16;
	t |= y2;
	writeRegister32(ILI9341_PAGEADDRSET, t); // HX8357D uses same registers!

	CS_IDLE;
}

void writeRegister32(uint8_t r, uint32_t d) {
	CS_ACTIVE;
	CD_COMMAND;
	write8(r)
	;
	CD_DATA;
	//delayMicroseconds(10);
	SysTick_Wait1us(10);
	write8(d >> 24)
	;
	//delayMicroseconds(10);
	SysTick_Wait1us(10);
	write8(d >> 16)
	;
	//delayMicroseconds(10);
	SysTick_Wait1us(10);
	write8(d >> 8)
	;
	//delayMicroseconds(10);
	SysTick_Wait1us(10);
	write8(d)
	;
	CS_IDLE;
}

void drawPixel(int16_t x, int16_t y, uint16_t color) {

	// Clip
	if ((x < 0) || (y < 0) || (x >= _width) || (y >= _height))
		return;

	CS_ACTIVE;
	setAddrWindow(x, y, _width - 1, _height - 1);
	CS_ACTIVE;
	CD_COMMAND;
	write8(0x2C)
	;
	CD_DATA;
	write8(color >> 8)
	;
	write8(color)
	;
	CS_IDLE;
}

void drawFastHLine(int16_t x, int16_t y, int16_t length, uint16_t color) {
	int16_t x2;

	// Initial off-screen clipping
	if ((length <= 0) || (y < 0) || (y >= _height) || (x >= _width)
			|| ((x2 = (x + length - 1)) < 0))
		return;

	if (x < 0) {        // Clip left
		length += x;
		x = 0;
	}
	if (x2 >= _width) { // Clip right
		x2 = _width - 1;
		length = x2 - x + 1;
	}

	setAddrWindow(x, y, x2, y);
	flood(color, length);
	setLR();
}

void drawFastVLine(int16_t x, int16_t y, int16_t length, uint16_t color) {
	int16_t y2;

	// Initial off-screen clipping
	if ((length <= 0) || (x < 0) || (x >= _width) || (y >= _height)
			|| ((y2 = (y + length - 1)) < 0))
		return;
	if (y < 0) {         // Clip top
		length += y;
		y = 0;
	}
	if (y2 >= _height) { // Clip bottom
		y2 = _height - 1;
		length = y2 - y + 1;
	}

	setAddrWindow(x, y, x, y2);
	flood(color, length);
	setLR();
}

void setLR(void) {
	CS_ACTIVE;
	writeRegisterPair(HX8347G_COLADDREND_HI, HX8347G_COLADDREND_LO, _width - 1)
	;
	writeRegisterPair(HX8347G_ROWADDREND_HI, HX8347G_ROWADDREND_LO, _height - 1)
	;
	CS_IDLE;
}

// Fast block fill operation for fillScreen, fillRect, H/V line, etc.
// Requires setAddrWindow() has previously been called to set the fill
// bounds.  'len' is inclusive, MUST be >= 1.
void flood(uint16_t color, uint32_t len) {
	uint16_t blocks;
	uint8_t i, hi = color >> 8, lo = color;

	CS_ACTIVE;
	CD_COMMAND;
	write8(0x2C)
	;

	// Write first pixel normally, decrement counter by 1
	CD_DATA;
	write8(hi)
	;
	write8(lo)
	;
	len--;

	blocks = (uint16_t) (len / 64); // 64 pixels/block
	if (hi == lo) {
		// High and low bytes are identical.  Leave prior data
		// on the port(s) and just toggle the write strobe.
		while (blocks--) {
			i = 16; // 64 pixels/block / 4 pixels/pass
			do {
				WR_STROBE;
				WR_STROBE;
				WR_STROBE;
				WR_STROBE; // 2 bytes/pixel
				WR_STROBE;
				WR_STROBE;
				WR_STROBE;
				WR_STROBE; // x 4 pixels
			} while (--i);
		}
		// Fill any remaining pixels (1 to 64)
		for (i = (uint8_t) len & 63; i--;) {
			WR_STROBE;
			WR_STROBE;
		}
	} else {
		while (blocks--) {
			i = 16; // 64 pixels/block / 4 pixels/pass
			do {
				write8(hi)
				;
				write8(lo)
				;
				write8(hi)
				;
				write8(lo)
				;
				write8(hi)
				;
				write8(lo)
				;
				write8(hi)
				;
				write8(lo)
				;
			} while (--i);
		}
		for (i = (uint8_t) len & 63; i--;) {
			write8(hi)
			;
			write8(lo)
			;
		}
	}
	CS_IDLE;
}

void setRotation(uint8_t x) {
	uint16_t t;

	rotation = (x & 3);
	switch (rotation) {
	case 0:
	case 2:
		_width = TFTWIDTH;
		_height = TFTHEIGHT;
		break;
	case 1:
	case 3:
		_width = TFTHEIGHT;
		_height = TFTWIDTH;
		break;
	}
	// Then perform hardware-specific rotation operations...

	CS_ACTIVE;

	// MEME, HX8357D uses same registers as 9341 but different values

	switch (rotation) {
	case 2:
		t = ILI9341_MADCTL_MX | ILI9341_MADCTL_BGR;
		break;
	case 3:
		t = ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR;
		break;
	case 0:
		t = ILI9341_MADCTL_MY | ILI9341_MADCTL_BGR;
		break;
	case 1:
		t = ILI9341_MADCTL_MX | ILI9341_MADCTL_MY | ILI9341_MADCTL_MV
				| ILI9341_MADCTL_BGR;
		break;
	}
	writeRegister8(ILI9341_MADCTL, t )
	; // MADCTL
	// For 9341, init default full-screen address window:
	setAddrWindow(0, 0, _width - 1, _height - 1); // CS_IDLE happens here
}

void fillRect(int16_t x1, int16_t y1, int16_t w, int16_t h,
  uint16_t fillcolor) {
  int16_t  x2, y2;

  // Initial off-screen clipping
  if( (w            <= 0     ) ||  (h             <= 0      ) ||
      (x1           >= _width) ||  (y1            >= _height) ||
     ((x2 = x1+w-1) <  0     ) || ((y2  = y1+h-1) <  0      )) return;
  if(x1 < 0) { // Clip left
    w += x1;
    x1 = 0;
  }
  if(y1 < 0) { // Clip top
    h += y1;
    y1 = 0;
  }
  if(x2 >= _width) { // Clip right
    x2 = _width - 1;
    w  = x2 - x1 + 1;
  }
  if(y2 >= _height) { // Clip bottom
    y2 = _height - 1;
    h  = y2 - y1 + 1;
  }

  setAddrWindow(x1, y1, x2, y2);
  flood(fillcolor, (uint32_t)w * (uint32_t)h);
  setLR();
}

void fillScreen(uint16_t color) {
  setAddrWindow(0, 0, _width - 1, _height - 1);
  flood(color, (long)TFTWIDTH * (long)TFTHEIGHT);
}
