/*
	CECS 449 Project 7

	Authors: Bret Erickson, James Pardue

	Academic team project

	Part 1 - Bret Erickson

	Render a 3D wirefram model of a 'solar system' including a sun and four planets.

	One planet also features a moon
	Controls:

	Press "r" key to toggle (off and on) running the animation
	Press "s" key to single-step animation
	The up arrow key and down array key control the time step used in the animation rate. 
	Each key press multiplies or divides the times by a factor of two (2).
	Press ESCAPE to exit.
	Part 2 - James Pardue

	Rotate camera around a fixed 3D cube

	Controls:

	x(decrease), X (increase), y, Y, z, and Z keys on the keyboard. 
	Camera always points at the center of the object. 
	The object is rotated about the x-, y- or z- axis based on the user input.

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
float xAngle, yAngle, zAngle;//Camera rotation for solar system

//Camera Rotate variables
double rotate_y=0; 
double rotate_x=0;
double rotate_z=0;

float Ex = -1;
float Ey = -1; 
float Ez = -1;

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
	case '1':
		xAngle += 5;
		glutPostRedisplay();
		break;
	case '2': //Rotate camera angle around y-axis
		yAngle += 5;
		glutPostRedisplay();
		break;
	case '3':
		zAngle += 5;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	}//end switch
}//end solarSys_KeyboardInput

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
	glPushMatrix();
	glRotatef(yAngle, 0,1,0);
	glRotatef(xAngle, 1,0,0);
	glRotatef(zAngle, 0,0,1);
	
	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);

	//Draw x,y,z axis for debug purposes
	glColor3f(0,1,0);
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

	glPopMatrix();
}//end solarSys_Display

void solarSys_Reshape(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(0.0,0.0, -250.0);
	gluLookAt(50,100,500, 0,0,0, 0,1,0);

	glutPostRedisplay();
}//end solarSys_Reshape

void update()
{
	solarSys->update();

	glutSetWindow(solarSystemWindow);
	glutPostRedisplay();
}

//////////////////////////////////////////////////////////////////
//Code for Part 2
/////////////////////////////////////////////////////////////////
void display()
{
  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
  // Reset transformations
  glLoadIdentity();

  //gluLookAt (Ex, Ey, Ez, cx, cy, cz, Up_x, Up_y, Up_z) 
  gluLookAt (Ex, Ey, Ez, 0, 0, 0, 0, 1, 0);


  // Rotate camera
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  glRotatef( rotate_z, 0.0, 0.0, 1.0 );

  //White side - FRONT
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );     
  glVertex3f(  0.5, -0.5, -0.5 );
  glVertex3f(  0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
 
  // Grey side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   0.2,  0.2, 0.2 );
  glVertex3f(  0.5, -0.5, 0.5 );
  glVertex3f(  0.5,  0.5, 0.5 );
  glVertex3f( -0.5,  0.5, 0.5 );
  glVertex3f( -0.5, -0.5, 0.5 );
  glEnd();
 
  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  1.0,  1.0,  0.0 );
  glVertex3f( 0.5, -0.5, -0.5 );
  glVertex3f( 0.5,  0.5, -0.5 );
  glVertex3f( 0.5,  0.5,  0.5 );
  glVertex3f( 0.5, -0.5,  0.5 );
  glEnd();
 
  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  1.0,  0.0 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
 
  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f(  0.5,  0.5,  0.5 );
  glVertex3f(  0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glEnd();
 
  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f(  0.5, -0.5, -0.5 );
  glVertex3f(  0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
 
  //printf(".");

  glFlush();
  glutSwapBuffers();
 
}

void keyPressed (unsigned char key, int x, int y)
{  

	if(key == 'x')
	  Ex -= .2;
	if(key == 'y')
	  Ey -= .2;
	if(key == 'z')
	  Ez -= .2;
	if(key == 'X')
	  Ex += .2;
	if(key == 'Y')
	  Ey += .2;
	if(key == 'Z')
	  Ez += .2;
	if (key == 'q')
      rotate_y += 5;
	if (key == 'w')
      rotate_y -= 5;
    if (key == 'e')
      rotate_x += 5;
    if (key == 'r')
      rotate_x -= 5;
	if (key == 'a')
      rotate_z += 5;
    if (key == 's')
      rotate_z -= 5;

	glutPostRedisplay();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 0.5, 10.0);
   glMatrixMode (GL_MODELVIEW);
}
////////////////////////////////////////////////////////////////////////////

//Pre:None
//Post:Initializes two windows, one for displaying the 3d solar system, the other for the camera rotation simulation
//along with their required callbacks
void initialize()
{
	//Setup solar system window
	cout << "---- Solar System Camera Controls ----" << endl;
	cout << "1: Rotate +x axis" << endl;
	cout << "2: Rotate +y axis" << endl;
	cout << "3: Rotate +z axis" << endl;

	solarSys = new SolarSystem();
	xAngle = yAngle = zAngle = 0;

	glutInitWindowSize(ssWidth,ssHeight);
	solarSystemWindow = glutCreateWindow("Solar System");
	//Callbacks specifically for solar system window
	glutReshapeFunc(solarSys_Reshape);
	glutDisplayFunc(solarSys_Display);
	glutKeyboardFunc(solarSys_KeyboardInput);
	glutSpecialFunc(solarSys_SpecialKeyboardInput);//Extra keyboard callback needed for up/down keys
	glShadeModel(GL_FLAT);
	glutIdleFunc(update);

	//Setup camera rotate example window here
	glutInitWindowPosition(520,0);
	cameraRotateWindow = glutCreateWindow("Camera Rotate");
	glEnable(GL_DEPTH_TEST);
 
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed);
	
}//end initializeWindows

//Application entrypoint
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	initialize(); //setup windows & initialize data

	glutMainLoop();
}//end main