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

}

Quad::Quad() : _program("vertex", "fragment"), _mesh(VERTICES, INDICES) {}

