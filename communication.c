/*
 * communication.c
 *
 *  Created on: May 19, 2018
 *      Author: BKIC
 */

#include "communication.h"

extern char uart_ch;

void Communication_Init(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART);
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART))	{ }
	UARTConfigSetExpClk(UART_BASE,	SysCtlClockGet(), 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIO);
	while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIO));
	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_RX | GPIO_PIN_TX);

	UARTFIFOLevelSet(UART_BASE,	UART_FIFO_TX2_8, UART_FIFO_RX2_8);
//	UARTFIFOEnable(UART_BASE);
	UARTIntRegister(UART_BASE, Communication_Handler);
	UARTIntEnable(UART_BASE, UART_INT_RX);
}


extern uint8_t led2;

void Communication_Handler(void)
{
	UARTIntClear(UART_BASE, UART_INT_RX);
//	led2 ^= 0x02;
//	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, led2);
	uart_ch = UARTCharGet(UART_BASE);
}
