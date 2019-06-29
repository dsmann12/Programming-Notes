#include "texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <cassert>
#include <iostream>

Texture::Texture(const std::string& filename) {
	// STBI will return this information
	int width, height, numComponents;
	// Loads texture data
	// Writes a few pieces of data
	// 1. Texture data
	unsigned char* image_data = stbi_load(filename.c_str(), &width, &height, &numComponents, 4);
	
	if (image_data == NULL) {
			std::cerr << "Texture loading failed for texture " << filename << std::endl;
	}

	// Buffers
	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	// function -> this controls texture wrapping
	// if read some location outside texture body, this lets you control what happens
	// One is for width, nad one is for height
	// Last parameter is for what action to take
	// Can do GL_CLAMP too
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// function -> 
	// What happens if texture takes up fewer pixels than specified or more
	// Min for when it takes up fewer, and Mag when it's bigger
	// Linear means linear interpolation
	// Also GL_NEAREST? For pixelated effect in the distance
	// More texture parameters than just this
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// technically optional. Specify texture data
	// Send data to GPU
	// target tells how to send data,
	// level is for mip mapping. Have textures of different resolutions of same object and will
	// use higher resolution when closer to camera and lower resolution when farther
	// Internal format is how OpenGL will store infinite pixels on GPU
	// width and height of texture
	// border
	// format is input format. Format of data being sent to GPU
	// type is how how data is stored
	// pixels -> pointer to data
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, 
					GL_UNSIGNED_BYTE, image_data);

	// Delete texture data from memory when don't need it anymore
	stbi_image_free(image_data);
}

Texture::~Texture() {
	glDeleteTextures(1, &m_texture);
}

void Texture::bind(unsigned int unit) {
	
	// OpenGL only has texture 0 - 31
	assert(unit >= 0 && unit <= 31);
	// will change what texture OpenGL is working with
	// Uses unit to get correct texture
	glActiveTexture(GL_TEXTURE0 + unit);
	// make so all future operations uses m_texture Texture
	glBindTexture(GL_TEXTURE_2D, m_texture);
}
