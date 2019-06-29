#include <GL/glew.h>
#include <iostream>
#include "display.h"


Display::Display(int width, int height, const std::string& title) {
	// initialize everything in SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// because using SDL_WINDOW_OPENGL can set additional parameters
	// # of bits used for displaying red colors. So 2^8 types of red. 256/ 8 * 4 = 32bits of data
	// may not get exactly 8 bits. At least 8 bits.
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	// how much data in bits SDL will allocate for a single pixel
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	// Allocate space for two windows. Double buffering
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	//SDL is C Library so needs C style string
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
					width, height, SDL_WINDOW_OPENGL);

	// GL Context decreases control OS has over window. 
	// Says GPU has control of windows. Gives GPU access to window. 
	m_glContext = SDL_GL_CreateContext(m_window);

	// GLEW construct
	// Initialize glew. Go through OS and find every openGL operation supported
	GLenum status = glewInit();
	if (status != GLEW_OK) {
		std::cerr << "Glew failed to initialize\n";
	}

	closed = false;	
	
}

Display::~Display() {
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

bool Display::isClosed() {
	return closed;
}

// For double buffering
void Display::Update() {
	SDL_GL_SwapWindow(m_window);

	SDL_Event e;
	while(SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			closed = true;
		}
	}
}
