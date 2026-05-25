#include <mesh.hpp>

namespace {
  template<typename T>
  void bind_buffer_data(GLuint buffer, GLenum target, const std::vector<T>& vector) {
    const GLsizeiptr size = static_cast<GLsizeiptr>(vector.size() * sizeof(T));
    glBindBuffer(target, buffer);
    glBufferData(target, size, vector.data(), GL_STATIC_DRAW);
  }

  void enable_vertex_attribute(GLuint index, GLint size, const void* offset) {
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, sizeof(Vertex), offset);
    glEnableVertexAttribArray(index);
  }
}

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices) {
  glGenVertexArrays(1, &_vao);
  glGenBuffers(1, &_vbo);
  glGenBuffers(1, &_ebo);
  glBindVertexArray(_vao);

  bind_buffer_data(_vbo, GL_ARRAY_BUFFER, vertices);
  bind_buffer_data(_ebo, GL_ELEMENT_ARRAY_BUFFER, indices);

  enable_vertex_attribute(0, 3, reinterpret_cast<void*>(offsetof(Vertex, position)));
  enable_vertex_attribute(1, 3, reinterpret_cast<void*>(offsetof(Vertex, normal)));
  enable_vertex_attribute(2, 2, reinterpret_cast<void*>(offsetof(Vertex, uv)));

  glBindVertexArray(0);
  _index_count = static_cast<GLsizei>(indices.size());
}

Mesh::~Mesh() {
  if (_ebo) glDeleteBuffers(1, &_ebo);
  if (_vbo) glDeleteBuffers(1, &_vbo);
  if (_vao) glDeleteVertexArrays(1, &_vao);
}

void Mesh::draw() const {
  glBindVertexArray(_vao);
  glDrawElements(GL_TRIANGLES, _index_count, GL_UNSIGNED_INT, nullptr);
}
