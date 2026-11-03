#include <mesh.hpp>

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices) : _index_count(static_cast<GLsizei>(indices.size())) {
  glGenVertexArrays(1, &_vao);
  glGenBuffers(1, &_vbo);
  glGenBuffers(1, &_ebo);
  glGenBuffers(1, &_ibo);
  glBindVertexArray(_vao);

  glBindBuffer(GL_ARRAY_BUFFER, _vbo);
  glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(vertices.size() * sizeof(Vertex)), vertices.data(), GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizeiptr>(indices.size() * sizeof(GLuint)), indices.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, position)));
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, uv)));
  glEnableVertexAttribArray(1);

  glBindVertexArray(0);
}

Mesh::~Mesh() {
  glDeleteBuffers(1, &_ibo);
  glDeleteBuffers(1, &_ebo);
  glDeleteBuffers(1, &_vbo);
  glDeleteVertexArrays(1, &_vao);
}

void Mesh::add_instance_attribute(GLuint index, GLint size, GLsizei stride, std::size_t offset) {
  glBindVertexArray(_vao);
  glBindBuffer(GL_ARRAY_BUFFER, _ibo);
  glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, reinterpret_cast<void*>(offset));
  glEnableVertexAttribArray(index);
  glVertexAttribDivisor(index, 1);
  glBindVertexArray(0);
}

void Mesh::draw(const void* instances, GLsizeiptr size, GLsizei count) const {
  glBindBuffer(GL_ARRAY_BUFFER, _ibo);
  glBufferData(GL_ARRAY_BUFFER, size, instances, GL_DYNAMIC_DRAW);

  glBindVertexArray(_vao);
  glDrawElementsInstanced(GL_TRIANGLES, _index_count, GL_UNSIGNED_INT, nullptr, count);
  glBindVertexArray(0);
}
