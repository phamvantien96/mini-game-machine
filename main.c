/**
 * @file main.c
 * @author Tien.P.V
 * @date 24-Apr-2018
 */

#include <stdbool.h>
#include <stdint.h>
#include <driverlib/sysctl.h>
#include <driverlib/gpio.h>
#include <inc/hw_memmap.h>
#include <inc/tm4c123gh6pm.h>

#define RGB_LED 	(GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3)
#define RED 			0x02
#define GREEN			0x08
#define BLUE			0x04
#define YELLOW			0x0A
#define CYAN			0x0C
#define MAGENTA			0x06
#define WHITE			0x0E

#define USER_SW2 		GPIO_PIN_0

void GPIO_Init(void);

int main(void){
	GPIO_Init();

	while(1) {
		if(0 == GPIOPinRead(GPIO_PORTF_BASE, USER_SW2))
			GPIOPinWrite(GPIO_PORTF_BASE, RGB_LED, WHITE);
		else
			GPIOPinWrite(GPIO_PORTF_BASE, RGB_LED, 0);
	}
}

void GPIO_Init(void) {
	/* Active PortF clock and wait for it is ready */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

    /* Config output with 2mA drive and push-pull pin type */
	GPIOPadConfigSet(GPIO_PORTF_BASE,
					 RGB_LED,
					 GPIO_STRENGTH_2MA,
					 GPIO_PIN_TYPE_STD);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, RGB_LED);

	/* Unlock and set pull-up for input PF0 */
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTF_CR_R |= 0x01;
	GPIOPadConfigSet(GPIO_PORTF_BASE,
					 USER_SW2,
					 GPIO_STRENGTH_2MA,
					 GPIO_PIN_TYPE_STD_WPU);
	GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, USER_SW2);
}
