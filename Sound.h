// Used to play different sounds using 4-bit DAC on Port B bits 3-0

// initiate sound module, which includes DAC and Timer0 to create 11.025 kHz interrupts
void Sound_Init(void);

// functions to play different sounds
void Sound_Shoot(void);
void Sound_Killed(void);
void Sound_Explosion(void);
void Sound_Fastinvader1(void);
void Sound_Fastinvader2(void);
void Sound_Fastinvader3(void);
void Sound_Fastinvader4(void);
void Sound_Highpitch(void);
