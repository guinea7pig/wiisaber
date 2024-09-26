#incluse grrlib.h
#incude motion.h
#include input.h
int yaw = 0
int roll=0
int pitch=0
int time
void gxinit()
{
GX_INIT();
GX_SetViewport(0, 0, 680, 480);
GX_SetScissor(0,0,680,480)
GXSetProjection(mtx, GX_PERSPECTIVE)\
GXSetCullMode()
}

int main()
{
gxinit()
render()
}
void render()
{
GX_Clearvtx()//me thiks
GX_flush()//this should send stuff to the gpu
}


void time()

void conversion()
{
roll=roll-time;//makes it slowly stop over time 
pitch=pitch-time;
yaw=yaw-time;
}

//converts rool yaw and pitch to angle valuses
