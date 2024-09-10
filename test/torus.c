#include <grrlib.h>

#include <math.h>
#include <stdint.h>

GRRLIB_init();

GRRLIB_ObjectViewBegin();
GRRLIB_ObjectView(0, 0, 0, 0, 0, 0, 1, 1, 1);
GRRLIB_DrawTorus(1, 1, 2048, 10, false, /* color */);


