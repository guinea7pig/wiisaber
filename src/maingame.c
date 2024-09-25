#incluse grrlib.h
#incude motion.h
#include input.h
int yaw = 0
int roll=0
int pitch=0
int time
void main()
{
GRRLIB_Camera3dSettings()
GRRLIB_3dmode()g
GRRLIB_ObjectView(480,50,10,roll,pitch,yaw,1,1,1);//i think this applys to the model drawn with gx
GX_BEGIN()

GX_END()
}

void time()

void conversion()
{
roll=roll-time;//makes it slowly stop over time 
pitch=pitch-time;
yaw=yaw-time;
}

//converts rool yaw and pitch to angle valuses
