/*
	SolarSystem.cpp
	Project 7, CECS 449
	Author: Bret Erickson
*/

#include "SolarSystem.h"

SolarSystem::SolarSystem()
{
	stepMultiplier = 24;

	sun =	new Planet(1,1,0, 50,0, 1,1); //Yes I know the sun isn't a planet, thanks
	earth = new Planet(0,0,1, 15,150, 365,24);
	moon =	new Planet(1,1,1, 2,20, 30.4, 1);

	planetX = new Planet(1,0,1, 15, 300, 200,1);
	planetY = new Planet(1,0,0, 15, 200, 500,1);
	planetZ = new Planet(0,1,1, 15, 250, 100,1);

	state = RUNNING;

}//end constructor

void SolarSystem::render()
{
	glPushMatrix();
		sun->render();
	glPopMatrix();

	glPushMatrix();
		earth->render();
		moon->render();
	glPopMatrix();

	glPushMatrix();
		planetX->render();
	glPopMatrix();

	glPushMatrix();
		glRotatef(120,0,0,1);
		planetY->render();
	glPopMatrix();

	glPushMatrix();
		glRotatef(90,1,1,1);
		planetZ->render();
	glPopMatrix();
}//end render

void SolarSystem::update()
{
	if(state == RUNNING || state==STEP)
	{
		earth->update(stepMultiplier);
		moon->update(stepMultiplier);

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