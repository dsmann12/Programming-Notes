#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

class Shader {
	public:
		Shader(const std::string& filename);
		void bind();
		virtual ~Shader();
	private:
		static const unsigned int NUM_SHADERS = 2;
		GLuint m_program;
		GLuint m_shaders[NUM_SHADERS];	
};

#endif
