/*
	
	main.c - Main source file.

  	Sep 2024, Ryan Murphy, (rehmurphy@gmail.com)
   	Sep 2024, guinea7pig

*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
// #include <malloc.h>

#include <grrlib.h>
#include <wiiuse/wpad.h>

#define WHITE 0xFFFF

#include "imgload.h"  //do in need to put my font png there
		      // I would do that if I were you. - Toad

int main(void) {
    	// Initialise the Graphics & Video subsystems
	GRRLIB_Init();

	WPAD_Init();
	
    	load_img(); // called from imgload.h

   	GRRLIB_texImg *tex_BMfont4 = GRRLIB_LoadTexture(/* add own texture here */);
	GRRLIB_LoadTTFFromFile(assets/BeonMedium-7Z34.ttf);


    	while(1) {

        	WPAD_ScanPads();  // Scan the Wiimotes

        // If HOME was pressed on a Wiimote, break out of the loop
        	if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) {
		 	exit(1);
		}
	    
	/* image loading is handled from "imgload.h" */
	
		GRRLIB_SetBackgroundColour(0x000000FF); 		//should be rgba
	        
		GRRLIB_PrintfTTF(5,
			0,
			BeonMedium-7Z34.ttf
			,"beon font test",
			1,
			WHITE); //difrnt order of thing from reagular print wired

 		GRRLIB_Printf(5, 
			25,
			tex_BMfont3,
			WHITE, 
			1,
		 	"wiisaber is a clone of beatsaber ");

	    	GRRLIB_Printf(5, 
			0,
			tex_BMfont3,
			WHITE, 
			1,
			"© toadrage and guinea7pig 2024"); // Might replace this with a license boilerplate.

         
		GRRLIB_Render();  // Render the frame buffer to the screen
	    
   	}

    	GRRLIB_Exit(); 	// Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
	
}
