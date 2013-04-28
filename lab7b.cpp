// CECS 449
//Assignment #7
//James Pardue

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <glut.h>


void display();
void mykeys();
 

double rotate_y=0; 
double rotate_x=0;
double rotate_z=0;
 

float Ex = -1;
float Ey = -1; 
float Ez = -1;

void display(){
 
	

  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
  // Reset transformations
  glLoadIdentity();

  //gluLookAt (Ex, Ey, Ez, cx, cy, cz, Up_x, Up_y, Up_z) 
  gluLookAt (Ex, Ey, Ez, 0, 0, 0, 0, 1, 0);


  // Rotate camera
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  glRotatef( rotate_z, 0.0, 0.0, 1.0 );

  //White side - FRONT
  glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );     
  glVertex3f(  0.5, -0.5, -0.5 );
  glVertex3f(  0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
 
  // Grey side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   0.2,  0.2, 0.2 );
  glVertex3f(  0.5, -0.5, 0.5 );
  glVertex3f(  0.5,  0.5, 0.5 );
  glVertex3f( -0.5,  0.5, 0.5 );
  glVertex3f( -0.5, -0.5, 0.5 );
  glEnd();
 
  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  1.0,  1.0,  0.0 );
  glVertex3f( 0.5, -0.5, -0.5 );
  glVertex3f( 0.5,  0.5, -0.5 );
  glVertex3f( 0.5,  0.5,  0.5 );
  glVertex3f( 0.5, -0.5,  0.5 );
  glEnd();
 
  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  1.0,  0.0 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
 
  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f(  0.5,  0.5,  0.5 );
  glVertex3f(  0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glEnd();
 
  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f(  0.5, -0.5, -0.5 );
  glVertex3f(  0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
 
  printf(".");

  glFlush();
  glutSwapBuffers();
 
}


void keyPressed (unsigned char key, int x, int y)
{  

	if(key == 'x')
	  Ex -= .2;
	if(key == 'y')
	  Ey -= .2;
	if(key == 'z')
	  Ez -= .2;
	if(key == 'X')
	  Ex += .2;
	if(key == 'Y')
	  Ey += .2;
	if(key == 'Z')
	  Ez += .2;
	if (key == 'q')
      rotate_y += 5;
	if (key == 'w')
      rotate_y -= 5;
    if (key == 'e')
      rotate_x += 5;
    if (key == 'r')
      rotate_x -= 5;
	if (key == 'a')
      rotate_z += 5;
    if (key == 's')
      rotate_z -= 5;

	glutPostRedisplay();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 0.5, 10.0);
   glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char* argv[]){
 
  glutInit(&argc,argv);
 
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (500, 500); 
 
  //glMatrixMode(GL_PROJECTION);
  

  glutCreateWindow("Camera Rotate");
 
  glEnable(GL_DEPTH_TEST);
 
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyPressed);
 
  glutMainLoop();
 
  return 0;
 
}