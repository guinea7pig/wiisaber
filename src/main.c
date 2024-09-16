/*
	
	main.c - Main source file.

*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
// #include <malloc.h>

#include <grrlib.h>
#include <wiiuse/wpad.h>

#define WHITE 0xFFFF
#include "imgload.h"  //do in need to put my font png there

int main(void) {
    // Initialise the Graphics & Video subsystems
    GRRLIB_Init();

    WPAD_Init();
	
    load_img(); // called from imgload.h

   GRRLIB_texImg *tex_BMfont4 = GRRLIB_LoadTexture(//add own texture here);


    while(1) {

        WPAD_ScanPads();  // Scan the Wiimotes

        // If HOME was pressed on a Wiimote, break out of the loop
        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) {
		 exit(1);
	}
	    
	/* image loading is handled from "imgload.h" */
	
	GRRLIB_SetBackgroundColour(0x000000FF); 		//should be rgba 			//this might be wrong 
	
 	GRRLIB_Printf(5, 
		25,
		BMfont3.png,
		WHITE, 
		1,
		 "wiisaber is a clone of beatsaber ");

	    GRRLIB_Printf(5, 
		0,
		BMfont3.png
		WHITE, 
		1,
		 "© toadrage and guinea7pig 2024");

         
	GRRLIB_Render();  // Render the frame buffer to the screen
	    
    }

    GRRLIB_Exit(); 	// Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
	
}
