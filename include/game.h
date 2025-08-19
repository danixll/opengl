#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Game {
private:
	GLFWmonitor* monitor;
	const GLFWvidmode* mode;
	GLFWwindow* window;
public:
	Game();
	void run();
	~Game();
};