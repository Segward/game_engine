#include <mesh.hpp>

Mesh::Mesh(const std::vector<glm::vec3>& positions, const std::vector<GLuint>& indices) {
  glGenVertexArrays(1, &_vao);
  glGenBuffers(1, &_vbo);
  glGenBuffers(1, &_ebo);

  glBindVertexArray(_vao);

  const GLsizeiptr positions_bytes = static_cast<GLsizeiptr>(positions.size() * sizeof(glm::vec3));
  glBindBuffer(GL_ARRAY_BUFFER, _vbo);
  glBufferData(GL_ARRAY_BUFFER, positions_bytes, positions.data(), GL_STATIC_DRAW);

  const GLsizeiptr indices_bytes = static_cast<GLsizeiptr>(indices.size() * sizeof(GLuint));
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_bytes, indices.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), nullptr);
  glEnableVertexAttribArray(0);

  glBindVertexArray(0);

  _index_count = static_cast<GLsizei>(indices.size());
}

Mesh::~Mesh() {
  if (_ebo) {
    glDeleteBuffers(1, &_ebo);
  }

  if (_vbo) {
    glDeleteBuffers(1, &_vbo);
  }

  if (_vao) {
    glDeleteVertexArrays(1, &_vao);
  }
}

void Mesh::draw() const {
  glBindVertexArray(_vao);
  glDrawElements(GL_TRIANGLES, _index_count, GL_UNSIGNED_INT, nullptr);
}
