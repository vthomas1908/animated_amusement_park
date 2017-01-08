#include <Fl/gl.h>
#include "libtarga.h"


class Rocket{
  private:

    bool    initialized;    // Whether or not we have been initialised.
	float shoot;
	float shoot_up, shoot_down;
	bool up;

  public:
    // Constructor. Can't do initialization here because we are
    // created before the OpenGL context is set up.
    Rocket(void) {initialized = false;};

    // Destructor. Frees the display lists and texture object.
//    ~Rocket(void);

    // Initializer. Creates the display list.
    bool    Initialize(float up, float down);

    // Does the drawing.
    void    Draw(void);

	bool    Resize(ubyte *data, int *height, int *width);

	void Update();
};