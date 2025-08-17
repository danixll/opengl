#include "game.h"

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