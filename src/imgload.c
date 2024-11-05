#include "imgload.h"

#include <stdint.h>

#include <grrlib.h>

void load_img(void) {
	
	/*
		Texture naming conventions:

		Replace spaces and periods with underscores.

		That's literally it.

	*/

	GRRLIB_texImg *BMfont3_png =GRRLIB_LoadTextureFromFile(BMfont3_png);
	GRRLIB_texImg *pointer_png = GRRLIB_LoadTextureFromFile(pointer_png); 

}
