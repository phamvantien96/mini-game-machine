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

///****************************************************************************
///
/// PROTOTYPE PRIVATE FUNCTION
///
///****************************************************************************
//static void SysTick_Handler(void);

///****************************************************************************
///
/// FUNCTION IMPLEMENTATION
///
///****************************************************************************


void static inline GPIO_Init(void)
{
	/* Active PortE clock and wait for it is ready */
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE));

	/* Config output with 2mA drive and standard pin type */
	GPIOPadConfigSet(GPIO_PORTE_BASE,
					 PORTE_PIN_USE,
					 GPIO_STRENGTH_2MA,
					 GPIO_PIN_TYPE_STD);
	GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, PORTE_PIN_USE);

	/* Active PortB clock and wait for it is ready */
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB));

	/* Config output with 2mA drive and standard pin type */
	GPIOPadConfigSet(GPIO_PORTB_BASE,
					 PORTB_PIN_USE,
					 GPIO_STRENGTH_2MA,
					 GPIO_PIN_TYPE_STD);
	GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, PORTB_PIN_USE);
}





void System_Init(void)
{
    ///
	///  System Clock Init
	///
	/* Set CPU clock at 80Mhz */
	SysCtlClockSet(SYSCTL_SYSDIV_2_5 |
				   SYSCTL_USE_PLL    |
				   SYSCTL_XTAL_16MHZ |
				   SYSCTL_OSC_MAIN	 );
	///
	///  SysTick Init
	///
	/* Set 0.1 second period interrupt */
	SysTickPeriodSet(8E6-1);
//	SysTickIntRegister(SysTick_Handler);
//	SysTickIntEnable();
	SysTickEnable();

	///
	///  GPIO Init
	///
	/* Active PortF clock and wait for it is ready */
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

	/* Config output with 2mA drive and standard pin type */
	GPIOPadConfigSet(GPIO_PORTF_BASE,
					 GPIO_PIN_1,
					 GPIO_STRENGTH_2MA,
					 GPIO_PIN_TYPE_STD);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);

	/* Unlock and set pull-up for input PF0 */
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTF_CR_R |= 0xFF;


	HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;
	HWREG(GPIO_PORTF_BASE+GPIO_O_CR) |= GPIO_PIN_0;

	GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0);
	GPIOPadConfigSet(GPIO_PORTF_BASE,
					 GPIO_PIN_0,
					 GPIO_STRENGTH_2MA,
					 GPIO_PIN_TYPE_STD_WPU);
	GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_RISING_EDGE);
	GPIOIntRegister(GPIO_PORTF_BASE, Switch_Handler);
	GPIOIntEnable(GPIO_PORTF_BASE, GPIO_INT_PIN_0);

	///
	///  UART Init
	///
	/* Active UART0 clock and wait for it is ready */
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	while (!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0));

	/* Active PA0, PA1 and choose function UART0 */
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));
	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

	/* Config UART at 115200 baudrate 8-N-1 frame format*/
	UARTConfigSetExpClk(UART0_BASE,
						SysCtlClockGet(), 115200,
						(UART_CONFIG_WLEN_8   |
						 UART_CONFIG_STOP_ONE |
						 UART_CONFIG_PAR_NONE ));

	GPIO_Init();
}

void SysTick_Handler(void)
{
//	ADCProcessorTrigger(ADC0_BASE, 2);
}

uint8_t led = 0;

void Switch_Handler(void)
{
	led ^= 0x02;
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, led);
	GPIOIntClear(GPIO_PORTF_BASE, GPIO_INT_PIN_0);
}
