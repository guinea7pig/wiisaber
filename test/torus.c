#include <grrlib.h>

#include <math.h>
#include <stdint.h>

#include <wiiuse/wpad.h>

void rotate(u32 channel) {
	WPADData data = WPAD_Data(channel);
	
