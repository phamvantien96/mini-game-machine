/** @file main.c
 *  @author Tien.P.V
 *  @date 24-Apr-2018
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <driverlib/sysctl.h>
#include <driverlib/systick.h>
#include <driverlib/gpio.h>
#include <inc/hw_memmap.h>
#include <inc/tm4c123gh6pm.h>
#include "config.h"
#include "lcd_driver.h"
#include "image.h"
#include "joystick.h"

uint32_t ui32Value[2];

int main(void){
	System_Init();
	ADC_Init();
//	LCD_init();
//	LCD_reset();
//	LCD_begin();
//	setRotation(0);
//	drawRGBBitmap(0, 0, img_woof.image, img_woof.numCols, img_woof.numRows);
//	uint8_t * pData;
//	pData = (uint8_t *) calloc(100, sizeof(uint8_t));
//	int32_t i;
	while(1)
	{
//		ADCProcessorTrigger(ADC0_BASE, 2);
		//while(!ADCIntStatus(ADC0_BASE, 2, false)) {}

//		SysTick_Wait1ms(30);
//		i = 0;
//		while(1 == UARTCharsAvail(UART0_BASE))
//		{
//			pData[i] = (uint8_t) UARTCharGetNonBlocking(UART0_BASE);
//			if(0 == i)		GPIO_PORTF_DATA_R = 0x02;
//			else			GPIO_PORTF_DATA_R = 0;
//			i++;
//		}
//
//		GPIO_PORTF_DATA_R = 0x04;
//
//		if(0 == i)		GPIO_PORTF_DATA_R = 0x02;
//		else			GPIO_PORTF_DATA_R = 0;
//		while(i)
//		{
//			UARTCharPut(UART0_BASE, pData[i-1]);
//			i--;
//		}
	}
}
