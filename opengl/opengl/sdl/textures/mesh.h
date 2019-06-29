#ifndef MESH_H
#define MESH_H

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>


class Vertex {
	public:
		Vertex(const glm::vec3& pos, const glm::vec2& texCoord);
		inline glm::vec3* get_pos() { return &pos; }
		inline glm::vec2* get_texCoord() { return &texCoord; }
	private:
		glm::vec3 pos;
		glm::vec2 texCoord;
};

class Mesh {
	public:
		Mesh(Vertex* vertices, unsigned int numVertices);
		virtual ~Mesh();
		void draw();		
	private:
		enum {
			POSITION_VB,
			TEXCOORD_VB,
			NUM_BUFFERS
		};
		GLuint m_vertexArrayObject;
		GLuint m_vertexArrayBuffers[NUM_BUFFERS];
		unsigned int m_drawCount;

};

#endif
