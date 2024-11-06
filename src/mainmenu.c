//stuff for the main menu
//im in socail studies rn while writing coee sep 19 10:24:20
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <grrlib.h>
#include <imgload.h>
#include <wiiuse/wpad.h>
int cursor_y = 130; //trying to make a varbly proababy did this horibly wrong 
int cursor_stage=0;  //starts at 0=play 1=setting 2=exit
		


int mainmenu(void) {

	//dosent like this some reson GRRLIB_INIT
	
  load_img(); 
  GRRLIB_texImg *tex_BMfont3_png = GRRLIB_LoadTexture(tex_BMfont3_png);
  GRRLIB_texImg *pointer_png = GRRLIB_LoadTexture(pointer_png);
   GRRLIB_ttfFont *BeonMedium7Z34_ttf = GRRLIB_LoadTTFFromFile(BeonMedium7Z34_ttf);
	  //y valus are just estimates same with x valus
	GRRLIB_SetBackgroundColour(0,0,0,0);//frick the actull beatsaber menu is a graidint 
	GRRLIB_PrintfTTF(50,160,BeonMedium7Z34_ttf,"WII",1,0000);//need to change this to red
  	GRRLIB_PrintfTTF(50,155,BeonMedium7Z34_ttf,"SABER",1,0000);//need to change this to bluw
	GRRLIB_DrawImg(50,cursor_y,pointer_png,180,1,1,0000);

    //this doesent use rtf
 		GRRLIB_Printf(50,130,tex_BMfont3_png,0000,1,"play ");
	 	GRRLIB_Printf(50,100,tex_BMfont3_png,0000,1,"settings ");
	        GRRLIB_Printf(50,70,tex_BMfont3_png,0000,1,"exit ");
	        print("debug");
		printf(cursor_y);
	        printf(cursor_stage);
    //setting up for ir controls
      GRRLIB_LoadTexture(pointer_png);//needs to replace with cursor

	



	   GRRLIB_Printf(5, 0,tex_BMfont3_png,0000,1,"© toadrage and guinea7pig 2024"); // Might replace this with a license boilerplate. //same as main.c

         
		GRRLIB_Render();  // Render the frame buffer to the screen
	    
   	//again dosent like this }

    	GRRLIB_Exit(); 	// Be a good boy, clear the memory allocated by GRRLIB
	
}

int controls(void) 
{
 WPAD_INIT();//this should inate wpad me think
//need to redo the input system
        While(1);
        {
	u32 ButtonsDown = WPAD_ButtonsDown(0);
	WPAD_SCANPADS();	
		if(ButtonsDown & WPAD_BUTTON_UP & cursor_stage==0)
		{
		cursor_y=130;//next menu tex x 
		cursor_stage=0;
		}
			if(ButtonsDown & WPAD_BUTTON_UP &cursor_stage==1)
			{
				cursor_y=130;//next menu tex x 
				cursor_stage=0;	
			}

 				if(ButtonsDown & WPAD_BUTTON_UP & cursor_stage==2)
				{
				cursor_y=100;//next menu tex x 
				cursor_stage=1;
	            }

					if(ButtonsDown & WPAD_BUTTON_DOWN & cursor_stage==0)
					{
						cursor_y=100;//next menu tex x
						cursor_stage=1;
					}

						if(ButtonsDown & WPAD_BUTTON_DOWN & cursor_stage==1)
						{
							cursor_y=70;//next menu tex x
							cursor_stage=2;
						}
							if(ButtonsDown & WPAD_BUTTON_DOWN & cursor_stage==1)
							{
							cursor_y=70;//next menu tex x
							cursor_stage=2;
							}
	


								if(ButtonsDown & WPAD_BUTTON_A & cursor_stage==0)
								{
								 //see what i mean about messy code
								//whaever intates the start
								}

									if(ButtonsDown & WPAD_BUTTON_A & cursor_stage==1)
									{ //see what i mean about messy code
									//settings
									}	

							if(ButtonsDown & WPAD_BUTTON_A & cursor_stage==2)
							{ //see what i mean about messy code
							//quit
							}
}
}

int music()
{
      //stuff gor musinc	
}

