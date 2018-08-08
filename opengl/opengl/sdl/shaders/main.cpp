#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"

int main() {
	std::cout << "Hello World\n";
	std::cout << "Yes! I think it's working!\n";
	Display display(800, 600, "Hello World!");
	Shader shader("./res/basicShader");
	while(!display.isClosed()) {
		// set clear color to some color
		glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
		// clear color buffer. Fill all colors with clear color
		glClear(GL_COLOR_BUFFER_BIT);

		shader.bind();
		display.Update();
	}
	return 0;
}