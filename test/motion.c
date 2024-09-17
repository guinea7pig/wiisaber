//for the motion controls
#include <wiiuse/wpad.h>
#include <wiiuse/wiiuse.h>
//what wiiiuse thing would be motion controls

#include <stdint.h>
#include <stdio.h>
// how would we put thes values in a header file
void motion(u32 channel)
{
	WPADData *data = WPAD_Data(channel);
	orient_t orientation = data->orient;
	return orient;
}
void testmotion()
{
//make it print the yaw,rool and pitch vales to test
//hopefully grrlib supports yaw,rool and pitch for 3d objects
printf(orient)//me thinks this is how it works
}
