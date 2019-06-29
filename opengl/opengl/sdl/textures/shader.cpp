#include <iostream>
#include <fstream>
#include "shader.h"

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
static std::string LoadShader(const std::string& filename);
static GLuint CreateShader(const std::string& text, GLenum shadertype);

Shader::Shader(const std::string& filename) {
	std::cout << filename << std::endl;	
	// tell opengl to create program
	m_program = glCreateProgram();
	// create shader from filename and assign it to vertex shader
	m_shaders[0] = CreateShader(LoadShader(filename + ".vs"), GL_VERTEX_SHADER);
	m_shaders[1] = CreateShader(LoadShader(filename + ".fs"), GL_FRAGMENT_SHADER);

	// loop through all shaders
	for (unsigned int i = 0; i < NUM_SHADERS; ++i) {
		// attach shader to program
		glAttachShader(m_program, m_shaders[i]);
	}

	// DONT FORGET THIS
	// WON'T OBVIOUSLY FAIL IF YOU DONT
	// Bind attribute location
	// binds with data in shader code.
	glBindAttribLocation(m_program, 0, "position");
	glBindAttribLocation(m_program, 1, "texCoord");

	// neeed to link shaders
	glLinkProgram(m_program);
	CheckShaderError(m_program, GL_LINK_STATUS, true, "Error: Shader Program linking failed");

	// now validate program
	glValidateProgram(m_program);
	CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Program is invalid");
}

Shader::~Shader() {

	// for every shader, detach and delete
	for (unsigned int i = 0; i < NUM_SHADERS; ++i) {
		glDetachShader(m_program, m_shaders[i]);
		glDeleteShader(m_shaders[i]);
	}

	glDeleteProgram(m_program);
}

static GLuint CreateShader(const std::string& text, GLenum shadertype) {
	// Create shader
	GLuint shader = glCreateShader(shadertype);

	// Error check
	if (shader == 0) {
		std::cerr << "Error: Shader creation failed\n";
	}

	// opengl is a c api so cannot use std::string
	const GLchar* shaderSourceStrings[1];
	GLint shaderSourceStringLengths[1];
	shaderSourceStrings[0] = text.c_str(); 
	shaderSourceStringLengths[0] = text.length();

	// implementation depends on graphics card and driver
	glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
	glCompileShader(shader);

	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed");
	return shader;
}

void Shader::bind() {
	// bind program
	glUseProgram(m_program);
}


static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage) {
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram) {
		glGetProgramiv(shader, flag, &success);
	} else {
		glGetShaderiv(shader, flag, &success);
	}

	if (success == GL_FALSE) {
		if (isProgram) {
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		} else {
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);
		}

		std::cerr << errorMessage << ": '" << error << "'" << std::endl;
	}
}

static std::string LoadShader(const std::string& filename) {
	std::ifstream file;
	file.open(filename.c_str());

	std::string output;
	std::string line;

	if (file.is_open()) {
		while (file.good()) {
			getline(file, line);
			output.append(line + '\n');
		}
	} else {
		std::cerr << "Unable to load shader: " << filename << std::endl;
	}

	return output;
}
