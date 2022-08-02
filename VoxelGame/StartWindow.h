#pragma once

#include "libs.h"

void myKeyCallback(GLFWwindow* window, int key, int scacode, int action, int mods) {
	if (key == GLFW_KEY_E && action == GLFW_PRESS)
		printf("You pressed the E key!\n");
}

int startWindow() {
	if (!glfwInit()) {
		printf("Failed to initialize GLFW");
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	const int windowWidth = 1280;
	const int windowHeight = 720;
	const char* windowTitle = "MelonCraft";
	GLFWwindow* window = glfwCreateWindow(
		windowWidth,
		windowHeight,
		windowTitle,
		nullptr,
		nullptr
	);

	if (window == nullptr) {
		printf("Failed to create GLFW window\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		printf("Failed to initialize Glad\n");
		return -1;
	}

	glfwSetKeyCallback(window, myKeyCallback);

	glViewport(0, 0, windowWidth, windowHeight);
	printf("Voxel Game Engine Started\n");

	while (!glfwWindowShouldClose(window)) {
		glClearColor(250.0f / 255.0f, 119.0f / 255.0f, 110.0f / 255.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);



		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}