#include <Fl/gl.h>
#include "libtarga.h"


class Sign {
  private:
    GLubyte display_list;   // The display list that does all the work.
    GLuint  texture_obj;    // The object for the wood texture.
	GLubyte display_list2;   // The display list that does all the work.
    GLuint  texture_obj2;    // The object for the wood texture.
    bool    initialized;    // Whether or not we have been initialised.
	float rotation;

  public:
    // Constructor. Can't do initialization here because we are
    // created before the OpenGL context is set up.
    Sign(void) { display_list = 0; initialized = false; };

    // Destructor. Frees the display lists and texture object.
    ~Sign(void);

    // Initializer. Creates the display list.
    bool    Initialize(void);

    // Does the drawing.
    void    Draw(void);

	bool    Resize(ubyte *data, int *height, int *width);

	void Update();
};

