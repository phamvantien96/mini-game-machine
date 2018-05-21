/*
 * communication.c
 *
 *  Created on: May 19, 2018
 *      Author: BKIC
 */

#include "communication.h"

extern char uartNum[2];

void Communication_Init(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIO);
	while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIO));
	GPIOPinConfigure(GPIO_P_URX);
	GPIOPinConfigure(GPIO_P_UTX);
	GPIOPinTypeUART(GPIO_PORT_BASE, GPIO_PIN_RX | GPIO_PIN_TX);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART);
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART))	{ }

	UARTClockSourceSet(UART_BASE, UART_CLOCK_SYSTEM);
	UARTConfigSetExpClk(UART_BASE,	SysCtlClockGet(), 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
	UARTFIFOLevelSet(UART_BASE,	UART_FIFO_TX1_8, UART_FIFO_RX1_8);
	UARTFIFOEnable(UART_BASE);
	UARTIntRegister(UART_BASE, Communication_Handler);
	UARTIntEnable(UART_BASE, UART_INT_RX);
	UARTEnable(UART_BASE);

}


void Communication_Handler(void)
{
	static uint8_t cnt;
	UARTIntClear(UART_BASE, UART_INT_RX);
//	while(UARTCharsAvail(UART_BASE))
//    {
//        UARTCharPutNonBlocking(UART_BASE, UARTCharGetNonBlocking(UART_BASE));
//	}
//	UARTCharPutNonBlocking(UART_BASE, '\n');
	uartNum[cnt] = UARTCharGetNonBlocking(UART_BASE);
	cnt ^= 1;
}
