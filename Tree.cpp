#include "Tree.h"
#include "libtarga.h"
#include <math.h>
#include <iostream>
#include <GL/glu.h>
#include <stdio.h>

// Destructor
Tree::~Tree(void)
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
Tree::Initialize(void)
{
	
    initialized = true;

    return true;
}


// Draw just calls the display list we set up earlier.
void
Tree::Draw(float n)
{
    glPushMatrix();

	glColor3f((float)145/(float)256, (float)69/(float)256, (float)15/(float)256);
	gluCylinder(gluNewQuadric(), .5*n, .5*n, 4*n, 4*n, 2*n);

	glTranslated(0, 0, 2*n);
	glColor3f(0, 1, 0);
	gluCylinder(gluNewQuadric(), 3*n, 0, 4*n, 4*n, 2*n);

	glTranslated(0, 0, 2*n);
	glColor3f(0, 1, 0);
	gluCylinder(gluNewQuadric(), 2*n, 0, 3*n, 4*n, 2*n);

	glTranslated(0, 0, 2*n);
	glColor3f(0, 1, 0);
	gluCylinder(gluNewQuadric(), 1*n, 0, 2*n, 4*n, 2*n);

    glPopMatrix();
}