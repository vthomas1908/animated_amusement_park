#include "Bridge.h"
#include "libtarga.h"
#include <math.h>
#include <iostream>
#include <GL/glu.h>
#include <stdio.h>

// Destructor
Bridge::~Bridge(void)
{
	
    if ( initialized )
    {
	glDeleteLists(display_list, 1);
	glDeleteTextures(1, &texture_obj);
    }
	
}


// Initializer. Returns false if something went wrong, like not being able to
// load the texture.
bool
Bridge::Initialize(void)
{
	
    initialized = true;

	float plankh = 1;
	float plankw = 2;
	float plankd = .5;
	float curr = 0;
	float deg = 45;

	bridge_list = glGenLists(1);
	glNewList(bridge_list, GL_COMPILE);
	glColor3f(0, 0, 0);
	glPushMatrix();
	glBegin(GL_QUADS);
	  for(int i = 0; i <=6; i++)
	  {
		  glTranslated(curr, 0, 0);
		  glRotated(deg, 0, 0, 1);

		  //bottom
		  glNormal3f(0, 0, -1);

		  glVertex3f(-plankw, -plankh, 0);
		  glVertex3f(plankw, -plankh, 0);
		  glVertex3f(plankw, plankh, 0);
		  glVertex3f(-plankw, plankh, 0);

		  //top
		  glNormal3f(0, 0, 1);
		  glVertex3f(-plankw, -plankh, plankd);
		  glVertex3f(plankw, -plankh, plankd);
		  glVertex3f(plankw, plankh, plankd);
		  glVertex3f(-plankw, plankh, plankd);

		  //left
		  glNormal3f(0, -1, 0);
		  glVertex3f(-plankw, plankh, plankd);
		  glVertex3f(-plankw, plankh, 0);
		  glVertex3f(-plankw, -plankh, 0);
		  glVertex3f(-plankw, -plankh, plankd);

		  //right
		  glNormal3f(0, 1, 0);
		  glVertex3f(plankw, plankh, plankd);
		  glVertex3f(plankw, plankh, 0);
		  glVertex3f(plankw, -plankh, 0);
		  glVertex3f(plankw, -plankh, plankd);

		  //front
		  glNormal3f(-1, 0, 0);
		  glVertex3f(-plankw, -plankh, plankd);
		  glVertex3f(-plankw, -plankh, 0);
		  glVertex3f(plankw, -plankh, 0);
		  glVertex3f(plankw, plankh, plankd);

		  //back
		  glNormal3f(1, 0, 0);
		  glVertex3f(-plankw, plankh, plankd);
		  glVertex3f(-plankw, plankh, 0);
		  glVertex3f(plankw, plankh, 0);
		  glVertex3f(plankw, plankh, plankd);

		  curr+= (2 * curr);
		  deg += 15;
	  }
	  glPopMatrix();
	  glEnd();
	  glEndList();

    return true;
}


// Draw just calls the display list we set up earlier.
void
Bridge::Draw(void)
{
	glPushMatrix();
	glCallList(bridge_list);
	glPopMatrix();
   
}