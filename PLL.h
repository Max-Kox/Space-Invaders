// initializes the Phase-locked loop to the desired frequency.
// bus frequency is 400MHz/(SYSDIV2+1) = 400MHz/(4+1) = 80 MHz


// ************PLL_Init*****************
// sets PLL to 80 MHz
// This needs to be called once 
// Inputs: none
// Outputs: none
void PLL_Init(void);
