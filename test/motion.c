
//for the motion controls
#include <wiiuse/wpad.h>
#include <wiiuse/wiiuse.h>
//what wiiiuse thing would be motion controls

#include <stdint.h>
#include <stdio.h>
// how would we put thes values in a header file

orient_t* motion(u32 channel)
{
	WPADData *data = WPAD_Data(channel);
	orient_t orient = data->orient;
	return &orient;
}

void convert()//for conversion into stuff we can use with
{

}
void testmotion(u32 channel)
{
	orient_t* orient = motion(channel);
	//make it print the yaw,rool and pitch vales to test
	//hopefully grrlib supports yaw,rool and pitch for 3d objects
        printf(orient->roll);
	printf(orient->yaw);
	printf(orient->pitch);			//me thinks this is how it works
}
