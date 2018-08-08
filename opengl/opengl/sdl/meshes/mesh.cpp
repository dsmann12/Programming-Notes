#include <iostream>
#include <fstream>
#include "mesh.h"

Vertex::Vertex(const glm::vec3& pos) {
	this->pos = pos;
}

Mesh::Mesh(Vertex* vertices, unsigned int numVertices) {
	m_drawCount = numVertices;

	// gnerate one vertex array object
	glGenVertexArrays(1, &m_vertexArrayObject);
	// bind so that any operation that will affect vertex array object will affect this one specified
	glBindVertexArray(m_vertexArrayObject);

	// want all vertex buffers to be apart of vertex array object
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	// GL_ARRAY_BUFFER tells opengl to interpret next argument as an array
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
	// now want to put all vertex data in array
	// takes data from RAM and moves it to GPU memory (excpet in integrated GPUs which use RAM as memory)
	// GL_STATIC_DRAW tells GPU that this data will never change. Will put data in place in GPU where data is constant
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);
	
	// now tell GPU how to interpret this data
	// Vertices have attributes. Can use member variables in vertex class. Position is one attribute. Color could be another
	// OpenGL (GPU) needs to read data as a sequential array of data. Members of class could be pos, col making an array
	// or pos, col, pos, col, pos, col. Not useful. AttribArray functions tells GPU that array of attribut is every 2 member variables
	// skipping over col data
	glEnableVertexAttribArray(0); // tells there is going to be some attribute that can be read as an array
	// now must tell how to read it as an array
	// vec3 so 3 pieces of data
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); 


	// this maens any operation that will affect vertex array object will no long affect one earlier specified
	glBindVertexArray(0);
}


Mesh::~Mesh() {
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::draw() {
	glBindVertexArray(m_vertexArrayObject);

	// draw
	glDrawArrays(GL_TRIANGLES, 0, m_drawCount);

	glBindVertexArray(0);
}
