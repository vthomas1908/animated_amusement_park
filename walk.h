#include <Fl/gl.h>
#include "libtarga.h"


class Walk {
  private:
    GLubyte display_list;   // The display list that does all the work.
	GLuint  texture_obj;
    bool    initialized;    // Whether or not we have been initialised.

  public:
    // Constructor. Can't do initialization here because we are
    // created before the OpenGL context is set up.
    Walk(void) { display_list = 0; initialized = false; };

    // Destructor. Frees the display lists and texture object.
    ~Walk(void);

    // Initializer. Creates the display list.
    bool    Initialize(void);

    // Does the drawing.
    void    Draw(void);

	bool    Resize(ubyte *data, int *height, int *width);
};