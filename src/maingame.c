#include grrlib.h
#include motion.h
#include input.h
#include <wiiuse/wpad.h>
int time=0
int saberx=0
int sabery=0
int saberz=0
int saberxrot=0
int sbaeryrot
int saberzrotghx
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
    GRRLIB_ObjectVeiw(saberx,sabery,sarberz,saberxrot,saberyrot,saberzrot,2,1,1)
   GRRLIB_ObjectViewBegin()
    GRRLIB_DrawCube(1,true,FF2D00);
    GRRLIB_ObjectViewEnd()
}

void bgstuff()
{
    GRRLIB_SetBackroundColour(0,0,0)
    //this is platform that you stand on
    //praobly could clean this up with just reafulat objecct view
    GRRLIB_ObjectVeiw(0,-2,0,0,0,0,2,2,1)
    GRRLIB_ObjectViewBegin()
    GRRLIB_DrawCube(1,true,0000ff);//should be black
    GRRLIB_ObjectViewEnd()

    GRRLIB_ObjectView(0.-2,0,0,0,0,2.5,2.5,1);
    GRRLIB_ObjectViewBegin() 
    GRRLIB_Draw_cube(1,true.ff2d00 ); //should be a bit bnigges som it like right around the edges 
    GRRLIB_ObjectViewEnd()
}

void camera()
{
GRRLIB_Camera3dSettings(0,0,-1,0,0,0,0,0,0)
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
                 if(Buttonsi eDown & WPAD_BUTTON_UP)
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
  }   void 
 void combo_ui()
// i completly dont know what im going
 GRRLIB_teximg()//
 //this is in a 3d space
 //make this invible and put texture on ut
 GRRLIB_ObjectView()
 GRRLIB_ObjectViewBegin()
 //neeed to load texture
 GRRLIB_DrawImgQuad(combo.png)//neeed to make this trasparent
 GRRLIB_Object_VeiwEnd()

 //put combo texure me thinks we can use the texture for that
 //wait i should praobaly ise a img qaud actully idk
 //need to laod textures
 }
}

