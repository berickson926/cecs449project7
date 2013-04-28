
#include "SolarSystem.h"



SolarSystem::SolarSystem()
{
	sun = new Planet(1,1,0, 50,0,0, 0,0,0);
	earth = new Planet(0,0,1, 15,150,1, 1,0,0);

	/*planetX = new Planet(1,0,1, 15, 100,5, 0,1,0);
	planetY = new Planet(1,0,0, 15, 200,2, 0,1,0);
	planetZ = new Planet(0,1,1, 15, 250,1, 0,1,0);*/
}


void SolarSystem::render()
{
	glPushMatrix();
	sun->render();
	glPopMatrix();

	glPushMatrix();
	earth->render();
	glPopMatrix();

	/*glPushMatrix();
		planetX->render();
	glPopMatrix();

	glPushMatrix();
		planetY->render();
	glPopMatrix();

	glPushMatrix();
		planetZ->render();
	glPopMatrix();*/
}//end render

void SolarSystem::update()
{
	earth->update();

	/*planetX->update();
	planetY->update();
	planetZ->update();*/
}//end update