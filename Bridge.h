#include <Fl/gl.h>
#include "libtarga.h"



class Bridge {
  private:
    GLubyte display_list;   // The display list that does all the work.
	GLubyte bridge_list;
    GLuint  texture_obj;    // The object for the texture.
    bool    initialized;    // Whether or not we have been initialised.


  public:
    // Constructor. Can't do initialization here because we are
    // created before the OpenGL context is set up.
    Bridge(void) { display_list = 0; initialized = false; };

    // Destructor. Frees the display lists and texture object.
    ~Bridge(void);

    // Initializer. Creates the display list.
    bool    Initialize(void);

    // Does the drawing.
    void    Draw(void);
};