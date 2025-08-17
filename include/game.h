#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Game {
public:
	GLFWmonitor* monitor;
	const GLFWvidmode* mode;
	GLFWwindow* window;

	Game();
	void run();
	~Game();
};