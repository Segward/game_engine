#include <triangle.hpp>

namespace {
  struct TriangleVertex {
    glm::vec3 position;
    glm::vec2 uv;
    glm::vec3 color;
  };

  void enable_attribute(GLuint index, GLint size, std::size_t offset) {
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, sizeof(TriangleVertex), reinterpret_cast<void*>(offset));
    glEnableVertexAttribArray(index);
  }
}

Triangle& Triangle::instance() {
  static Triangle triangle;
  return triangle;
}

Triangle::Triangle() : _program("assets/triangle_vert.glsl", "assets/triangle_frag.glsl") {
  glGenVertexArrays(1, &_vao);
  glGenBuffers(1, &_vbo);
  glBindVertexArray(_vao);
  glBindBuffer(GL_ARRAY_BUFFER, _vbo);

  enable_attribute(0, 3, offsetof(TriangleVertex, position));
  enable_attribute(1, 2, offsetof(TriangleVertex, uv));
  enable_attribute(2, 3, offsetof(TriangleVertex, color));

  glBindVertexArray(0);

  _projection_location = _program.get_location("u_projection");
  _view_location = _program.get_location("u_view");
  _program.use();
  _program.set_uniform(_program.get_location("u_texture"), 0);
}

Triangle::~Triangle() {
  glDeleteBuffers(1, &_vbo);
  glDeleteVertexArrays(1, &_vao);
}

void Triangle::draw(const std::vector<TriangleInstance>& triangles, const Texture& texture) {
  std::vector<TriangleVertex> vertices;
  vertices.reserve(triangles.size() * 3);
  for (const TriangleInstance& triangle : triangles) {
    for (int corner = 0; corner < 3; corner++) vertices.push_back({triangle.positions[corner], triangle.uvs[corner], triangle.color});
  }

  _program.use();
  texture.bind();
  glBindBuffer(GL_ARRAY_BUFFER, _vbo);
  glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(vertices.size() * sizeof(TriangleVertex)), vertices.data(), GL_DYNAMIC_DRAW);

  glBindVertexArray(_vao);
  glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(vertices.size()));
  glBindVertexArray(0);
}
