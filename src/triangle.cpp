#include <triangle.hpp>

namespace {
  const std::vector<Vertex> vertices = {
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {1.0f, 1.0f}},
  };

  const std::vector<GLuint> indices = {0, 1, 2};
}

Triangle& Triangle::instance() {
  static Triangle triangle;
  return triangle;
}

Triangle::Triangle() : _program("assets/triangle_vert.glsl", "assets/triangle_frag.glsl"), _mesh(vertices, indices) {
  for (GLuint corner = 0; corner < 3; corner++) _mesh.add_instance_attribute(2 + corner, 3, sizeof(TriangleInstance), offsetof(TriangleInstance, positions) + corner * sizeof(glm::vec3));
  _mesh.add_instance_attribute(5, 3, sizeof(TriangleInstance), offsetof(TriangleInstance, color));

  _projection_location = _program.get_location("u_projection");
  _view_location = _program.get_location("u_view");
  _program.use();
  _program.set_uniform(_program.get_location("u_texture"), 0);
}

void Triangle::draw(const std::vector<TriangleInstance>& triangles, const Texture& texture) {
  _program.use();
  texture.bind();
  _mesh.draw(triangles);
}
