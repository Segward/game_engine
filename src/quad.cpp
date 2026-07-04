#include <quad.hpp>


namespace {
  const std::vector<Vertex> VERTICES = {
      {{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
      {{0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
      {{0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
      {{-0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
  };

  const std::vector<GLuint> INDICES = {0, 1, 2, 2, 3, 0};
}

Quad& Quad::instance() {
  static Quad quad;
  return quad;
}

void Quad::draw(const glm::vec2& position, const glm::vec2& size) {
  _program.use();

  GLint position_location = _program.get_location("u_position");
  GLint size_location = _program.get_location("u_size");

  _program.set_uniform(position_location, position);
  _program.set_uniform(size_location, size);

  _mesh.draw();
}

Quad::Quad() : _program("assets/quad.vert", "assets/quad.frag"), _mesh(VERTICES, INDICES) {}

