/** @file main.c
 *  @author Tien.P.V
 *  @date 24-Apr-2018
 */

#include <stdbool.h>
#include <stdint.h>
#include <driverlib/sysctl.h>
#include <driverlib/systick.h>
#include <driverlib/gpio.h>
#include <inc/hw_memmap.h>
#include <inc/tm4c123gh6pm.h>
#include "config.h"

int main(void){
	System_Init();
	while(1) {
		uint32_t data = UARTCharGet(UART0_BASE);
		UARTCharPut(UART0_BASE, data);
	}
}
