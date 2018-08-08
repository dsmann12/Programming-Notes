#ifndef MESH_H
#define MESH_H

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>


class Vertex {
	public:
		Vertex(const glm::vec3& pos);
	private:
		glm::vec3 pos;
};

class Mesh {
	public:
		Mesh(Vertex* vertices, unsigned int numVertices);
		virtual ~Mesh();
		void draw();		
	private:
		enum {
			POSITION_VB,
			NUM_BUFFERS
		};
		GLuint m_vertexArrayObject;
		GLuint m_vertexArrayBuffers[NUM_BUFFERS];
		unsigned int m_drawCount;

};

#endif
