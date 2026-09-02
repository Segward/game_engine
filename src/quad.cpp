#include <quad.hpp>

namespace {
  const std::vector<Vertex> vertices = {
    {{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
    {{0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
    {{0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
    {{-0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
  };

  const std::vector<GLuint> indices = {0, 1, 2, 2, 3, 0};
}

Quad& Quad::instance() {
  static Quad quad;
  return quad;
}

void Quad::draw(const std::vector<Instance>& instances) {
  _program.use();
  _mesh.set_instances(instances);
  _mesh.draw();
}

Quad::Quad() : _program("assets/quad_vert.glsl", "assets/quad_frag.glsl"), _mesh(vertices, indices) {
  _projection_location = _program.get_location("u_projection");
  _view_location = _program.get_location("u_view");

  GLint texture_location = _program.get_location("u_texture");
  _program.use();
  _program.set_uniform(texture_location, 0);
}
