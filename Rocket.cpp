
#include "Rocket.h"
#include "libtarga.h"
#include <math.h>
#include <iostream>
#include <GL/glu.h>
#include <stdio.h>

/*// Destructor
Rocket::~Rocket(void)
{

}
*/

// Initializer. Returns false if something went wrong, like not being able to
// load the texture.
bool
Rocket::Initialize(float up, float down)
{

	shoot = 0;
	shoot_up = up;
	shoot_down = down;
	up = true;

	
   
    // We only do all this stuff once, when the GL context is first set up.
    initialized = true;

    return true;
}


// Draw just calls the display list we set up earlier.
void
Rocket::Draw(void)
{
	float wide = 1;
	float high = .5;
	float deep = .25;

	 glColor3f(1, 0, 0);
	 gluCylinder(gluNewQuadric(), 1, 1, 20, 10, 10);

	 glPushMatrix();
	 glTranslated(0, 0, .01);
	 glColor3f(0, 0, 1);
	 gluDisk(gluNewQuadric(), 1.5, 5, 20, 10);
	 glPopMatrix();

	 glTranslatef(0, 0, shoot);
	 
	 glPushMatrix();
	 glTranslated(0, 1, 0);
	 glBegin(GL_QUADS);

	 //back of seat
	 //front
	 glColor3f(0, 0, 1);
	 glNormal3f(0, -1, 0);
	 glVertex3f(-wide, -deep, 0); 
	 glVertex3f(wide, -deep, 0); 
	 glVertex3f(wide, -deep, 2*high); 
	 glVertex3f(-wide, -deep, 2*high); 
	 
	//Back
	glColor3f(0, 0, 1);//texture supplies color
	// The surface normal is out.
	glNormal3f(0.0, 1.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, deep, 0.0); 
	 glVertex3f(-wide, deep, 2*high); 
	 glVertex3f(wide, deep, 2*high);
	 glVertex3f(wide, deep, 0.0); 

	//Left
    glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is left.
	glNormal3f(-1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, deep, 0.0); 
	 glVertex3f(-wide, -deep, 0.0); 
	 glVertex3f(-wide, -deep, 2*high); 
	 glVertex3f(-wide, deep, 2*high); 

	//Right
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is right.
	glNormal3f(1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(wide, deep, 2*high); 
	 glVertex3f(wide, -deep, 2*high); 
	 glVertex3f(wide, -deep, 0.0); 
	 glVertex3f(wide, deep, 0.0); 

	//Bottom
	glColor3f(0, 0, 1.0);//texture supplies color
	// The surface normal is down for bottom.
	glNormal3f(0.0, 0.0, -1.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, -deep, .0); 
	 glVertex3f(wide, -deep, .0); 
	 glVertex3f(wide, deep, .0); 
	 glVertex3f(-wide, deep, .0); 

	//Top
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is up for the top.
	glNormal3f(0.0, 0.0, 1.0);
	// vertex/texture coordinates.
	  glVertex3f(-wide, deep, 2*high); 
	  glVertex3f(-wide, -deep, 2*high); 
	  glVertex3f(wide, -deep, 2*high);
	  glVertex3f(wide, deep, 2*high); 

	glEnd();

//seat bottom
	glRotated(-90, 1, 0, 0);
	glBegin(GL_QUADS);
	//front
	 glColor3f(0, 0, 1);
	 glNormal3f(0, -1, 0);
	 glVertex3f(-wide, -deep, 0); 
	 glVertex3f(wide, -deep, 0); 
	 glVertex3f(wide, -deep, 2*high); 
	 glVertex3f(-wide, -deep, 2*high); 
	 
	//Back
	glColor3f(0, 0, 1.0);//texture supplies color
	// The surface normal is out.
	glNormal3f(0.0, 1.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, deep, 0.0); 
	 glVertex3f(-wide, deep, 2*high); 
	 glVertex3f(wide, deep, 2*high);
	 glVertex3f(wide, deep, 0.0); 

	//Left
    glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is left.
	glNormal3f(-1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, deep, 0.0); 
	 glVertex3f(-wide, -deep, 0.0); 
	 glVertex3f(-wide, -deep, 2*high); 
	 glVertex3f(-wide, deep, 2*high); 

	//Right
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is right.
	glNormal3f(1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(wide, deep, 2*high); 
	 glVertex3f(wide, -deep, 2*high); 
	 glVertex3f(wide, -deep, 0.0); 
	 glVertex3f(wide, deep, 0.0); 

	//Bottom
	glColor3f(1, 1, 1.0);//texture supplies color
	// The surface normal is down for bottom.
	glNormal3f(0.0, 0.0, -1.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, -deep, .0); 
	 glVertex3f(wide, -deep, .0); 
	 glVertex3f(wide, deep, .0); 
	 glVertex3f(-wide, deep, .0); 

	//Top
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is up for the top.
	glNormal3f(0.0, 0.0, 1.0);
	// vertex/texture coordinates.
	  glVertex3f(-wide, deep, 2*high); 
	  glVertex3f(-wide, -deep, 2*high); 
	  glVertex3f(wide, -deep, 2*high);
	  glVertex3f(wide, deep, 2*high); 

	glEnd();
//end


	glPopMatrix();

	glRotated(90, 0, 0, 1);
	glPushMatrix();
	glTranslated(0, 1, 0);
	glBegin(GL_QUADS);
	//back of seat
	 //front
	 glColor3f(0, 0, 1);
	 glNormal3f(0, -1, 0);
	 glVertex3f(-wide, -deep, 0); 
	 glVertex3f(wide, -deep, 0); 
	 glVertex3f(wide, -deep, 2*high); 
	 glVertex3f(-wide, -deep, 2*high); 
	 
	//Back
	glColor3f(0, 0, 1.0);//texture supplies color
	// The surface normal is out.
	glNormal3f(0.0, 1.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, deep, 0.0); 
	 glVertex3f(-wide, deep, 2*high); 
	 glVertex3f(wide, deep, 2*high);
	 glVertex3f(wide, deep, 0.0); 

	//Left
    glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is left.
	glNormal3f(-1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, deep, 0.0); 
	 glVertex3f(-wide, -deep, 0.0); 
	 glVertex3f(-wide, -deep, 2*high); 
	 glVertex3f(-wide, deep, 2*high); 

	//Right
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is right.
	glNormal3f(1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(wide, deep, 2*high); 
	 glVertex3f(wide, -deep, 2*high); 
	 glVertex3f(wide, -deep, 0.0); 
	 glVertex3f(wide, deep, 0.0); 

	//Bottom
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is down for bottom.
	glNormal3f(0.0, 0.0, -1.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, -deep, .0); 
	 glVertex3f(wide, -deep, .0); 
	 glVertex3f(wide, deep, .0); 
	 glVertex3f(-wide, deep, .0); 

	//Top
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is up for the top.
	glNormal3f(0.0, 0.0, 1.0);
	// vertex/texture coordinates.
	  glVertex3f(-wide, deep, 2*high); 
	  glVertex3f(-wide, -deep, 2*high); 
	  glVertex3f(wide, -deep, 2*high);
	  glVertex3f(wide, deep, 2*high); 

	glEnd();

//seat bottom
	glRotated(-90, 1, 0, 0);
	glBegin(GL_QUADS);
	//front
	 glColor3f(0, 0, 1);
	 glNormal3f(0, -1, 0);
	 glVertex3f(-wide, -deep, 0); 
	 glVertex3f(wide, -deep, 0); 
	 glVertex3f(wide, -deep, 2*high); 
	 glVertex3f(-wide, -deep, 2*high); 
	 
	//Back
	glColor3f(0, 0, 1.0);//texture supplies color
	// The surface normal is out.
	glNormal3f(0.0, 1.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, deep, 0.0); 
	 glVertex3f(-wide, deep, 2*high); 
	 glVertex3f(wide, deep, 2*high);
	 glVertex3f(wide, deep, 0.0); 

	//Left
    glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is left.
	glNormal3f(-1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, deep, 0.0); 
	 glVertex3f(-wide, -deep, 0.0); 
	 glVertex3f(-wide, -deep, 2*high); 
	 glVertex3f(-wide, deep, 2*high); 

	//Right
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is right.
	glNormal3f(1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(wide, deep, 2*high); 
	 glVertex3f(wide, -deep, 2*high); 
	 glVertex3f(wide, -deep, 0.0); 
	 glVertex3f(wide, deep, 0.0); 

	//Bottom
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is down for bottom.
	glNormal3f(0.0, 0.0, -1.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, -deep, .0); 
	 glVertex3f(wide, -deep, .0); 
	 glVertex3f(wide, deep, .0); 
	 glVertex3f(-wide, deep, .0); 

	//Top
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is up for the top.
	glNormal3f(0.0, 0.0, 1.0);
	// vertex/texture coordinates.
	  glVertex3f(-wide, deep, 2*high); 
	  glVertex3f(-wide, -deep, 2*high); 
	  glVertex3f(wide, -deep, 2*high);
	  glVertex3f(wide, deep, 2*high); 

	glEnd();
//end
	glPopMatrix();

	glRotated(90, 0, 0, 1);
	glPushMatrix();
	glTranslated(0, 1, 0);
	glBegin(GL_QUADS);
	//back of seat
	 //front
	 glColor3f(0, 0, 1);
	 glNormal3f(0, -1, 0);
	 glVertex3f(-wide, -deep, 0); 
	 glVertex3f(wide, -deep, 0); 
	 glVertex3f(wide, -deep, 2*high); 
	 glVertex3f(-wide, -deep, 2*high); 
	 
	//Back
	glColor3f(0, 0, 1.0);//texture supplies color
	// The surface normal is out.
	glNormal3f(0.0, 1.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, deep, 0.0); 
	 glVertex3f(-wide, deep, 2*high); 
	 glVertex3f(wide, deep, 2*high);
	 glVertex3f(wide, deep, 0.0); 

	//Left
    glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is left.
	glNormal3f(-1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, deep, 0.0); 
	 glVertex3f(-wide, -deep, 0.0); 
	 glVertex3f(-wide, -deep, 2*high); 
	 glVertex3f(-wide, deep, 2*high); 

	//Right
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is right.
	glNormal3f(1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(wide, deep, 2*high); 
	 glVertex3f(wide, -deep, 2*high); 
	 glVertex3f(wide, -deep, 0.0); 
	 glVertex3f(wide, deep, 0.0); 

	//Bottom
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is down for bottom.
	glNormal3f(0.0, 0.0, -1.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, -deep, .0); 
	 glVertex3f(wide, -deep, .0); 
	 glVertex3f(wide, deep, .0); 
	 glVertex3f(-wide, deep, .0); 

	//Top
	glColor3f(1, 1, 1.0);//texture supplies color
	// The surface normal is up for the top.
	glNormal3f(0.0, 0.0, 1.0);
	// vertex/texture coordinates.
	  glVertex3f(-wide, deep, 2*high); 
	  glVertex3f(-wide, -deep, 2*high); 
	  glVertex3f(wide, -deep, 2*high);
	  glVertex3f(wide, deep, 2*high); 

	glEnd();

//seat bottom
	glRotated(-90, 1, 0, 0);
	glBegin(GL_QUADS);
	//front
	 glColor3f(0, 0, 1);
	 glNormal3f(0, -1, 0);
	 glVertex3f(-wide, -deep, 0); 
	 glVertex3f(wide, -deep, 0); 
	 glVertex3f(wide, -deep, 2*high); 
	 glVertex3f(-wide, -deep, 2*high); 
	 
	//Back
	glColor3f(0, 0, 1.0);//texture supplies color
	// The surface normal is out.
	glNormal3f(0.0, 1.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, deep, 0.0); 
	 glVertex3f(-wide, deep, 2*high); 
	 glVertex3f(wide, deep, 2*high);
	 glVertex3f(wide, deep, 0.0); 

	//Left
    glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is left.
	glNormal3f(-1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, deep, 0.0); 
	 glVertex3f(-wide, -deep, 0.0); 
	 glVertex3f(-wide, -deep, 2*high); 
	 glVertex3f(-wide, deep, 2*high); 

	//Right
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is right.
	glNormal3f(1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(wide, deep, 2*high); 
	 glVertex3f(wide, -deep, 2*high); 
	 glVertex3f(wide, -deep, 0.0); 
	 glVertex3f(wide, deep, 0.0); 

	//Bottom
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is down for bottom.
	glNormal3f(0.0, 0.0, -1.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, -deep, .0); 
	 glVertex3f(wide, -deep, .0); 
	 glVertex3f(wide, deep, .0); 
	 glVertex3f(-wide, deep, .0); 

	//Top
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is up for the top.
	glNormal3f(0.0, 0.0, 1.0);
	// vertex/texture coordinates.
	  glVertex3f(-wide, deep, 2*high); 
	  glVertex3f(-wide, -deep, 2*high); 
	  glVertex3f(wide, -deep, 2*high);
	  glVertex3f(wide, deep, 2*high); 

	glEnd();
//end
	glPopMatrix();

	glRotated(90, 0, 0, 1);
	glPushMatrix();
	glTranslated(0, 1, 0);
	glBegin(GL_QUADS);
	//back of seat
	 //front
	 glColor3f(0, 0, 1);
	 glNormal3f(0, -1, 0);
	 glVertex3f(-wide, -deep, 0); 
	 glVertex3f(wide, -deep, 0); 
	 glVertex3f(wide, -deep, 2*high); 
	 glVertex3f(-wide, -deep, 2*high); 
	 
	//Back
	glColor3f(0, 0, 1.0);//texture supplies color
	// The surface normal is out.
	glNormal3f(0.0, 1.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, deep, 0.0); 
	 glVertex3f(-wide, deep, 2*high); 
	 glVertex3f(wide, deep, 2*high);
	 glVertex3f(wide, deep, 0.0); 

	//Left
    glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is left.
	glNormal3f(-1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, deep, 0.0); 
	 glVertex3f(-wide, -deep, 0.0); 
	 glVertex3f(-wide, -deep, 2*high); 
	 glVertex3f(-wide, deep, 2*high); 

	//Right
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is right.
	glNormal3f(1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(wide, deep, 2*high); 
	 glVertex3f(wide, -deep, 2*high); 
	 glVertex3f(wide, -deep, 0.0); 
	 glVertex3f(wide, deep, 0.0); 

	//Bottom
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is down for bottom.
	glNormal3f(0.0, 0.0, -1.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, -deep, .0); 
	 glVertex3f(wide, -deep, .0); 
	 glVertex3f(wide, deep, .0); 
	 glVertex3f(-wide, deep, .0); 

	//Top
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is up for the top.
	glNormal3f(0.0, 0.0, 1.0);
	// vertex/texture coordinates.
	  glVertex3f(-wide, deep, 2*high); 
	  glVertex3f(-wide, -deep, 2*high); 
	  glVertex3f(wide, -deep, 2*high);
	  glVertex3f(wide, deep, 2*high); 

	glEnd();

	//seat bottom
	glRotated(-90, 1, 0, 0);
	glBegin(GL_QUADS);
	//front
	 glColor3f(0, 0, 1);
	 glNormal3f(0, -1, 0);
	 glVertex3f(-wide, -deep, 0); 
	 glVertex3f(wide, -deep, 0); 
	 glVertex3f(wide, -deep, 2*high); 
	 glVertex3f(-wide, -deep, 2*high); 
	 
	//Back
	glColor3f(0, 0, 1.0);//texture supplies color
	// The surface normal is out.
	glNormal3f(0.0, 1.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, deep, 0.0); 
	 glVertex3f(-wide, deep, 2*high); 
	 glVertex3f(wide, deep, 2*high);
	 glVertex3f(wide, deep, 0.0); 

	//Left
    glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is left.
	glNormal3f(-1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, deep, 0.0); 
	 glVertex3f(-wide, -deep, 0.0); 
	 glVertex3f(-wide, -deep, 2*high); 
	 glVertex3f(-wide, deep, 2*high); 

	//Right
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is right.
	glNormal3f(1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	 glVertex3f(wide, deep, 2*high); 
	 glVertex3f(wide, -deep, 2*high); 
	 glVertex3f(wide, -deep, 0.0); 
	 glVertex3f(wide, deep, 0.0); 

	//Bottom
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is down for bottom.
	glNormal3f(0.0, 0.0, -1.0);
	// vertex/texture coordinates.
	 glVertex3f(-wide, -deep, .0); 
	 glVertex3f(wide, -deep, .0); 
	 glVertex3f(wide, deep, .0); 
	 glVertex3f(-wide, deep, .0); 

	//Top
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is up for the top.
	glNormal3f(0.0, 0.0, 1.0);
	// vertex/texture coordinates.
	  glVertex3f(-wide, deep, 2*high); 
	  glVertex3f(-wide, -deep, 2*high); 
	  glVertex3f(wide, -deep, 2*high);
	  glVertex3f(wide, deep, 2*high); 

	glEnd();
//end
	glPopMatrix();

	
	
}

bool Rocket::Resize(ubyte *data, int *height, int *width)
{
	int newWidth = pow(2.0, (int)ceil(log((float)*width)/log(2.f)));
	int newHeight = pow(2.0, (int)ceil(log((float)*width)/log(2.f)));

	newWidth = max(64, newWidth);
	newHeight = max(64, newHeight);

	if (newWidth != *width && newHeight != *height)
	{
		unsigned char* scaledData = new unsigned char[newWidth * newHeight * 4];
		if (gluScaleImage(GL_RGBA, *width, *height, GL_UNSIGNED_BYTE, data, newWidth, newHeight, GL_UNSIGNED_BYTE, scaledData) != 0)
		{
			delete[] scaledData;
			return false;
		}//if

		delete data;
		data = scaledData;
		*width = newWidth;
		*height = newHeight;
	}//if
	return true;
}

void Rocket::Update()
{
	if (up)
	{
		shoot += shoot_up;
		if(shoot >= 18)
			up = false;
	}
	else
	{
		shoot -= shoot_down;
		if(shoot <=2)
			up = true;
	}
}
	


