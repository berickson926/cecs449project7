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

int cameraRotateWindow, solarSystemWindow; //Identifiers for the separate windows
int wWidth = 500;
int wHeight= 500;

//Pre:
//Post:
void solarSys_KeyboardInput(unsigned char key, int x, int y)
{
	//TODO
}//end solarSys_KeyboardInput

//Pre:
//Post:
void solarSys_Display()
{
	//TODO
}//end solarSys_Display

//Pre:
//Post:
void solarSys_Reshape(int w, int h)
{
	//TODO

}//end solarSys_Reshape


//Pre:None
//Post:Initializes two windows, one for displaying the 3d solar system, the other for the camera rotation simulation
//along with their required callbacks
void initialize()
{
	glutInitWindowSize(wWidth,wHeight);



	//Setup solar system window
	solarSystemWindow = glutCreateWindow("Solar System");
	glutReshapeFunc(solarSys_Reshape);
	glutDisplayFunc(solarSys_Display);
	glutKeyboardFunc(solarSys_KeyboardInput);

	//Setup camera rotate example window



}//end initializeWindows


void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);


	initialize();

	glutMainLoop();
}//end main