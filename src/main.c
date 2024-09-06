#include <grrlib.h>

#include <stdlib.h>
#include <math.h>
#include <malloc.h>

#include <wiiuse/wpad.h>

int main(void) {
    // Initialise the Graphics & Video subsystem
    GRRLIB_Init();

    WPAD_Init();

    while(1) {

        WPAD_ScanPads();  // Scan the Wiimotes

        // If [HOME] was pressed on a Wiimote, break out of the loop
        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) {
		 break;
	}

	GRRLIB_texImg* GRRLIB_LoadTextureFromFile();	

 	GRRLIB_Printf(5, 
		25,
		// --need to add own images for our font!
		GRRLIB_WHITE, 
		1,
		 "wiisaber is a clone of beatsaber ");

         
	GRRLIB_Render();  // Render the frame buffer to the screen
    }

    GRRLIB_Exit(); 	// Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}
