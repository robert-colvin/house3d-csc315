#ifndef MAIN
#define MAIN

using namespace std;

#include "opengl.h"
#include "structs.h"
#include "prototypes.h"
#include "globals.h"
#include "constants.h"
#include <iostream>

bool filled = false;
bool drawAxis = false;
bool drawSign = false;
float zoomy = 0.0;
int persp = 1;



void keyboard(unsigned char key, int x, int y)
{
	if (key == 'q' || key == 'Q') exit(0);
	if (key == 'r')
	{
		yspin = 0.0; yDeltaSpin = 0.0;
		xspin = 0.0; xDeltaSpin = 0.0;
		zspin = 0.0; zDeltaSpin = 0.0;

	}
	if (key == 's' || key == 'S')
	{
		yDeltaSpin = 0.0;
		xDeltaSpin = 0.0;
		zDeltaSpin = 0.0;
	}
	if (key == 'R')
	{
		filled = false;
		drawAxis = false;
		drawSign = false;
		zoomy = 0.0;
		yspin = 0.0; yDeltaSpin = 0.0;
		xspin = 0.0; xDeltaSpin = 0.0;
		zspin = 0.0; zDeltaSpin = 0.0;

	}
	if (key == 'x' || key == 'X') 
	{	
		xDeltaSpin+=0.5; 
		glutIdleFunc(spinner);
	}
	if (key == 'y' || key == 'Y') 
	{	
		yDeltaSpin+=0.5; 
		glutIdleFunc(spinner);
	}
	if (key == 'z' || key == 'Z') 
	{	
		zDeltaSpin+=0.5; 
		glutIdleFunc(spinner);
	}
	if (key == 'f' || key == 'F') filled = !filled;

	glutPostRedisplay();
}
void special(int key, int x, int y)
{
	if (key == GLUT_KEY_PAGE_UP)
		zoomy = zoomy - 0.05;
	if (key == GLUT_KEY_PAGE_DOWN)
		zoomy = zoomy + 0.05;

	glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
	switch(button)
	{
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN)
			{

				if(y > (WINDOW_HEIGHT/WINDOW_WIDTH)*x && y > -(WINDOW_HEIGHT/WINDOW_WIDTH)*x + WINDOW_HEIGHT)
					zDeltaSpin = zDeltaSpin + 0.5;
				else 
				{
					if (x>WINDOW_WIDTH/2)
						xDeltaSpin = xDeltaSpin + 0.5;
					if (x<WINDOW_WIDTH/2)
						yDeltaSpin = yDeltaSpin + 0.5;
				}
				glutIdleFunc(spinner);
			}
			break;
		case GLUT_RIGHT_BUTTON:
			if (state == GLUT_DOWN)
			{
				if(y > (WINDOW_HEIGHT/WINDOW_WIDTH)*x && y > -(WINDOW_HEIGHT/WINDOW_WIDTH)*x + WINDOW_HEIGHT)
					zDeltaSpin = zDeltaSpin - 0.5;
				else 
				{
					if (x>WINDOW_WIDTH/2)
						xDeltaSpin = xDeltaSpin - 0.5;
					if (x<WINDOW_WIDTH/2)
						yDeltaSpin = yDeltaSpin - 0.5;
				}
				glutIdleFunc(spinner);
			}
			break;
		default:
			break;
	}
}
void axisRnah(int msg)
{
	switch(msg) 
	{
		case 1:
			drawAxis = true;
			break;
		case 2:
			drawAxis = false;
			break;
	}
	glutPostRedisplay();
}
void signRnah(int msg)
{
	switch(msg)
	{
		case 1:
			drawSign = true;
			break;
		case 2:
			drawSign = false;
			break;
	}
	glutPostRedisplay();
}
void fillRnah(int msg)
{
	switch(msg)
	{
		case 1:
			filled = true;
			break;
		case 2:
			filled = false;
			break;
	}
	glutPostRedisplay();
}

void viewRnah(int msg)
{
	switch(msg)
	{
		case 1:
			persp = 1;
			cout<<"Imagine the view is in perspective now\n";
			break;
		case 2:
			persp = 2;
			cout<<"Imagine the view is in orthographic now\n";
			break;
		case 3:
			persp = 3;
			cout<<"Dream up some crazy custom view and think we're in that right now\n";
			break;
			
	}
	glutPostRedisplay();
}
void exitRnah(int msg)
{
	switch(msg)
	{
		case 1:
			exit(0);
			break;
	}
}
void resetRnah(int msg)
{
	switch(msg)
	{
		case 1:
			filled = false;
			drawAxis = false;
			drawSign = false;
			zoomy = 0.0;
			yspin = 0.0; yDeltaSpin = 0.0;
			xspin = 0.0; xDeltaSpin = 0.0;
			zspin = 0.0; zDeltaSpin = 0.0;
			
			break;
		case 2:
			cout << "Then why are you even here?\n\n";
	}
	glutPostRedisplay();
}

void infectHostWithHorribleVirus(int msg){};
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (WINDOW_HEIGHT, WINDOW_WIDTH); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutMouseFunc(mouse);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(special);
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);

   int axis = glutCreateMenu(axisRnah);
   glutAddMenuEntry("Turn those bastards on!", 1);
   glutAddMenuEntry("Turn those bastards off!", 2);

   int sign = glutCreateMenu(signRnah);
   glutAddMenuEntry("Put the sign up bro!", 1);
   glutAddMenuEntry("Take the sign down bro!", 2);

   int fill = glutCreateMenu(fillRnah);
   glutAddMenuEntry("Lemme see it filled!", 1);
   glutAddMenuEntry("Lemme see the frame!", 2);

   int view = glutCreateMenu(viewRnah);
   glutAddMenuEntry("I want perspective so bad....", 1);
   glutAddMenuEntry("Bless me with orthographic...", 2);
   glutAddMenuEntry("I'd kill to customize it.....", 3);

   int exit = glutCreateMenu(exitRnah);
   glutAddMenuEntry("Kill this program! I've had enough!!", 1);
   glutAddMenuEntry("I could hang around for a bit longer", 2);

   int reset = glutCreateMenu(resetRnah);
   glutAddMenuEntry("Travel to the past", 1);
   glutAddMenuEntry("Stay in the present",2);

   int menu = glutCreateMenu(infectHostWithHorribleVirus);
   glutAddSubMenu("Reset",reset);
   glutAddSubMenu("Axes", axis);
   glutAddSubMenu("Sign", sign);
   glutAddSubMenu("Fill", fill);
   glutAddSubMenu("View", view);
   glutAddSubMenu("Exit", exit);

   glutAttachMenu(GLUT_MIDDLE_BUTTON);

   glutMainLoop();
   return 0;
}

#endif
