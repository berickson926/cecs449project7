
#include "Planet.h"

Planet::Planet(int red, int green, int blue, int pRadius, int oRadius, float year, float day)
{
	color = new int[3];
	color[0] = red;
	color[1] = green;
	color[2] = blue;
	
	this->pRadius = pRadius;
	this->oRadius = oRadius;
	this->delta = delta;
	angle = 0;

	hourOfDay = 0;
	dayOfYear = 0;
	this->year = year;
	this->day = day;
}

//Pre:
//Post:
void Planet::render()
{
	//can use glutSoldSphere(...); alternatively

	glColor3f(color[0], color[1], color[2]);
	
	glRotatef(360.0 * dayOfYear / year, 0, 1, 0);//rotate
	glTranslatef(oRadius, 0, 0); 

	glPushMatrix();
		glRotatef(360 * hourOfDay / day, 0,1,0); //Rotate planet on its axis
		glutWireSphere(pRadius, 50,50);
	glPopMatrix();
}//end render

//Pre:
//Post:
void Planet::update(float stepMult)
{
	hourOfDay += stepMult;
	dayOfYear += stepMult/24.0;

	hourOfDay = hourOfDay - ((int)(hourOfDay/day))*day;
	dayOfYear = dayOfYear - ((int)(dayOfYear/year))*year;
}//end update
