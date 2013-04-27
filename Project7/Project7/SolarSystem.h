#ifndef CLASS_SOLARSYSTEM_H
#define CLASS_SOLARSYSTEM_H

#include "Planet.h"

class SolarSystem
{
private:

	//Planet planetArray;
	Planet *testSun;
	Planet *testPlanet;

public:

	//Constructor
	SolarSystem();

	void update();
	//update(keyboard key input?);
	void render();
};

#endif