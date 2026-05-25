#include <mesh.hpp>

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices) {
  glGenVertexArrays(1, &_vao);
  glGenBuffers(1, &_vbo);
  glGenBuffers(1, &_ebo);
  glBindVertexArray(_vao);

  const GLsizeiptr vertices_size = static_cast<GLsizeiptr>(vertices.size() * sizeof(Vertex));
  const GLsizeiptr indices_size = static_cast<GLsizeiptr>(indices.size() * sizeof(GLuint));

  glBindBuffer(GL_ARRAY_BUFFER, _vbo);
  glBufferData(GL_ARRAY_BUFFER, vertices_size, vertices.data(), GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, _ebo);
  glBufferData(GL_ARRAY_BUFFER, indices_size, indices.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, position)));
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, normal)));
  glEnableVertexAttribArray(1);

  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, uv)));
  glEnableVertexAttribArray(2);

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
