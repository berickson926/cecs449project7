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

	int* color; //Defines RGB values for color rendering
	int radius; //Distance planet appears from center of system

	int angle;
	int delta; //Change in rotation angle for update

public:

	//Constructors
	Planet();

	Planet(int red, int green, int blue, int radius, int delta);

	void render();
	void update();
};

#endif