/** @file main.c
 *  @author Tien.P.V
 *  @date 24-Apr-2018
 */

#include <stdbool.h>
#include <stdint.h>
#include <driverlib/sysctl.h>
#include <driverlib/gpio.h>
#include <inc/hw_memmap.h>
#include <inc/tm4c123gh6pm.h>
#include "config.h"

int main(void){
	System_Init();
	uint32_t clk = SysCtlClockGet();
	while(1) {
	}
}
