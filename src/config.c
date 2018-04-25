/** @file config.h
 *  @author Tien.P.V
 *  @date 25-Apr-2018
 *  @breif Implementation for functions that configure the system
 *
 */

///****************************************************************************
///
/// HEADER INCLUDE
///
///****************************************************************************
#include "config.h"

void System_Init(void)
{
	/* Set CPU clock at 80Mhz */
	SysCtlClockSet(SYSCTL_SYSDIV_2_5 |
				   SYSCTL_USE_PLL    |
				   SYSCTL_XTAL_16MHZ |
				   SYSCTL_OSC_MAIN	 );
}
