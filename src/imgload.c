#include "imgload.h"

#include <stdint.h>

#include <grrlib.h>

void load_img(void) {
	
	/*
		Texture naming conventions:

		Replace spaces and periods with underscores.

		That's literally it.

	*/

	GRRLIB_texIMG *BMfont3_png = GRRLIB_LoadTextureFromFile(/* I still don't know whether they want a filename or a path. */);

}
