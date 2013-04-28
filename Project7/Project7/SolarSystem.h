#ifndef CLASS_SOLARSYSTEM_H
#define CLASS_SOLARSYSTEM_H

#include "Planet.h"

enum State {RUNNING, STOPPED, STEP};

class SolarSystem
{
private:

	State state;		//Manages state of the entire solar system update/rendering for user control
	float stepMultiplier;	//increase/decrease speed of celestial object rotation


	//Various celestial objects
	Planet *sun;
	Planet *earth;

	Planet *planetX;
	Planet *planetY;
	Planet *planetZ;

public:

	//Constructor
	SolarSystem();

	//Pre:None
	//Post:Moves all models in solar system forwad in time by one step
	void update();

	//Pre:none
	//Post:Renders solar system scene
	void render();

	//Pre:none
	//Post:
	void increaseStep();

	//Pre:
	//Post:
	void decreaseStep();

	//Pre:None
	//Post: If system in in RUNNING state, system moves into STOPPED and no longer updates scene
	//		Otherwise, a STOPPED system moves into RUNNING state and continues updating the model
	void toggleAnimation();

	//Pre:none
	//Post:Forces model to update/render one iteration even if stopped.
	//     Moves system into stopped state upon completion
	void singleStep();
};

#endif