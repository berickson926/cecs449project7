
#include "Planet.h"

void drawCirclePoint(int x, int y)
{
	glPointSize(.5);
	glColor3f(1.0,1.0,1.0);

	glBegin(GL_POINTS);
		glVertex2i(x,y);
		glVertex2i(-x,y);
		glVertex2i(x,-y);
		glVertex2i(-x,-y);
		glVertex2i(y,+x);
		glVertex2i(-y,x);
		glVertex2i(y,-x);
		glVertex2i(-y,-x);
	glEnd();
}//end drawCirclePoint

//Used to draw the orbital path of this planet
void circleMidpoint(int oRadius)
{
	int radius = oRadius; //Will approximate 1 foot
	int x = 0;
	int y = radius;

	float pK = (5/4) - radius;//p0

	//draw the first point
	drawCirclePoint(x, y);

	while(x < y)
	{
		if(pK < 0)
		{
			x++;
			pK += 2*x+1;
		}//end if
		else
		{
			x++;
			y--;
			pK += 2*(x-y)+1;
		}

		drawCirclePoint(x, y);//Draw additional points
	}//end while

}//end circleMidpoint

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
	glPushMatrix();
		glColor3f(1,1,1);
		glBegin(GL_LINES);
			glVertex2f(0,500);
			glVertex2f(0,-500);
		glEnd();
		glRotatef(90,1,0,0);
		circleMidpoint(oRadius);
	glPopMatrix();

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
