//stuff for the main menu
//im in socail studies rn while writing coee sep 19 10:24:20
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <grrlib.h>
#include "imgload.h"

		    

int main(void) {

	GRRLIB_Init();
	
    	load_img(); 

  GRRLIB_texImg *tex_BMfont4 = GRRLIB_LoadTexture(/* add own texture here */);
	GRRLIB_LoadTTFFromFile(assets/BeonMedium-7Z34.ttf);
  
	  //y valus are just estimates same with x valus
		GRRLIB_SetBackgroundColour(0x000000FF);//frick the actull maib menu is a graidint 
		GRRLIB_PrintfTTF(50,160,BeonMedium-7Z34.ttf,"WII",1,ff0000);//need to change this to red
  	GRRLIB_PrintfTTF(50,155,BeonMedium-7Z34.ttf,"SABER",1,00fff);//need to change this to bluw

    //this doesent use ttf
 		GRRLIB_Printf(50,130,tex_BMfont3,WHITE, 1,"play ");

	   GRRLIB_Printf(5, 0,tex_BMfont3,WHITE,1,"© toadrage and guinea7pig 2024"); // Might replace this with a license boilerplate. //same as main.c

         
		GRRLIB_Render();  // Render the frame buffer to the screen
	    
   	}

    	GRRLIB_Exit(); 	// Be a good boy, clear the memory allocated by GRRLIB
	
}
