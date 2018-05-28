// This module is used to operate with GPIOs - LEDs (PB4 and PB5) and buttons (PE0 and PE1)
// fire button connected to PE0
// special weapon fire button connected to PE1
// both buttons are positive (connected to +3.3 when pushed) logic and used without external pull-up resistors

#include "tm4c123gh6pm.h"
#include "LED_and_Buttons.h"

void LEDs_Init(void)									// PB4, PB5 - output for LED
{
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= 0x00000002;				// 1) B clock
	delay = SYSCTL_RCGC2_R;							// delay to allow clock to stabilize     
	GPIO_PORTB_AMSEL_R &= ~0x30;				// 2) disable analog function
	GPIO_PORTB_PCTL_R &= ~0x00FF0000;		// 3) GPIO clear bit PCTL  
	GPIO_PORTB_DIR_R |= 0x30;						// 4) output  LED
	GPIO_PORTB_AFSEL_R &= ~0x30;				// 5) no alternate function  
	GPIO_PORTB_DEN_R |= 0x30;						// 7) enable digital pins
}

void Buttons_Init(void)								// PE0, PE1 - inputs for buttons
{
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= 0x00000010;				// 1) E clock
	delay = SYSCTL_RCGC2_R;							// delay to allow clock to stabilize     
	GPIO_PORTE_AMSEL_R &= ~0x03;				// 2) disable analog function
	GPIO_PORTE_PCTL_R &= ~0x000000FF;		// 3) GPIO clear bit PCTL  
	GPIO_PORTE_DIR_R &= ~0x03;					// 4) input
	GPIO_PORTE_PDR_R |= 0x03;						// Pull-down resistors
	GPIO_PORTE_AFSEL_R &= ~0x03;				// 5) no alternate function  
	GPIO_PORTE_DEN_R |= 0x03;						// 7) enable digital pins
}

// This Initialization function init buttons (PE0 - fire, PE1 - special fire) and LEDs (PB4, PB5)
void LED_and_Buttons_Init(void)
{
	LEDs_Init();
	Buttons_Init();
}

// input: 0 to turn LED (PB4) off, any other value to turn it off
void LED_1_Out(unsigned long out)
{
	if(out == 0) GPIO_PORTB_DATA_R &= ~0x10;	// turn LED off
	else GPIO_PORTB_DATA_R |= 0x10;						// turn LED on
}

// input: 0 to turn LED (PB5) off, any other value to turn it off
void LED_2_Out(unsigned long out)
{
	if(out == 0) GPIO_PORTB_DATA_R &= ~0x20;	// turn LED off
	else GPIO_PORTB_DATA_R |= 0x20;						// turn LED on
}

// button for ordinary fire attack
// output: 1, when button (PE0) is pushed, 0 when is released
unsigned long Fire_Button_In(void)
{
	return (GPIO_PORTE_DATA_R & 0x01);
}

// button for special fire attack
// output: 1, when button (PE1) is pushed, 0 when is released
unsigned long SpFire_Button_In(void)
{
	return (GPIO_PORTE_DATA_R & 0x02) >> 1;
}

