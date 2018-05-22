/*
 * communication.h
 *
 *  Created on: May 19, 2018
 *      Author: BKIC
 */

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdint.h>
#include <driverlib/sysctl.h>
#include <driverlib/uart.h>
#include <driverlib/gpio.h>
#include <inc/hw_memmap.h>
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include <inc/tm4c123gh6pm.h>
#include "driverlib/pin_map.h"
#include "definitions.h"

extern point_t rival_point;
extern bool	rival_bomb;
extern bool semaphore_uart;
extern bool semaphore_comm;

#define	SYSCTL_PERIPH_UART		SYSCTL_PERIPH_UART3
#define	UART_BASE				UART3_BASE

#define GPIO_P_URX				GPIO_PC6_U3RX
#define GPIO_P_UTX				GPIO_PC7_U3TX

#define	SYSCTL_PERIPH_GPIO		SYSCTL_PERIPH_GPIOC
#define	GPIO_PORT_BASE			GPIO_PORTC_BASE
#define GPIO_PIN_RX				GPIO_PIN_6
#define GPIO_PIN_TX				GPIO_PIN_7

//#define	SYSCTL_PERIPH_UART		SYSCTL_PERIPH_UART0
//#define	UART_BASE				UART0_BASE
//
//#define	SYSCTL_PERIPH_GPIO		SYSCTL_PERIPH_GPIOA
//#define	GPIO_PORT_BASE			GPIO_PORTA_BASE
//#define GPIO_PIN_RX				GPIO_PIN_0
//#define GPIO_PIN_TX				GPIO_PIN_1

void Communication_Init(void);
void Communication_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* COMMUNICATION_H_ */
