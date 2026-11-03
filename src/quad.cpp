#include <quad.hpp>

namespace {
  const std::vector<Vertex> vertices = {
    {{-0.5f, -0.5f, 0.0f}, {0.0f, 1.0f}},
    {{0.5f, -0.5f, 0.0f}, {1.0f, 1.0f}},
    {{0.5f, 0.5f, 0.0f}, {1.0f, 0.0f}},
    {{-0.5f, 0.5f, 0.0f}, {0.0f, 0.0f}},
  };

  const std::vector<GLuint> indices = {0, 1, 2, 2, 3, 0};
}

Quad& Quad::instance() {
  static Quad quad;
  return quad;
}

Quad::Quad() : _program("assets/quad_vert.glsl", "assets/quad_frag.glsl"), _mesh(vertices, indices) {
  _mesh.add_instance_attribute(2, 2, sizeof(QuadInstance), offsetof(QuadInstance, position));
  _mesh.add_instance_attribute(3, 2, sizeof(QuadInstance), offsetof(QuadInstance, size));
  for (GLuint corner = 0; corner < 4; corner++) _mesh.add_instance_attribute(4 + corner, 2, sizeof(QuadInstance), offsetof(QuadInstance, uvs) + corner * sizeof(glm::vec2));
  _mesh.add_instance_attribute(8, 3, sizeof(QuadInstance), offsetof(QuadInstance, color));

  _projection_location = _program.get_location("u_projection");
  _program.use();
  _program.set_uniform(_program.get_location("u_texture"), 0);
}

void Quad::draw(const std::vector<QuadInstance>& instances, const Texture& texture) {
  _program.use();
  texture.bind();
  _mesh.draw(instances);
}
