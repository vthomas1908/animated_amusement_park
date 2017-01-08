
#include "TicketBooth.h"
#include "libtarga.h"
#include <math.h>
#include <iostream>
#include <GL/glu.h>
#include <stdio.h>

// Destructor
TicketBooth::~TicketBooth(void)
{
	
    if ( initialized )
    {
	glDeleteLists(display_list, 1);
	glDeleteLists(display_list2, 1);
	glDeleteTextures(1, &texture_obj);
	glDeleteTextures(1, &texture_ticket);
    }
	
}


// Initializer. Returns false if something went wrong, like not being able to
// load the texture.
bool
TicketBooth::Initialize(void)
{
	
    ubyte   *image_data;
    int	    image_height, image_width;

    // Load the image for the texture. The texture file has to be in
    // a place where it will be found.
    if ( ! ( image_data = (ubyte*)tga_load("woodgrain.tga", &image_width,
					   &image_height, TGA_TRUECOLOR_24) ) )
    {
	fprintf(stderr, "TicketBooth::Initialize: Couldn't load woodgrain.tga\n");
	return false;
    }

	
    // This creates a texture object and binds it, so the next few operations
    // apply to this texture.
    glGenTextures(1, &texture_obj);
    glBindTexture(GL_TEXTURE_2D, texture_obj);

    // This sets a parameter for how the texture is loaded and interpreted.
    // basically, it says that the data is packed tightly in the image array.
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // This sets up the texture with high quality filtering. First it builds
    // mipmaps from the image data, then it sets the filtering parameters
    // and the wrapping parameters. We want the grass to be repeated over the
    // ground.
    gluBuild2DMipmaps(GL_TEXTURE_2D,3, image_width, image_height, 
		      GL_RGB, GL_UNSIGNED_BYTE, image_data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		    GL_NEAREST_MIPMAP_LINEAR);

    // This says what to do with the texture. Modulate will multiply the
    // texture by the underlying color.
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 

    // Now do the geometry for each of the 6 sides of the main ticket booth
	
	//Create the display list.
    display_list = glGenLists(1);
    glNewList(display_list, GL_COMPILE);

	// Turn on texturing and bind the wood texture.
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture_obj);





	glBegin(GL_QUADS);
	//Bottom
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is down for bottom.
	glNormal3f(0.0, 0.0, -1.0);
	// vertex/texture coordinates.
	glVertex3f(-2, -2, .0); 
	glVertex3f(2, -2, .0); 
	glVertex3f(2, 2, .0); 
	glVertex3f(-2, 2, .0); 

	//Top
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is up for the top.
	glNormal3f(0.0, 0.0, 1.0);
	// vertex/texture coordinates.
	glTexCoord2f(0, 1);  glVertex3f(-2, 2, 5); 
	glTexCoord2f(0, 0);  glVertex3f(-2, -2, 5); 
	glTexCoord2f(1, 0);  glVertex3f(2, -2, 5);
	glTexCoord2f(1, 1);  glVertex3f(2, 2, 5); 

	
	//Front one
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is in.
	glNormal3f(0.0, -1.0, 0.0);
	// vertex/texture coordinates.
	glTexCoord2f(0, 0); glVertex3f(-2, -2, 0.0); 
	glTexCoord2f(.25, 0); glVertex3f(-1, -2, 0.0); 
	glTexCoord2f(.25, 1); glVertex3f(-1, -2, 5); 
	glTexCoord2f(0, 1); glVertex3f(-2, -2, 5); 

	//Front two
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is in.
	glNormal3f(0.0, -1.0, 0.0);
	// vertex/texture coordinates.
	glTexCoord2f(.75, 0); glVertex3f(1, -2, 0.0); 
	glTexCoord2f(1, 0); glVertex3f(2, -2, 0.0); 
	glTexCoord2f(1, 1); glVertex3f(2, -2, 5); 
	glTexCoord2f(.75, 1); glVertex3f(1, -2, 5); 

	//Front three
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is in.
	glNormal3f(0.0, -1.0, 0.0);
	// vertex/texture coordinates.
	glTexCoord2f(.25, .5); glVertex3f(-1, -2, 2); 
	glTexCoord2f(.75, .5); glVertex3f(1, -2, 2); 
	glTexCoord2f(.75, 1); glVertex3f(1, -2, 5); 
	glTexCoord2f(.25, 1); glVertex3f(-1, -2, 5); 



	//Back
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is out.
	glNormal3f(0.0, 1.0, 0.0);
	// vertex/texture coordinates.
	glTexCoord2f(0, 0); glVertex3f(-2, 2, 0.0); 
	glTexCoord2f(0, 1); glVertex3f(-2, 2, 5); 
	glTexCoord2f(1, 1); glVertex3f(2, 2, 5);
	glTexCoord2f(1, 0); glVertex3f(2, 2, 0.0); 

	//Left
    glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is left.
	glNormal3f(-1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	glTexCoord2f(0, 0); glVertex3f(-2, 2, 0.0); 
	glTexCoord2f(1, 0); glVertex3f(-2, -2, 0.0); 
	glTexCoord2f(1, 1); glVertex3f(-2, -2, 5); 
	glTexCoord2f(0, 1); glVertex3f(-2, 2, 5); 

	//Right
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is right.
	glNormal3f(1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	glTexCoord2f(1, 1); glVertex3f(2, 2, 5); 
	glTexCoord2f(0, 1); glVertex3f(2, -2, 5); 
	glTexCoord2f(0, 0); glVertex3f(2, -2, 0.0); 
	glTexCoord2f(1, 0); glVertex3f(2, 2, 0.0); 

	glEnd();
	
	// Turn texturing off again, because we don't want everything else to
	// be textured.
	glDisable(GL_TEXTURE_2D);
    glEndList();
	






/*




	glBegin(GL_QUADS);
	//Bottom
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is down for bottom.
	glNormal3f(0.0, 0.0, -1.0);
	// vertex/texture coordinates.
	glTexCoord2f(0, 1); glVertex3f(-40.0, -30.0, .0); 
	glTexCoord2f(1, 1); glVertex3f(-30.0, -30.0, .0); 
	glTexCoord2f(1, 0); glVertex3f(-30.0, -40.0, .0); 
	glTexCoord2f(0, 0); glVertex3f(-40.0, -40.0, .0); 

	//Top
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is up for the top.
	glNormal3f(0.0, 0.0, 1.0);
	// vertex/texture coordinates.
	glTexCoord2f(0, 1);  glVertex3f(-40.0, -30.0, 10.0); 
	glTexCoord2f(0, 0);  glVertex3f(-40.0, -40.0, 10.0); 
	glTexCoord2f(1, 0);  glVertex3f(-30.0, -40.0, 10.0);
	glTexCoord2f(1, 1);  glVertex3f(-30.0, -30.0, 10.0); 

	//Front
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is in.
	glNormal3f(0.0, -1.0, 0.0);
	// vertex/texture coordinates.
	glTexCoord2f(0, 0); glVertex3f(-40.0, -40.0, 0.0); 
	glTexCoord2f(1, 0); glVertex3f(-30.0, -40.0, 0.0); 
	glTexCoord2f(1, 1); glVertex3f(-30.0, -40.0, 10.0); 
	glTexCoord2f(0, 1); glVertex3f(-40.0, -40.0, 10.0); 

	//Back
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is out.
	glNormal3f(0.0, 1.0, 0.0);
	// vertex/texture coordinates.
	glTexCoord2f(0, 0); glVertex3f(-40.0, -30.0, 0.0); 
	glTexCoord2f(0, 1); glVertex3f(-40.0, -30.0, 10.0); 
	glTexCoord2f(1, 1); glVertex3f(-30.0, -30.0, 10.0);
	glTexCoord2f(1, 0); glVertex3f(-30.0, -30.0, 0.0); 

	//Left
    glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is left.
	glNormal3f(-1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	glTexCoord2f(0, 0); glVertex3f(-40.0, -30.0, 0.0); 
	glTexCoord2f(1, 0); glVertex3f(-40.0, -40.0, 0.0); 
	glTexCoord2f(1, 1); glVertex3f(-40.0, -40.0, 10.0); 
	glTexCoord2f(0, 1); glVertex3f(-40.0, -30.0, 10.0); 

	//Right
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is right.
	glNormal3f(1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	glTexCoord2f(1, 1); glVertex3f(-30.0, -30.0, 10.0); 
	glTexCoord2f(0, 1); glVertex3f(-30.0, -40.0, 10.0); 
	glTexCoord2f(0, 0); glVertex3f(-30.0, -40.0, 0.0); 
	glTexCoord2f(1, 0); glVertex3f(-30.0, -30.0, 0.0); 

	glEnd();
	
	// Turn texturing off again, because we don't want everything else to
	// be textured.
	glDisable(GL_TEXTURE_2D);
    glEndList();
	*/
//new texture
	    // Load the image for the texture. The texture file has to be in
    // a place where it will be found.
    if ( ! ( image_data = (ubyte*)tga_load("ticket.tga", &image_width,
					   &image_height, TGA_TRUECOLOR_24) ) )
    {
	fprintf(stderr, "TicketBooth::Initialize: Couldn't load ticket.tga\n");
	return false;
    }

	
    // This creates a texture object and binds it, so the next few operations
    // apply to this texture.
    glGenTextures(1, &texture_ticket);
    glBindTexture(GL_TEXTURE_2D, texture_ticket);

    // This sets a parameter for how the texture is loaded and interpreted.
    // basically, it says that the data is packed tightly in the image array.
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // This sets up the texture with high quality filtering. First it builds
    // mipmaps from the image data, then it sets the filtering parameters
    // and the wrapping parameters. We want the grass to be repeated over the
    // ground.
    gluBuild2DMipmaps(GL_TEXTURE_2D,3, image_width, image_height, 
		      GL_RGB, GL_UNSIGNED_BYTE, image_data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		    GL_NEAREST_MIPMAP_LINEAR);

    // This says what to do with the texture. Modulate will multiply the
    // texture by the underlying color.
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 

    // Now do the geometry for each of the 6 sides of the main ticket booth
	
	//Create the display list.
    display_list2 = glGenLists(1);
    glNewList(display_list2, GL_COMPILE);

	// Turn on texturing and bind the wood texture.
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture_ticket);

	glPushMatrix();
	glRotated(90, 0, 0, 1);

	glBegin(GL_QUADS);
	//Bottom
	glColor3f(0, 0, 0);//texture supplies color
	// The surface normal is down for bottom.
	glNormal3f(0.0, 0.0, -1.0);
	// vertex/texture coordinates.
	glVertex3f(.5, -4, 6); 
	glVertex3f(-.5, -4, 6); 
	glVertex3f(-.5, 4, 6); 
	glVertex3f(.5, 4, 6); 

	//Top
	glColor3f(0, 0, 0);//texture supplies color
	// The surface normal is up for the top.
	glNormal3f(0.0, 0.0, 1.0);
	// vertex/texture coordinates.
	glVertex3f(.5, -4, 10); 
	glVertex3f(-.5, -4, 10); 
	glVertex3f(-.5, 4, 10); 
	glVertex3f(.5, 4, 10); 

	//Front
	glColor3f(0, 0, 0);//texture supplies color
	// The surface normal is in.
	glNormal3f(0.0, -1.0, 0.0);
	// vertex/texture coordinates.
	glVertex3f(.5, -4, 6); 
	glVertex3f(-.5, -4, 6); 
	glVertex3f(-.5, -4, 10); 
	glVertex3f(.5, -4, 10); 

	//Back
	glColor3f(0, 0, 0);//texture supplies color
	// The surface normal is out.
	glNormal3f(0.0, 1.0, 0.0);
	// vertex/texture coordinates.
	glVertex3f(.5, 4, 6); 
	glVertex3f(-.5, 4, 6); 
	glVertex3f(-.5, 4, 10); 
	glVertex3f(.5, 4, 10);  

	//Left
    glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is left.
	glNormal3f(-1.0, 0.0, 0.0);
	// vertex/texture coordinates.
	glTexCoord2f(0, 0); glVertex3f(-.5, 4, 6); 
	glTexCoord2f(1, 0); glVertex3f(-.5, -4, 6); 
	glTexCoord2f(1, 1); glVertex3f(-.5, -4, 10); 
	glTexCoord2f(0, 1); glVertex3f(-.5, 4, 10); 

	//Right
	glColor3f(1.0, 1.0, 1.0);//texture supplies color
	// The surface normal is right.
	glNormal3f(1.0, 1.0, 1.0);
	// vertex/texture coordinates.
	glTexCoord2f(1, 1); glVertex3f(.5, 4, 10); 
	glTexCoord2f(0, 1); glVertex3f(.5, -4, 10); 
	glTexCoord2f(0, 0); glVertex3f(.5, -4, 6); 
	glTexCoord2f(1, 0); glVertex3f(.5, 4, 6); 

	glEnd();

	glPopMatrix();
	
	// Turn texturing off again, because we don't want everything else to
	// be textured.
	glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslated(0, 0, 5);
	gluCylinder(gluNewQuadric(), .5, .5, 1, 5, 5);
	glPopMatrix();
    glEndList();
//end new texture
	
	

    // We only do all this stuff once, when the GL context is first set up.
    initialized = true;

    return true;
}


// Draw just calls the display list we set up earlier.
void
TicketBooth::Draw(void)
{
    glPushMatrix();
    glCallList(display_list);
	glCallList(display_list2);
    glPopMatrix();
}

bool TicketBooth::Resize(ubyte *data, int *height, int *width)
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
	


