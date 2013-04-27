#ifndef CLASS_SOLARSYSTEM_H
#define CLASS_SOLARSYSTEM_H

class SolarSystem
{
private:

	Planet planetArray;

public:

	//Constructor
	SolarSystem();

	update();
	//update(keyboard key input?);
	render();
};

#endif