#ifndef CLASS_SOLARSYSTEM_H
#define CLASS_SOLARSYSTEM_H

#include "Planet.h"

enum State {RUNNING, STOPPED};

class SolarSystem
{
private:

	//Various celestial objects
	Planet *sun;
	Planet *earth;

	Planet *planetX;
	Planet *planetY;
	Planet *planetZ;

public:

	//Constructor
	SolarSystem();

	void update();
	void input(State state);
	void render();
};

#endif