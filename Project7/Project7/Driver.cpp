/*
	CECS 449 Project 7

	Authors: Bret Erickson, 

	Description:

*/

#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/Glut.h>
#include <stdlib.h>
#include "SolarSystem.h"

int cameraRotateWindow, solarSystemWindow; //Identifiers for the separate windows

//Independent clip window/screen variables
int ssWidth = 500;		//screen dimensions
int ssHeight= 500;
SolarSystem *solarSys;	//Reference to the solar system object we will be rendering

//Pre:
//Post:
void solarSys_KeyboardInput(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'r': //Toggle animation
		solarSys->toggleAnimation();
		break;
	case 's': //single-step animation
		solarSys->singleStep();
		break;
	case 27:
		exit(0);
		break;
	}//end switch
}//end solarSys_KeyboardInput

//Pre:
//Post:
void solarSys_SpecialKeyboardInput(int key, int x, int y)
{
	switch(key)
	{
	case GLUT_KEY_UP:	//up key
		solarSys->increaseStep();
		break;
	case GLUT_KEY_DOWN://down key
		solarSys->decreaseStep();
		break;
	}//end switch
}//end solarSys_SpecialKeyboardInput

//Pre: None
//Post: Clears background to black and renders the current state of the solar system 3d model
void solarSys_Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);

	//Draw x,y,z axis for debug purposes
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex3f(-500,0,0);
		glVertex3f(500,0,0);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0,500,0);
		glVertex3f(0,-500,0);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0,0,500);
		glVertex3f(0,0,-500);
	glEnd();

	//render solar system scene
	solarSys->render();

	glutSwapBuffers();
}//end solarSys_Display

//Pre:
//Post:
void solarSys_Reshape(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(0.0,0.0, -250.0);
	gluLookAt(250,100,250, 0,0,0, 0,1,0);

	glutPostRedisplay();
}//end solarSys_Reshape

//Pre:none
//Post:
void update()
{
	solarSys->update();


	glutPostRedisplay();
}


//Pre:None
//Post:Initializes two windows, one for displaying the 3d solar system, the other for the camera rotation simulation
//along with their required callbacks
void initialize()
{
	//Setup solar system window
	solarSys = new SolarSystem();

	glutInitWindowSize(ssWidth,ssHeight);
	solarSystemWindow = glutCreateWindow("Solar System");
	//Callbacks specifically for solar system window
	glutReshapeFunc(solarSys_Reshape);
	glutDisplayFunc(solarSys_Display);
	glutKeyboardFunc(solarSys_KeyboardInput);
	glutSpecialFunc(solarSys_SpecialKeyboardInput);//Extra keyboard callback needed for up/down keys
	glShadeModel(GL_FLAT);


	//Setup camera rotate example window here


	//Shared update callback
	glutIdleFunc(update);

}//end initializeWindows


void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	initialize(); //setup windows & initialize data

	glutMainLoop();
}//end main