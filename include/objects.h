#include "shader.h"

class Cube {
private:
	unsigned int VBO, VAO, EBO;
	Shader* defaultShader;
public:
	Cube();
	void draw();
};