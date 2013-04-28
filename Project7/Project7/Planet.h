#ifndef CLASS_PLANET_H
#define CLASS_PLANET_H

#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/Glut.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Planet
{
private:

	int* color;		//Defines RGB values for color rendering
	int pRadius;	//Radius of the planet
	float hourOfDay;//Day length of planet
	float dayOfYear;//Rotational period around center of system
	float day;		//max hours per day
	float year;		//max days per year

	int oRadius;	//Orbit radius from center of system
	float angle;	//Current rotation angle around center of system
	float delta;	//Change in rotation angle for update

public:

	//Constructor
	Planet(int red, int green, int blue, int pRadius, int oRadius, float year, float day);

	void render();
	void update(float stepMult);
};

#endif