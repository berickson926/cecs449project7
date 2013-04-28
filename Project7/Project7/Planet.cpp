
#include "Planet.h"

Planet::Planet(int red, int green, int blue, int pRadius, int oRadius, int delta,
			   int x, int y, int z)
{
	color = new int[3];
	color[0] = red;
	color[1] = green;
	color[2] = blue;
	
	this->pRadius = pRadius;
	this->oRadius = oRadius;
	this->delta = delta;
	angle = 0;

	axis = new int[3];
	axis[0] = x;
	axis[1] = y;
	axis[2] = z;

	cout << x << " " << y << " " << z << endl;
}

//Pre:
//Post:
void Planet::render()
{
	//can use glutSoldSphere(...); alternatively

	glColor3f(color[0], color[1], color[2]);
	
	glPushMatrix();
		glRotatef(angle, 0, 1, 0);//need to modify for different axis possibilities
		glTranslatef(oRadius, 0, 0); //Only working on x-axis atm, need to modify to allow axis to be changed
		glutSolidSphere(pRadius, 50,50);
	glPopMatrix();

}//end render

//Pre:
//Post:
void Planet::update(float stepMult)
{
	angle += (delta * stepMult);

	if(angle > 360)
		angle = 0;
}//end update
