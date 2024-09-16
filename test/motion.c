//for the motion controls
#include <wiiuse/wpad.h>
#include <wiiuse/wiiuse.h>

#include <stdint.h>
#include <stdio.h>

void motion(u32 channel)
{
	WPADData *data = WPAD_Data(channel);
	orient_t orientation = data->orient;
	return orient;
}
