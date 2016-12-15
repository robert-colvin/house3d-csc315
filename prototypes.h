#ifndef PROTOTYPES
#define PROTOTYPES

#include "structs.h"

extern bool filled, drawAxis, drawSign;
extern float xspin, yspin, zspin,xDeltaSpin,yDeltaSpin,zDeltaSpin, zoomy;
extern double near,far,left0,right0,fovY,aspect,bottom,top;
extern int persp;

void spinner(void);
void init(void);
void p2Ortho( double fov, double aspecty, double zNear, double zFar );
void o2Persp(double lefty, double righty, double bottomy, double topy, double neary, double fary);
void drawAxes(int, bool );
void drawTheSign(bool);
void defineBox( struct box* );
void defineBox( struct pentagon* );
void drawBox( struct box*, bool );
void drawBox( struct pentagon*, bool );
void display(void);
void reshape (int , int );

/*
void init(void) 
void drawAxes(int length)
void defineBox( box *face )
void drawBox( struct box *face )
void display(void)
void reshape (int w, int h)
*/
#endif

