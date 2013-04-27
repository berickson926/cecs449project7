
#include "Planet.h"

Planet::Planet(int red, int green, int blue, int radius, int delta)
{
	color = new int[3];
	color[0] = red;
	color[1] = green;
	color[2] = blue;

	this->radius = radius;
	this->delta = delta;
	angle = 0;
}


void Planet::render()
{
	//can use glutSoldSphere(...); alternatively

	glColor3f(color[0], color[1], color[2]);
	
	glPushMatrix();
	glRotatef(angle, 0,1,0);//need to modify for different axis possibilities
	glTranslatef(radius, 0, 0); //Only working on x-axis atm, need to modify to allow axis to be changed
	glutWireSphere(10, 50,50);
	

}//end render

void Planet::update()
{
	angle += delta;

	if(angle > 360)
	{
		angle = 0;

	}		
}
