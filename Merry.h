#include <Fl/gl.h>
#include "libtarga.h"



class Merry {
  private:
    GLubyte display_list;   // The display list that does all the work.
    bool    initialized;    // Whether or not we have been initialised.

	float rotation;
	float rotation_update;


  public:
    // Constructor. Can't do initialization here because we are
    // created before the OpenGL context is set up.
    Merry(void) { display_list = 0; initialized = false; };

    // Destructor. Frees the display lists and texture object.
    ~Merry(void);

    // Initializer. Creates the display list.
    bool    Initialize(void);

    // Does the drawing.
    void    Draw(void);

	void Update(void);
};