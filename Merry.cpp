#include "Merry.h"
#include "libtarga.h"
#include <math.h>
#include <iostream>
#include <GL/glu.h>
#include <stdio.h>

// Destructor
Merry::~Merry(void)
{
	
    if ( initialized )
    {
	glDeleteLists(display_list, 1);
    }
	
}


// Initializer. Returns false if something went wrong, like not being able to
// load the texture.
bool
Merry::Initialize(void)
{
	
    initialized = true;
	rotation = 0;
	rotation_update = -.35;

    return true;
}


// Draw just calls the display list we set up earlier.
void
Merry::Draw(void)
{
	float bodyx = 1.5;
	float bodyy = 1;
	float bodyz = .75;

	float head_bottom_lx = -.5;
	float head_bottom_lz = -.5;
	float head_top_lx = -.5;
	float head_top_lz = .5;

	float mouth_x = .75;
	float mouth_z = -.5;

	float nose_x = .75;
	float nose_z = 0;

	float eye_x = .25;
	float eye_z = .25;

	float forhead_x = 0;
	float forhead_z = .5;

	float y = .6;

	glColor3f((float)247/(float)256, (float)123/(float)256, (float)15/(float)256);
	gluCylinder(gluNewQuadric(), 5, 5, 2, 20, 20);
	

	glRotated(-rotation, 0, 0, 1);
	glTranslated(0, 0, 2);
	glColor3f((float)15/(float)256, (float)220/(float)256, (float)247/(float)256);
	gluDisk(gluNewQuadric(), 0, 5, 20, 20);

	glPushMatrix();
	glTranslated(0, -4, 0);

	glColor3f((float)15/(float)256, (float)247/(float)256, (float)42/(float)256);
	gluCylinder(gluNewQuadric(), .5, .5, 5, 5, 5);

	glPushMatrix();
	glTranslated(0, 0, 2.25);
	glColor3f((float)247/(float)256, (float)123/(float)256, (float)15/(float)256);
	glBegin(GL_QUADS);
	//front
	glNormal3f(0, -1, 0);
	glVertex3f(-bodyx, -bodyy, -bodyz);
	glVertex3f(bodyx, -bodyy, -bodyz);
	glVertex3f(bodyx, -bodyy, bodyz);
	glVertex3f(-bodyx, -bodyy, bodyz);
	//back
	glNormal3f(0, 1, 0);
	glVertex3f(-bodyx, bodyy, -bodyz);
	glVertex3f(bodyx, bodyy, -bodyz);
	glVertex3f(bodyx, bodyy, bodyz);
	glVertex3f(-bodyx, bodyy, bodyz);
	//right
	glNormal3f(1, 0, 0);
	glVertex3f(bodyx, -bodyy, -bodyz);
	glVertex3f(bodyx, -bodyy, bodyz);
	glVertex3f(bodyx, bodyy, bodyz);
	glVertex3f(bodyx, bodyy, -bodyz);
	//left
	glNormal3f(-1, 0, 0);
	glVertex3f(-bodyx, -bodyy, -bodyz);
	glVertex3f(-bodyx, -bodyy, bodyz);
	glVertex3f(-bodyx, bodyy, bodyz);
	glVertex3f(-bodyx, bodyy, -bodyz);
	//top
	glNormal3f(0, 0, 1);
	glVertex3f(-bodyx, -bodyy, bodyz);
	glVertex3f(-bodyx, bodyy, bodyz);
	glVertex3f(bodyx, bodyy, bodyz);
	glVertex3f(bodyx, -bodyy, bodyz);
	//bottom
	glNormal3f(0, 0, -1);
	glVertex3f(-bodyx, -bodyy, -bodyz);
	glVertex3f(-bodyx, bodyy, -bodyz);
	glVertex3f(bodyx, bodyy, -bodyz);
	glVertex3f(bodyx, -bodyy, -bodyz);
	glEnd();

	//head
	glTranslated(1.5, 0, 1);
	glBegin(GL_POLYGON);
	//front
	glNormal3f(0, -1, 0);
	glVertex3f(head_bottom_lx, -y, head_bottom_lz);
	glVertex3f(mouth_x, -y, mouth_z);
	glVertex3f(nose_x, -y, nose_z);
	glVertex3f(eye_x, -y, eye_z);
	glVertex3f(forhead_x, -y, forhead_z);
	glVertex3f(head_top_lx, -y, head_top_lz);
	//back
	glNormal3f(0, 1, 0);
	glVertex3f(head_bottom_lx, y, head_bottom_lz);
	glVertex3f(mouth_x, y, mouth_z);
	glVertex3f(nose_x, y, nose_z);
	glVertex3f(eye_x, y, eye_z);
	glVertex3f(forhead_x, y, forhead_z);
	glVertex3f(head_top_lx, y, head_top_lz);
	//right
	glNormal3f(1, 0, 0);
	glVertex3f(mouth_x, -y, mouth_z);
	glVertex3f(mouth_x, y, mouth_z);
	glVertex3f(nose_x, y, nose_z);
	glVertex3f(eye_x, y, eye_z);
	glVertex3f(forhead_x, y, forhead_z);
	glVertex3f(forhead_x, -y, forhead_z);
	glVertex3f(eye_x, -y, eye_z);
	glVertex3f(nose_x, -y, nose_z);
	//left
	glNormal3f(-1, 0, 0);
	glVertex3f(head_top_lx, -y, head_top_lz);
	glVertex3f(head_top_lx, y, head_top_lz);
	glVertex3f(head_bottom_lx, y, head_bottom_lz);
	glVertex3f(head_bottom_lx, -y, head_bottom_lz);
	//top
	glNormal3f(0, 0, 1);
	glVertex3f(head_top_lx, -y, head_top_lz);
	glVertex3f(head_top_lx, y, head_top_lz);
	glVertex3f(forhead_x, y, forhead_z);
	glVertex3f(forhead_x, -y, forhead_z);
	//bottom
	glNormal3f(0, 0, -1);
	glVertex3f(head_bottom_lx, -y, head_bottom_lz);
	glVertex3f(head_bottom_lx, y, head_bottom_lz);
	glVertex3f(mouth_x, y, mouth_z);
	glVertex3f(mouth_x, -y, mouth_z);
	glEnd();
	glPopMatrix();

	glPopMatrix();


	glPushMatrix();
	glRotated(90, 0, 0, 1);

	glPushMatrix();
	glTranslated(0, -4, 0);
	glColor3f((float)247/(float)256, (float)123/(float)256, (float)15/(float)256);
	gluCylinder(gluNewQuadric(), .5, .5, 5, 5, 5);

	glPushMatrix();
	glTranslated(0, 0, 2.25);
	glColor3f((float)15/(float)256, (float)247/(float)256, (float)42/(float)256);
	glBegin(GL_QUADS);
	//front
	glNormal3f(0, -1, 0);
	glVertex3f(-bodyx, -bodyy, -bodyz);
	glVertex3f(bodyx, -bodyy, -bodyz);
	glVertex3f(bodyx, -bodyy, bodyz);
	glVertex3f(-bodyx, -bodyy, bodyz);
	//back
	glNormal3f(0, 1, 0);
	glVertex3f(-bodyx, bodyy, -bodyz);
	glVertex3f(bodyx, bodyy, -bodyz);
	glVertex3f(bodyx, bodyy, bodyz);
	glVertex3f(-bodyx, bodyy, bodyz);
	//right
	glNormal3f(1, 0, 0);
	glVertex3f(bodyx, -bodyy, -bodyz);
	glVertex3f(bodyx, -bodyy, bodyz);
	glVertex3f(bodyx, bodyy, bodyz);
	glVertex3f(bodyx, bodyy, -bodyz);
	//left
	glNormal3f(-1, 0, 0);
	glVertex3f(-bodyx, -bodyy, -bodyz);
	glVertex3f(-bodyx, -bodyy, bodyz);
	glVertex3f(-bodyx, bodyy, bodyz);
	glVertex3f(-bodyx, bodyy, -bodyz);
	//top
	glNormal3f(0, 0, 1);
	glVertex3f(-bodyx, -bodyy, bodyz);
	glVertex3f(-bodyx, bodyy, bodyz);
	glVertex3f(bodyx, bodyy, bodyz);
	glVertex3f(bodyx, -bodyy, bodyz);
	//bottom
	glNormal3f(0, 0, -1);
	glVertex3f(-bodyx, -bodyy, -bodyz);
	glVertex3f(-bodyx, bodyy, -bodyz);
	glVertex3f(bodyx, bodyy, -bodyz);
	glVertex3f(bodyx, -bodyy, -bodyz);
	glEnd();

	//head
	glTranslated(1.5, 0, 1);
	glBegin(GL_QUADS);
	//front
	glNormal3f(0, -1, 0);
	glVertex3f(head_bottom_lx, -y, head_bottom_lz);
	glVertex3f(mouth_x, -y, mouth_z);
	glVertex3f(nose_x, -y, nose_z);
	glVertex3f(eye_x, -y, eye_z);
	glVertex3f(forhead_x, -y, forhead_z);
	glVertex3f(head_top_lx, -y, head_top_lz);
	//back
	glNormal3f(0, 1, 0);
	glVertex3f(head_bottom_lx, y, head_bottom_lz);
	glVertex3f(mouth_x, y, mouth_z);
	glVertex3f(nose_x, y, nose_z);
	glVertex3f(eye_x, y, eye_z);
	glVertex3f(forhead_x, y, forhead_z);
	glVertex3f(head_top_lx, y, head_top_lz);
	//right
	glNormal3f(1, 0, 0);
	glVertex3f(mouth_x, -y, mouth_z);
	glVertex3f(mouth_x, y, mouth_z);
	glVertex3f(nose_x, y, nose_z);
	glVertex3f(eye_x, y, eye_z);
	glVertex3f(forhead_x, y, forhead_z);
	glVertex3f(forhead_x, -y, forhead_z);
	glVertex3f(eye_x, -y, eye_z);
	glVertex3f(nose_x, -y, nose_z);
	//left
	glNormal3f(-1, 0, 0);
	glVertex3f(head_top_lx, -y, head_top_lz);
	glVertex3f(head_top_lx, y, head_top_lz);
	glVertex3f(head_bottom_lx, y, head_bottom_lz);
	glVertex3f(head_bottom_lx, -y, head_bottom_lz);
	//top
	glNormal3f(0, 0, 1);
	glVertex3f(head_top_lx, -y, head_top_lz);
	glVertex3f(head_top_lx, y, head_top_lz);
	glVertex3f(forhead_x, y, forhead_z);
	glVertex3f(forhead_x, -y, forhead_z);
	//bottom
	glNormal3f(0, 0, -1);
	glVertex3f(head_bottom_lx, -y, head_bottom_lz);
	glVertex3f(head_bottom_lx, y, head_bottom_lz);
	glVertex3f(mouth_x, y, mouth_z);
	glVertex3f(mouth_x, -y, mouth_z);
	glEnd();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 0, 0, 1);

	glPushMatrix();
	glTranslated(0, -4, 0);
	glColor3f((float)15/(float)256, (float)247/(float)256, (float)42/(float)256);
	gluCylinder(gluNewQuadric(), .5, .5, 5, 5, 5);

	glPushMatrix();
	glTranslated(0, 0, 2.25);
	glColor3f((float)247/(float)256, (float)123/(float)256, (float)15/(float)256);
	glBegin(GL_QUADS);
	//front
	glNormal3f(0, -1, 0);
	glVertex3f(-bodyx, -bodyy, -bodyz);
	glVertex3f(bodyx, -bodyy, -bodyz);
	glVertex3f(bodyx, -bodyy, bodyz);
	glVertex3f(-bodyx, -bodyy, bodyz);
	//back
	glNormal3f(0, 1, 0);
	glVertex3f(-bodyx, bodyy, -bodyz);
	glVertex3f(bodyx, bodyy, -bodyz);
	glVertex3f(bodyx, bodyy, bodyz);
	glVertex3f(-bodyx, bodyy, bodyz);
	//right
	glNormal3f(1, 0, 0);
	glVertex3f(bodyx, -bodyy, -bodyz);
	glVertex3f(bodyx, -bodyy, bodyz);
	glVertex3f(bodyx, bodyy, bodyz);
	glVertex3f(bodyx, bodyy, -bodyz);
	//left
	glNormal3f(-1, 0, 0);
	glVertex3f(-bodyx, -bodyy, -bodyz);
	glVertex3f(-bodyx, -bodyy, bodyz);
	glVertex3f(-bodyx, bodyy, bodyz);
	glVertex3f(-bodyx, bodyy, -bodyz);
	//top
	glNormal3f(0, 0, 1);
	glVertex3f(-bodyx, -bodyy, bodyz);
	glVertex3f(-bodyx, bodyy, bodyz);
	glVertex3f(bodyx, bodyy, bodyz);
	glVertex3f(bodyx, -bodyy, bodyz);
	//bottom
	glNormal3f(0, 0, -1);
	glVertex3f(-bodyx, -bodyy, -bodyz);
	glVertex3f(-bodyx, bodyy, -bodyz);
	glVertex3f(bodyx, bodyy, -bodyz);
	glVertex3f(bodyx, -bodyy, -bodyz);
	glEnd();

	//head
	glTranslated(1.5, 0, 1);
	glBegin(GL_QUADS);
	//front
	glNormal3f(0, -1, 0);
	glVertex3f(head_bottom_lx, -y, head_bottom_lz);
	glVertex3f(mouth_x, -y, mouth_z);
	glVertex3f(nose_x, -y, nose_z);
	glVertex3f(eye_x, -y, eye_z);
	glVertex3f(forhead_x, -y, forhead_z);
	glVertex3f(head_top_lx, -y, head_top_lz);
	//back
	glNormal3f(0, 1, 0);
	glVertex3f(head_bottom_lx, y, head_bottom_lz);
	glVertex3f(mouth_x, y, mouth_z);
	glVertex3f(nose_x, y, nose_z);
	glVertex3f(eye_x, y, eye_z);
	glVertex3f(forhead_x, y, forhead_z);
	glVertex3f(head_top_lx, y, head_top_lz);
	//right
	glNormal3f(1, 0, 0);
	glVertex3f(mouth_x, -y, mouth_z);
	glVertex3f(mouth_x, y, mouth_z);
	glVertex3f(nose_x, y, nose_z);
	glVertex3f(eye_x, y, eye_z);
	glVertex3f(forhead_x, y, forhead_z);
	glVertex3f(forhead_x, -y, forhead_z);
	glVertex3f(eye_x, -y, eye_z);
	glVertex3f(nose_x, -y, nose_z);
	//left
	glNormal3f(-1, 0, 0);
	glVertex3f(head_top_lx, -y, head_top_lz);
	glVertex3f(head_top_lx, y, head_top_lz);
	glVertex3f(head_bottom_lx, y, head_bottom_lz);
	glVertex3f(head_bottom_lx, -y, head_bottom_lz);
	//top
	glNormal3f(0, 0, 1);
	glVertex3f(head_top_lx, -y, head_top_lz);
	glVertex3f(head_top_lx, y, head_top_lz);
	glVertex3f(forhead_x, y, forhead_z);
	glVertex3f(forhead_x, -y, forhead_z);
	//bottom
	glNormal3f(0, 0, -1);
	glVertex3f(head_bottom_lx, -y, head_bottom_lz);
	glVertex3f(head_bottom_lx, y, head_bottom_lz);
	glVertex3f(mouth_x, y, mouth_z);
	glVertex3f(mouth_x, -y, mouth_z);
	glEnd();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glRotated(90, 0, 0, 1);

	glPushMatrix();
	glTranslated(0, -4, 0);
	glColor3f((float)247/(float)256, (float)123/(float)256, (float)15/(float)256);
	gluCylinder(gluNewQuadric(), .5, .5, 5, 5, 5);

	glPushMatrix();
	glTranslated(0, 0, 2.25);
	glColor3f((float)15/(float)256, (float)247/(float)256, (float)42/(float)256);
	glBegin(GL_QUADS);
	//front
	glNormal3f(0, -1, 0);
	glVertex3f(-bodyx, -bodyy, -bodyz);
	glVertex3f(bodyx, -bodyy, -bodyz);
	glVertex3f(bodyx, -bodyy, bodyz);
	glVertex3f(-bodyx, -bodyy, bodyz);
	//back
	glNormal3f(0, 1, 0);
	glVertex3f(-bodyx, bodyy, -bodyz);
	glVertex3f(bodyx, bodyy, -bodyz);
	glVertex3f(bodyx, bodyy, bodyz);
	glVertex3f(-bodyx, bodyy, bodyz);
	//right
	glNormal3f(1, 0, 0);
	glVertex3f(bodyx, -bodyy, -bodyz);
	glVertex3f(bodyx, -bodyy, bodyz);
	glVertex3f(bodyx, bodyy, bodyz);
	glVertex3f(bodyx, bodyy, -bodyz);
	//left
	glNormal3f(-1, 0, 0);
	glVertex3f(-bodyx, -bodyy, -bodyz);
	glVertex3f(-bodyx, -bodyy, bodyz);
	glVertex3f(-bodyx, bodyy, bodyz);
	glVertex3f(-bodyx, bodyy, -bodyz);
	//top
	glNormal3f(0, 0, 1);
	glVertex3f(-bodyx, -bodyy, bodyz);
	glVertex3f(-bodyx, bodyy, bodyz);
	glVertex3f(bodyx, bodyy, bodyz);
	glVertex3f(bodyx, -bodyy, bodyz);
	//bottom
	glNormal3f(0, 0, -1);
	glVertex3f(-bodyx, -bodyy, -bodyz);
	glVertex3f(-bodyx, bodyy, -bodyz);
	glVertex3f(bodyx, bodyy, -bodyz);
	glVertex3f(bodyx, -bodyy, -bodyz);
	glEnd();

	//head
	glTranslated(1.5, 0, 1);
	glBegin(GL_QUADS);
	//front
	glNormal3f(0, -1, 0);
	glVertex3f(head_bottom_lx, -y, head_bottom_lz);
	glVertex3f(mouth_x, -y, mouth_z);
	glVertex3f(nose_x, -y, nose_z);
	glVertex3f(eye_x, -y, eye_z);
	glVertex3f(forhead_x, -y, forhead_z);
	glVertex3f(head_top_lx, -y, head_top_lz);
	//back
	glNormal3f(0, 1, 0);
	glVertex3f(head_bottom_lx, y, head_bottom_lz);
	glVertex3f(mouth_x, y, mouth_z);
	glVertex3f(nose_x, y, nose_z);
	glVertex3f(eye_x, y, eye_z);
	glVertex3f(forhead_x, y, forhead_z);
	glVertex3f(head_top_lx, y, head_top_lz);
	//right
	glNormal3f(1, 0, 0);
	glVertex3f(mouth_x, -y, mouth_z);
	glVertex3f(mouth_x, y, mouth_z);
	glVertex3f(nose_x, y, nose_z);
	glVertex3f(eye_x, y, eye_z);
	glVertex3f(forhead_x, y, forhead_z);
	glVertex3f(forhead_x, -y, forhead_z);
	glVertex3f(eye_x, -y, eye_z);
	glVertex3f(nose_x, -y, nose_z);
	//left
	glNormal3f(-1, 0, 0);
	glVertex3f(head_top_lx, -y, head_top_lz);
	glVertex3f(head_top_lx, y, head_top_lz);
	glVertex3f(head_bottom_lx, y, head_bottom_lz);
	glVertex3f(head_bottom_lx, -y, head_bottom_lz);
	//top
	glNormal3f(0, 0, 1);
	glVertex3f(head_top_lx, -y, head_top_lz);
	glVertex3f(head_top_lx, y, head_top_lz);
	glVertex3f(forhead_x, y, forhead_z);
	glVertex3f(forhead_x, -y, forhead_z);
	//bottom
	glNormal3f(0, 0, -1);
	glVertex3f(head_bottom_lx, -y, head_bottom_lz);
	glVertex3f(head_bottom_lx, y, head_bottom_lz);
	glVertex3f(mouth_x, y, mouth_z);
	glVertex3f(mouth_x, -y, mouth_z);
	glEnd();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glColor3f((float)15/(float)256, (float)220/(float)256, (float)247/(float)256);
	glTranslated(0, 0, 5);
	gluCylinder(gluNewQuadric(), 5, 0, 1, 20, 10);
	
	glTranslated(0, 0, -.75);
	glColor3f((float)247/(float)256, (float)123/(float)256, (float)15/(float)256);
	gluCylinder(gluNewQuadric(), 5, 5, .75, 20, 10);


	

}

void Merry::Update(void)
{
	rotation += rotation_update;
}