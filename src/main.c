*
	
	main.c - Main source file.

  	Sep 2024, Ryan Murphy, (rehmurphy@gmail.com)
   	Sep 2024, guinea7pig

*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <malloc.h>
#include <BMfont3_png.h>
#inlude <combo_png.h> 
#include <grrlib.h>
#include <wiiuse/wpad.h>

#define WHITE 0xFFFFFFFF  //do in need to put my font png there
		      // I would do that if I were you. - Toad

int main(void) {
    	// Initialise the Graphics & Video subsystems
	GRRLIB_Init();

	WPAD_Init();
	

    GRRLIB_texImg *BMfont_png = GRRLIB_LoadTexture("BMfont_png");
    GRRLIB_ttfFont *beonttf  = GRRLIB_LoadTTFFromFile("beonttf");

 

    	while(1) {

        	WPAD_ScanPads();  // Scan the Wiimotes
        // If HOME was pressed on a Wiimote, break out of the loop
        	if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) {
		 	exit(1);
                        GRRLIB_Exit()
		}
              }
	    
	/* image loading is handled from "imgload.h" */
	
		GRRLIB_SetBackgroundColour(0,0,0,0); 		//should be rgba
	        
		GRRLIB_PrintfTTF(5,0,beonttf,"beon font test",1,WHITE); //difrnt order of thing from reagular print wired

 		GRRLIB_Printf(5,25,BMfont_png,WHITE,1,"wiisaber is a clone of beatsaber ");

	    	GRRLIB_Printf(5,0,BMfont_png,WHITE,1,"© toadrage and guinea7pig 2024"); // Might replace this with a license boilerplate.

         
		GRRLIB_Render();  // Render the frame buffer to the screen
	    
   	}

    
