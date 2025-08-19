#include "rendering.h"

class Cube {
private:
	Shader* defaultShader;
	ObjectBuffer* Buffers;
public:
	Cube();
	void draw();
};