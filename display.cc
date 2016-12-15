
#ifndef DISPLAY
#define DISPLAY

using namespace std;

#include "opengl.h"
#include "structs.h"
#include "prototypes.h"
#include <cmath>
#include <iostream>

double left0=-1.0;double right0=1.0;double bottom=-1.0;double top=1.0;double near=1.0;double far=50.0;double aspect = 0.0; double fovY = 0.0;

void p2Ortho( double fov, double aspecty, double zNear, double zFar )
{//
	near = zNear;
	far = zFar;
	
    const GLdouble pi = 3.1415926535897932384626433832795;
    GLdouble fW, fH;

    //fH = tan( (fovY / 2) / 180 * pi ) * zNear;
    fH = tan( fov / 360 * pi ) * zNear;
    fW = fH * aspecty;

	right0 = fW;
	left0 = -fW;
	top = fH;
	bottom = -fH;

    glOrtho( left0, right0, bottom, top, near, far );
}
void o2Persp(double lefty, double righty, double bottomy, double topy, double neary, double fary)
{
	const GLdouble pi = 3.1415926535897932384626433832795;
	//GLdouble fovY, aspect;
	
	aspect = right0/top;
	fovY = atan(top/near)/pi*360;
	
	gluPerspective(fovY,aspect,neary,fary);
}
void display(void)
{

   struct /*box*/pentagon faces[7];
   
   float *M;
   int i, j;
   

   defineBox(&faces[0]);

   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);

/* ONLY MODIFY CODE BELOW */

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity ();             /* clear the matrix */

   // Let's manually move the camera back
   
   glTranslatef(0.0, 0.0, -10.0);
   //glScalef(2.0,1.0,1.0);

   // Now explicitly place the camera
   /*if (persp==1)
   	o2Persp(left0,right0,bottom,top,near,far);
   if (persp==2)
   	p2Ortho(fovY,aspect,near,far);*/
   //glOrtho   (-10.0, 10.0, -10.0, 10.0, 1.0, 20.0);
  
   gluLookAt (5.7+zoomy, 5.7+zoomy, 5.7+zoomy, -10.0, -10.0, -10.0, 0.0, 0.0, 1.0);


/* DO NOT MODIFY ANYTHING ELSE */

   /* Draw a coordinate axis */

   glEnable(GL_DEPTH_TEST);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   drawAxes(5, drawAxis);
	glPushMatrix();
	glTranslatef(1.0,1.0,0.0);
	glRotatef(zspin,0.0,0.0,1.0);
	glRotatef(xspin,1.0,0.0,0.0);
	glRotatef(yspin,0.0,1.0,0.0);
	glTranslatef(-1.0,-1.0,0.0);
   drawBox(&faces[0],filled);
	glPushMatrix();
	glScalef(0.0025,0.0025,0.0025);
	//glRotatef(180.0,1.0,0.0,0.0);
	glRotatef(180.0,0.0,1.0,0.0);
	glTranslatef(-350.0,1220.0,-200.0);
	glRotatef(270.0,1.0,0.0,0.0);
//	drawBox(&faces[0],filled);   
	drawTheSign(drawSign);
	glPopMatrix();
//drawTheSign(drawSign);
	glPopMatrix();


   glutSwapBuffers();

}

#endif
