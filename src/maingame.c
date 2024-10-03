#include grrlib.h
#include motion.h
#include input.h
#include <wiiuse/wpad.h>
int time=0
int saberx=0
int sabery=0
int saberxrot=0
int sbaeryrot
int saberzrot
bool paused = false

void grlib_init()//using grrlib for 2d elments 
{
    Grrlib_Init()
}

void debug()
{   
    GRRLIB_Printf(50,0,tex_BMfont3,fffff,1,saberx)//need to include image this applys to all
    GRRLIB_Printf(50,10,tex_BMfont3,ffff,1,sabery)
    GRRLIB_Printf(50,20,tex_BMfont3,ffff,saberxrot)
    GRRLIB_Printf(50,30,tex_BMfont3,ffff,saberyrot)
    GRRLIB_Printf(50,40,tex_BMfont3,ffff,saberzrot)
}


void main()
{
    render()
}

void saber()
{
    //draws saber 
    GRRLIB_DrawCube(1,true,FF2D00);
    GRRLIB_ObjectViewScale(2,1,1)
    GRRLIB_ObjectVeiwTrans(saberx,sabery,saberz)//has something to do with tranlating it to screen
    GRRLIB_OBJECTVeiwRotate(saberxrot,saberyrot,saberzrot)//wimote values are in yaw picth and roll witch is annoying
}

void bgstuff()
{
    //this is platform that you stand on
    GRRLIB_DrawCube(1,true,0000ff);//should be black
    GRRlIB_ObjectVeiwScale(2,2,1)//again i dont know what this ia minuplating
    GRRLLIB_ObjectviewTrans()//should be  under the camera
    GRRLIB_Draw_cube(1,true.ff2d00 ); //should be a bit bnigges som it like right around the edges 
    GGRLIB_ObjectVeiwScale(2.5,2.5,1)//again i dont know witch onject its doing this too
    GRRLIB_ObjectViewaTrans()//also should be under camera
}

void camera()
{
    //for the positiom of the camera    
}


void render()
{
    GRRLIB_Render()
}

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
                 if(ButtonsDown & WPAD_BUTTON_UP)
                {
                saberyrot=saberyrot+1
                }

            if(ButtonsDown & WPAD_BUTTON_DOWN)
            {
             saberyrot=saberyroty-1
            }
void pause()
  {
    puased= true //need to ad something where it freezes game 
        if(ButtonsDown & WPAD_BUTTON_HOME && pause=true)
        {
           GRLIB_EXIT()
           exit(0)
        } 
  }   
}

