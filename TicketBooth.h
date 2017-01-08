#include <Fl/gl.h>
#include "libtarga.h"


class TicketBooth {
  private:
    GLubyte display_list;   // The display list that does all the work.
	GLubyte display_list2;
    GLuint  texture_obj;    // The object for the wood texture.
	GLuint  texture_ticket;
    bool    initialized;    // Whether or not we have been initialised.

  public:
    // Constructor. Can't do initialization here because we are
    // created before the OpenGL context is set up.
    TicketBooth(void) { display_list = 0; initialized = false; };

    // Destructor. Frees the display lists and texture object.
    ~TicketBooth(void);

    // Initializer. Creates the display list.
    bool    Initialize(void);

    // Does the drawing.
    void    Draw(void);

	bool    Resize(ubyte *data, int *height, int *width);
};