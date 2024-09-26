#incluse grrlib.h
#incude motion.h
#include input.h
#include <wiiuse/wpad.h>
int yaw = 0
int roll=0
int pitch=0
int time

void grlib_init()//using grrlib for 2d elments 
{
Grrlib_Init()
}




void main()
{
render()
}

void rectangle()
{
GRRLIB_ObjectVeiw()
GX_BEGIN()//srarts and ends drawing 
  
GX_END()
}

void render()
{
GRRLIB_Render()
}


void time()

void conversion()
{
roll=roll-time;//makes it slowly stop over time 
pitch=pitch-time;
yaw=yaw-time;
}

//converts rool yaw and pitch to angle valuses
while(1)

WPAD_SCANPADS()//forget how to format this 
if(WPAD_ButtonsDownW $ PAD_BUTTON_HOME)
{
pause()
}

void pause()
{

}
}
