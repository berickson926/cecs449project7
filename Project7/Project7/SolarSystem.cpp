
#include "SolarSystem.h"

SolarSystem::SolarSystem()
{
	testSun = new Planet(1,1,0, 0, 0);
	testPlanet = new Planet(0,1,1, 50, 2);
}


void SolarSystem::render()
{
	testSun->render();

	testPlanet->render();//debug

}

void SolarSystem::update()
{
	testPlanet->update();

}