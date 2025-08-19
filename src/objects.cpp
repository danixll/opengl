#include "glad/glad.h"
#include "objects.h"

Cube::Cube() {
	std::vector<float> vertices = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f
	};
	std::vector<unsigned int> indices = {
		0, 1, 2,
		2, 3, 0
	};

	defaultShader = new Shader("./assets/shaders/default.vert", "./assets/shaders/default.frag");
	Buffers = new ObjectBuffer(vertices, indices);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	Buffers->unbind();
}

void Cube::draw() {
	defaultShader->use();
	Buffers->bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}