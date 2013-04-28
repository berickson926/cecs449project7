#ifndef CLASS_PLANET_H
#define CLASS_PLANET_H

#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/Glut.h>
#include <stdlib.h>

class Planet
{
private:

	int* color;		//Defines RGB values for color rendering
	int pRadius;	//Radius of the planet


	int oRadius;	//Orbit radius from center of system
	int angle;		//Current rotation angle around center of system
	int delta;		//Change in rotation angle for update

public:

	//Constructor
	Planet(int red, int green, int blue, int pRadius, int oRadius, int delta);

	void render();
	void update();
};

#endif