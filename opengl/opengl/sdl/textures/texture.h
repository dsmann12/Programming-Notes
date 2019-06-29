#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GL/glew.h>

class Texture {
	public:
		Texture(const std::string& filename);
		void bind(unsigned int unit);
		virtual ~Texture();
	private:
		GLuint m_texture;
};

#endif
