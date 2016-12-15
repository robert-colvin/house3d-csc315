#ifndef RESHAPE
#define RESHAPE

#include "opengl.h"

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   
   glFrustum (-1.0,1.0,-1.0,1.0,1.0,50.0);
  
   glMatrixMode (GL_MODELVIEW);
}

#endif
