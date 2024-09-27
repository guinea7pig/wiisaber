#incluse grrlib.h
#incude motion.h
#include input.h
#include <wiiuse/wpad.h>
int time=0
int saber x=0
int saber y=0
int saber xrot=0
int sbaer yrot
int saber zrot
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
GRRLIB_DrawCube(1,true,0000ff);
GRRLIB_ObjectViewScale(2,1,1)
GRRLIB_ObjectVeiwTrans(saberx,sabery,saberz)//has something to do with tranlating it to screen
GRRLIB_OBJECTVeiwRotate(saberxrot,saberyrot,saberzrot)//wimote values are in yaw picth and roll witch is annoying
   
}

void render()
{
GRRLIB_Render()


while(1)
{
u32 buttonsDown = WPAD_ButtonsDown();
WPAD_SCANPADS()//forget how to format this
 
if(ButtonsDown & WPAD_BUTTON_HOME)
{
pause()
}
if(ButtonsDown & WPAD_BUTTON_RIGHT)   //making sure it actlly it actlully roatess befor motion controls 
{
saberxrot=saberxrot+1
}
if(ButtosDown & WPAD_BUTTON_LEFT)
{
saberxtot=saberxrot-1
}
}
void pause()
{

}
}
