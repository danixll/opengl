#include "game.h"

void processInput(GLFWwindow* window);

Game::Game() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	monitor = glfwGetPrimaryMonitor();
	mode = glfwGetVideoMode(monitor);
	window = glfwCreateWindow(mode->width, mode->height, "OpenGL Game", monitor, nullptr);
	if (!window) {
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		glfwDestroyWindow(window);
		glfwTerminate();
	}
	glViewport(0, 0, mode->width, mode->height);
}

void Game::run() {
	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		glClearColor(0.25f, 0.33f, 0.37f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

Game::~Game() {
	if (window) {
		glfwDestroyWindow(window);
	}
	glfwTerminate();
}