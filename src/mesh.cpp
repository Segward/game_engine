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

  void enable_instance_attribute(GLuint index, GLint size, const void* offset) {
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, sizeof(Instance), offset);
    glEnableVertexAttribArray(index);
    glVertexAttribDivisor(index, 1);
  }
}

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices) {
  glGenVertexArrays(1, &_vao);
  glGenBuffers(1, &_vbo);
  glGenBuffers(1, &_ebo);
  glGenBuffers(1, &_ibo);
  glBindVertexArray(_vao);

  bind_buffer_data(_vbo, GL_ARRAY_BUFFER, vertices);
  bind_buffer_data(_ebo, GL_ELEMENT_ARRAY_BUFFER, indices);

  enable_vertex_attribute(0, 3, reinterpret_cast<void*>(offsetof(Vertex, position)));
  enable_vertex_attribute(1, 3, reinterpret_cast<void*>(offsetof(Vertex, normal)));
  enable_vertex_attribute(2, 2, reinterpret_cast<void*>(offsetof(Vertex, uv)));

  glBindBuffer(GL_ARRAY_BUFFER, _ibo);

  enable_instance_attribute(3, 2, reinterpret_cast<void*>(offsetof(Instance, position)));
  enable_instance_attribute(4, 2, reinterpret_cast<void*>(offsetof(Instance, size)));
  enable_instance_attribute(5, 2, reinterpret_cast<void*>(offsetof(Instance, uv_offset)));
  enable_instance_attribute(6, 2, reinterpret_cast<void*>(offsetof(Instance, uv_scale)));

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  _index_count = static_cast<GLsizei>(indices.size());
}

Mesh::~Mesh() {
  if (_ibo) glDeleteBuffers(1, &_ibo);
  if (_ebo) glDeleteBuffers(1, &_ebo);
  if (_vbo) glDeleteBuffers(1, &_vbo);
  if (_vao) glDeleteVertexArrays(1, &_vao);
}

void Mesh::set_instances(const std::vector<Instance>& instances) {
  const GLsizeiptr size = static_cast<GLsizeiptr>(instances.size() * sizeof(Instance));

  glBindBuffer(GL_ARRAY_BUFFER, _ibo);
  if (size > _instances_capacity) {
    glBufferData(GL_ARRAY_BUFFER, size, instances.data(), GL_DYNAMIC_DRAW);
    _instances_capacity = size;
  } else {
    glBufferData(GL_ARRAY_BUFFER, _instances_capacity, nullptr, GL_DYNAMIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, size, instances.data());
  }

  glBindBuffer(GL_ARRAY_BUFFER, 0);

  _instances_count = static_cast<GLsizei>(instances.size());
}

void Mesh::draw() const {
  glBindVertexArray(_vao);
  glDrawElementsInstanced(GL_TRIANGLES, _index_count, GL_UNSIGNED_INT, nullptr, _instances_count);
  glBindVertexArray(0);
}
