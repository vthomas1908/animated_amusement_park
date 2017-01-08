#include "Wheel.h"
#include "libtarga.h"
#include <math.h>
#include <iostream>
#include <GL/glu.h>
#include <stdio.h>

// Destructor
Wheel::~Wheel(void)
{
	
    if ( initialized )
    {
	glDeleteLists(display_list, 1);
    }
	
}


// Initializer. Returns false if something went wrong, like not being able to
// load the texture.
bool
Wheel::Initialize(void)
{
	
    initialized = true;
	rotation = 0;
	rotation_update = .5;

    return true;
}


// Draw just calls the display list we set up earlier.
void
Wheel::Draw(void)
{
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	
	//front
	glNormal3f(0, -1, 0);
	glVertex3f(-13, -4, -11);
	glVertex3f(-11, -4, -11);
	glVertex3f(1, -4, 0);
	glVertex3f(-1, -4, 0);

	//back
	glNormal3f(0, 1, 0);
	glVertex3f(-13, -3, -11);
	glVertex3f(-11, -3, -11);
	glVertex3f(1, -3, 0);
	glVertex3f(-1, -3, 0);

	//left
	glNormal3f(-1, 0, 0);
	glVertex3f(-13, -4, -11);
	glVertex3f(-1, -4, 0);
	glVertex3f(-1, -3, 0);
	glVertex3f(-13, -3, -11);

	//right
	glNormal3f(1, 0, 0);
	glVertex3f(-11, -4, -11);
	glVertex3f(1, -4, 0);
	glVertex3f(1, -3, 0);
	glVertex3f(-11, -3, -11);

	glEnd();

	glBegin(GL_QUADS);
	
	//front
	glNormal3f(0, -1, 0);
	glVertex3f(-1, -4, 0);
	glVertex3f(1, -4, 0);
	glVertex3f(13, -4, -11);
	glVertex3f(11, -4, -11);

	//back
	glNormal3f(0, 1, 0);
	glVertex3f(-1, -3, 0);
	glVertex3f(1, -3, 0);
	glVertex3f(13, -3, -11);
	glVertex3f(11, -3, -11);

	//left
	glNormal3f(-1, 0, 0);
	glVertex3f(-1, -4, 0);
	glVertex3f(-1, -3, 0);
	glVertex3f(11, -3, -11);
	glVertex3f(11, -4, -11);

	//right
	glNormal3f(1, 0, 0);
	glVertex3f(1, -4, 0);
	glVertex3f(1, -3, 0);
	glVertex3f(13, -3, -11);
	glVertex3f(13, -4, -11);

	//top
	glNormal3f(0, 0, 1);
	glVertex3f(-1, -4, 0);
	glVertex3f(-1, -3, 0);
	glVertex3f(1, -3, 0);
	glVertex3f(1, -4, 0);
	
	glEnd();

	glBegin(GL_QUADS);
	
	//front
	glNormal3f(0, 1, 0);
	glVertex3f(-13, 4, -11);
	glVertex3f(-11, 4, -11);
	glVertex3f(1, 4, 0);
	glVertex3f(-1, 4, 0);

	//back
	glNormal3f(0, -1, 0);
	glVertex3f(-13, 3, -11);
	glVertex3f(-11, 3, -11);
	glVertex3f(1, 3, 0);
	glVertex3f(-1, 3, 0);

	//left
	glNormal3f(-1, 0, 0);
	glVertex3f(-13, 4, -11);
	glVertex3f(-1, 4, 0);
	glVertex3f(-1, 3, 0);
	glVertex3f(-13, 3, -11);

	//right
	glNormal3f(1, 0, 0);
	glVertex3f(-11, 4, -11);
	glVertex3f(1, 4, 0);
	glVertex3f(1, 3, 0);
	glVertex3f(-11, 3, -11);

	glEnd();

	glBegin(GL_QUADS);
	
	//front
	glNormal3f(0, 1, 0);
	glVertex3f(-1, 4, 0);
	glVertex3f(1, 4, 0);
	glVertex3f(13, 4, -11);
	glVertex3f(11, 4, -11);

	//back
	glNormal3f(0, -1, 0);
	glVertex3f(-1, 3, 0);
	glVertex3f(1, 3, 0);
	glVertex3f(13, 3, -11);
	glVertex3f(11, 3, -11);

	//left
	glNormal3f(-1, 0, 0);
	glVertex3f(-1, 4, 0);
	glVertex3f(-1, 3, 0);
	glVertex3f(11, 3, -11);
	glVertex3f(11, 4, -11);

	//right
	glNormal3f(1, 0, 0);
	glVertex3f(1, 4, 0);
	glVertex3f(1, 3, 0);
	glVertex3f(13, 3, -11);
	glVertex3f(13, 4, -11);

	//top
	glNormal3f(0, 0, 1);
	glVertex3f(-1, 4, 0);
	glVertex3f(-1, 3, 0);
	glVertex3f(1, 3, 0);
	glVertex3f(1, 4, 0);
	
	glEnd();

	glColor3f((float)250/(float)256, (float)12/(float)256, (float)163/(float)256);;
	gluDisk(gluNewQuadric(), 11, 16, 20, 10);

	glRotated(rotation, 0, 1, 0);

	
    glPushMatrix();

	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glPushMatrix();
	glTranslated(0, 0, -4.5);
	glColor3f(1, 1, 1);
	gluCylinder(gluNewQuadric(), .5, .5, 9, 10, 10);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 0, 4.5);
	glColor3f(1, 0, 0);
	gluDisk(gluNewQuadric(), 0, .5, 10, 10);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 0, -4.5);
	glColor3f(1, 0, 0);
	gluDisk(gluNewQuadric(), 0, .5, 10, 10);
	glPopMatrix();
	glPopMatrix();

	glColor3f((float)144/(float)256, (float)31/(float)256, (float)209/(float)256);
	gluSphere(gluNewQuadric(), 3, 10, 10);

	glColor3f((float)209/(float)256, (float)31/(float)256, (float)55/(float)256);
	gluCylinder(gluNewQuadric(), 2, .25, 10, 10, 10);
	glPushMatrix();
	glTranslatef(0, 0, 10);
	glColor3f(0, 0, 0);
	gluSphere(gluNewQuadric(), 1, 5, 5);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(60, 0, 1, 0);
	glColor3f((float)96/(float)256, (float)209/(float)256, (float)31/(float)256);
	gluCylinder(gluNewQuadric(), 2, 0, 10, 10, 10);
	glPushMatrix();
	glTranslatef(0, 0, 10);
	glColor3f(0, 0, 0);
	gluSphere(gluNewQuadric(), 1, 5, 5);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(60, 0, 1, 0);
	glColor3f((float)31/(float)256, (float)185/(float)256, (float)209/(float)256);
	gluCylinder(gluNewQuadric(), 2, 0, 10, 10, 10);
	glPushMatrix();
	glTranslatef(0, 0, 10);
	glColor3f(0, 0, 0);
	gluSphere(gluNewQuadric(), 1, 5, 5);
	glPopMatrix();

	glPushMatrix();
	glRotatef(60, 0, 1, 0);
	glColor3f((float)209/(float)256, (float)55/(float)256, (float)31/(float)256);
	gluCylinder(gluNewQuadric(), 2, 0, 10, 10, 10);
	glPushMatrix();
	glTranslatef(0, 0, 10);
	glColor3f(0, 0, 0);
	gluSphere(gluNewQuadric(), 1, 5, 5);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(60, 0, 1, 0);
	glColor3f((float)96/(float)256, (float)209/(float)256, (float)31/(float)256);
	gluCylinder(gluNewQuadric(), 2, 0, 10, 10, 10);
	glPushMatrix();
	glTranslatef(0, 0, 10);
	glColor3f(0, 0, 0);
	gluSphere(gluNewQuadric(), 1, 5, 5);
	glPopMatrix();

	glPushMatrix();
	glRotatef(60, 0, 1, 0);
	glColor3f((float)31/(float)256, (float)185/(float)256, (float)209/(float)256);
	gluCylinder(gluNewQuadric(), 2, 0, 10, 10, 10);
	glPushMatrix();
	glTranslatef(0, 0, 10);
	glColor3f(0, 0, 0);
	gluSphere(gluNewQuadric(), 1, 5, 5);
	glPopMatrix();

	glPushMatrix();
	glRotatef(60, 0, 1, 0);
	glColor3f((float)145/(float)256, (float)69/(float)256, (float)15/(float)256);
	gluCylinder(gluNewQuadric(), 2, 0, 10, 10, 10);
	glPushMatrix();
	glTranslatef(0, 0, 10);
	glColor3f(0, 0, 0);
	gluSphere(gluNewQuadric(), 1, 5, 5);
	glPopMatrix();

	

    glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void Wheel::Update(void)
{
	
	glRotatef(rotation, 0, 1, 0);
	glPushMatrix();
		glColor3f(1, 1, 0);
	gluDisk(gluNewQuadric(), 10, 15, 20, 10);
    glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	gluSphere(gluNewQuadric(), 3, 10, 10);

	glColor3f(0, 0, 1);
	gluCylinder(gluNewQuadric(), 2, .25, 10, 10, 10);
	glPushMatrix();
	glTranslatef(0, 0, 10);
	glColor3f(0, 0, 0);
	gluSphere(gluNewQuadric(), 1, 5, 5);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(60, 0, 1, 0);
	glColor3f(0, 1, 1);
	gluCylinder(gluNewQuadric(), 2, 0, 10, 10, 10);
	glPushMatrix();
	glTranslatef(0, 0, 10);
	glColor3f(0, 0, 0);
	gluSphere(gluNewQuadric(), 1, 5, 5);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(60, 0, 1, 0);
	glColor3f(0, 1, 1);
	gluCylinder(gluNewQuadric(), 2, 0, 10, 10, 10);
	glPushMatrix();
	glTranslatef(0, 0, 10);
	glColor3f(0, 0, 0);
	gluSphere(gluNewQuadric(), 1, 5, 5);
	glPopMatrix();

	glPushMatrix();
	glRotatef(60, 0, 1, 0);
	glColor3f(0, 1, 1);
	gluCylinder(gluNewQuadric(), 2, 0, 10, 10, 10);
	glPushMatrix();
	glTranslatef(0, 0, 10);
	glColor3f(0, 0, 0);
	gluSphere(gluNewQuadric(), 1, 5, 5);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(60, 0, 1, 0);
	glColor3f(0, 1, 1);
	gluCylinder(gluNewQuadric(), 2, 0, 10, 10, 10);
	glPushMatrix();
	glTranslatef(0, 0, 10);
	glColor3f(0, 0, 0);
	gluSphere(gluNewQuadric(), 1, 5, 5);
	glPopMatrix();

	glPushMatrix();
	glRotatef(60, 0, 1, 0);
	glColor3f(0, 1, 1);
	gluCylinder(gluNewQuadric(), 2, 0, 10, 10, 10);
	glPushMatrix();
	glTranslatef(0, 0, 10);
	glColor3f(0, 0, 0);
	gluSphere(gluNewQuadric(), 1, 5, 5);
	glPopMatrix();

	glPushMatrix();
	glRotatef(60, 0, 1, 0);
	glColor3f(0, 1, 1);
	gluCylinder(gluNewQuadric(), 2, 0, 10, 10, 10);
	glPushMatrix();
	glTranslatef(0, 0, 10);
	glColor3f(0, 0, 0);
	gluSphere(gluNewQuadric(), 1, 5, 5);
	glPopMatrix();

	

    glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();


	rotation += rotation_update;

}