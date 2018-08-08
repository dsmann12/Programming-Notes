#include <iostream>

#include <GL/glew.h> 			// GLEW
#include <GLFW/glfw3.h>			// GLFW

const GLint WIDTH = 800, HEIGHT = 600;		// Dimensions of window

int main() {
	// Initialize GLFW
	if(!glfwInit()) {
		std::cout << "GLFW initialization failed\n";
		glfwTerminate();
		return 1;
	}

	// Setup GLFW window properties
	// OpenGL version 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); 
	// No backward compatability
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Allow forward compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	
	GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
	if (!mainWindow) {
		std::cout << "GLFW Window creation failed\n";
		glfwTerminate();
		return 1;
	}

	// get buffer size information
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// set context for GLEW to use
	glfwMakeContextCurrent(mainWindow);

	// allow modern extension features
	glewExperimental = GL_TRUE;

	// initialize GLEW
	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW initiailization failed\n";
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}	

	// setup viewport size
	// setup size of what we are drawing to in the window
	// x coord, y coord
	glViewport(0, 0, bufferWidth, bufferHeight);
	
	// main loop
	// loop until window close
	while(!glfwWindowShouldClose(mainWindow)) {
		// enable user input events
		// resizing windows, moving, etc
		glfwPollEvents();
		
		// clear window
		// rgb values (0-1) and alpha
		// hex / 256 gets value
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// have two scenes going on at once
		// one you draw into
		// one that can be seen
		// also have triple buffering
		glfwSwapBuffers(mainWindow);
	}
	return 0;
}
