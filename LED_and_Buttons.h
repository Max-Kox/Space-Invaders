// This module is used to operate with GPIOs - LEDs (PB4 and PB5) and buttons (PE0 and PE1)
// fire button connected to PE0
// special weapon fire button connected to PE1
// both buttons are positive (connected to +3.3 when pushed) logic and used without external pull-up resistors

// This Initialization function init buttons (PE0 - fire, PE1 - special fire) and LEDs (PB4, PB5)
void LED_and_Buttons_Init(void);

// input: 0 to turn LED (PB4) off, any other value to turn it off
void LED_1_Out(unsigned long out);

// input: 0 to turn LED (PB5) off, any other value to turn it off
void LED_2_Out(unsigned long out);

// button for ordinary fire attack
// output: 1, when button (PE0) is pushed, 0 when is released
unsigned long Fire_Button_In(void);

// button for special fire attack
// output: 1, when button (PE1) is pushed, 0 when is released
unsigned long SpFire_Button_In(void);
