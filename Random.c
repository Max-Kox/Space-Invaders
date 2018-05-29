// Random number generator;
// Linear congruential generator 
// How to use: 
// Call Random_Init once with a seed. For example
//    Random_Init(1);
//    Random_Init(NVIC_CURRENT_R);
// Call Random over and over to get a new random number. For example
//    m = Random32()%60; // returns a random number from 0 to 59
//    p = Random();      // returns a random number 0 to 255

#include "Random.h"

unsigned long M;

void Random_Init(unsigned long seed)
{
	M = seed;
}
// Return 32-bit number (not so good random for least significant bits)
unsigned long Random32(void)
{
	M = 1664525 * M + 1013904223;
	return M;
}
// Return 8-bit number (good random for all bits)
unsigned long Random(void)
{
	M = 1664525 * M + 1013904223;
	return (M >> 24);
}
