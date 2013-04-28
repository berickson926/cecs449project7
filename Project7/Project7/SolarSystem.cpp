/*
	SolarSystem.cpp
	Project 7, CECS 449
	Author: Bret Erickson
*/

#include "SolarSystem.h"

SolarSystem::SolarSystem()
{
	stepMultiplier = 1;

	sun = new Planet(1,1,0, 50,0,0, 0,0,0);
	earth = new Planet(0,0,1, 15,150,1, 1,0,0);

	planetX = new Planet(1,0,1, 15, 100,5, 0,1,0);
	planetY = new Planet(1,0,0, 15, 200,2, 0,1,0);
	planetZ = new Planet(0,1,1, 15, 250,1, 0,1,0);
}//end constructor

void SolarSystem::render()
{
	glPushMatrix();
		sun->render();
	glPopMatrix();

	glPushMatrix();
		earth->render();
	glPopMatrix();

	glPushMatrix();
		planetX->render();
	glPopMatrix();

	glPushMatrix();
		planetY->render();
	glPopMatrix();

	glPushMatrix();
		planetZ->render();
	glPopMatrix();
}//end render

void SolarSystem::update()
{
	if(state != STOPPED || state==STEP)
	{
		earth->update(stepMultiplier);

		planetX->update(stepMultiplier);
		planetY->update(stepMultiplier);
		planetZ->update(stepMultiplier);

		if(state == STEP)
			state = STOPPED;
	}
}//end update

void SolarSystem::toggleAnimation()
{
	if(state != STOPPED)
		state = STOPPED;
	else
		state = RUNNING;
}//end toggleAnimation

void SolarSystem::singleStep()
{
	state = STEP;
	this->update();
	this->render();
}//end singleStep

void SolarSystem::increaseStep()
{
	stepMultiplier = stepMultiplier * 2;
}//end increaseStep

void SolarSystem::decreaseStep()
{
	stepMultiplier = stepMultiplier / 2;
}//end decreaseStep