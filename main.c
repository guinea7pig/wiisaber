

#include <grrlib.h>

#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <wiiuse/wpad.h>

int main(int argc, char **argv) {
    // Initialise the Graphics & Video subsystem
    GRRLIB_Init();

    WPAD_Init();

    while(1) {

        WPAD_ScanPads();  // Scan the Wiimotes

        // If [HOME] was pressed on the first Wiimote, break out of the loop
        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME)  break;
 
        GRRLIB_Printf(5, 25,--need to add own images for our fontt, GRRLIB_WHITE, 1, "wiisaber is a clone of beatsaber ");

         
        GRRLIB_Render();  // Render the frame buffer to the TV
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}
