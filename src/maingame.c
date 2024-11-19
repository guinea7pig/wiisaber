#include <grrlib.h> 
#include <wiiuse/wpad.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
int saberx=0;
int sabery=0;
int saberz=0;
int saberxrot=0;
int saberyrot;
int saberzrot;
bool paused = false;

void eeee()
{
    GRRLIB_Init();
    GRRLIB_Render();
}

void debug()
{   
   GRRLIB_texImg *tex_BMfont3_png = GRRLIB_LoadTexture("tex_BMfont3_png");
    GRRLIB_Printf(50,0,tex_BMfont3_png,255,255,255,0.8,1,saberx);
    GRRLIB_Printf(50,10,tex_BMfont3_png,255,255,255,0.8,1,sabery);
    GRRLIB_Printf(50,20,tex_BMfont3_png,255,255,255,0.8,saberxrot);
    GRRLIB_Printf(50,30,tex_BMfont3_png,255,255,255,0.8,saberyrot);
    GRRLIB_Printf(50,40,tex_BMfont3_png,255,255,255,0.8,saberzrot);
}


void saber()
{
    //draws saber 
    GRRLIB_ObjectView(saberx,sabery,saberz,saberxrot,saberyrot,saberzrot,2,1,1);
   GRRLIB_ObjectViewBegin();
    GRRLIB_DrawCube(1,true,00000);
    GRRLIB_ObjectViewEnd();
}

void bgstuff()
{
    GRRLIB_SetBackgroundColour(0,0,0,0);
    //this is platform that you stand on
    //praobly could clean this up with just reafulat objecct view
    GRRLIB_ObjectView(0,-2,0,0,0,0,2,2,1);
    GRRLIB_ObjectViewBegin();
    GRRLIB_DrawCube(1,true,000000);//should be black
    GRRLIB_ObjectViewEnd();

    GRRLIB_ObjectView(0,-2,0,0,0,0,2.5,2.5,1);
    GRRLIB_ObjectViewBegin(); 
    GRRLIB_DrawCube(1,true,00000 ); //should be a bit bnigges som it like right around the edges 
    GRRLIB_ObjectViewEnd();
}

void camera()
{
GRRLIB_Camera3dSettings(0,0,-1,0,0,0,0,0,0);
}


void control()
{
while(1)
{
    u32 ButtonsDown = WPAD_ButtonsDown(0);
    WPAD_ScanPads();//forget how to format this
 
    if(ButtonsDown & WPAD_BUTTON_HOME)
    {
       //NEED TO ADD PUSE FUNCTION HERE
    }
        if(ButtonsDown & WPAD_BUTTON_RIGHT)   //making sure it actlly it actlully roatess befor motion controls 
        {
            saberxrot=saberxrot+1;
        }
             if(ButtonsDown & WPAD_BUTTON_LEFT)
            {
                saberxrot=saberxrot-1;
            }
                 if(ButtonsDown & WPAD_BUTTON_UP)
                {
                saberyrot=saberyrot+1;
                }

            if(ButtonsDown & WPAD_BUTTON_DOWN)
            {
             saberyrot=saberyrot-1;
            }
    if(ButtonsDown & WPAD_BUTTON_HOME && paused == true);
        {
           GRRLIB_Exit();
           exit(0);
        } 
}
void pause()
  {
    paused = true; //need to ad something where it freezes game 
  }   
 void combo_ui()
{
// i completly dont know what im going
 //this is in a 3d space
 //make this later 

 //put combo texure me thinks we can use the texture for that
 //wait i should praobaly ise a img qaud actully idk
 //need to laod textures
 }
 }

