/** @file config.h
 *  @author Tien.P.V
 *  @date 25-Apr-2018
 *  @breif Prototype for functions that configure the system
 */

#ifndef SRC_CONFIG_H_
#define SRC_CONFIG_H_


///****************************************************************************
///
/// HEADER INCLUDE
///
///****************************************************************************
#include <stdbool.h>
#include <stdint.h>
#include <driverlib/sysctl.h>
#include <driverlib/systick.h>
#include <driverlib/gpio.h>
#include <driverlib/uart.h>
#include <inc/hw_memmap.h>
#include <inc/tm4c123gh6pm.h>

///****************************************************************************
///
/// PROTOTYPE
///
///****************************************************************************
/** @brief System_Init
 *
 *  This one call function is used to initialize the system. It include
 *  initialize system clock, gpio, uart ...
 *
 *  @param void
 *  @return void
 */
void System_Init(void);


#endif /* SRC_CONFIG_H_ */
