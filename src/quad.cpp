#include <quad.hpp>

namespace {
  const std::vector<glm::vec3> QUAD_POSITIONS = {
    {-0.5f, -0.5f, 0.0f},
    { 0.5f, -0.5f, 0.0f},
    { 0.5f,  0.5f, 0.0f},
    {-0.5f,  0.5f, 0.0f},
  };

  const std::vector<GLuint> QUAD_INDICES = {0, 1, 2, 2, 3, 0};
}

Quad::Quad()
  : _mesh(QUAD_POSITIONS, QUAD_INDICES),
    _shader("assets/quad.vert", "assets/quad.frag"),
    _u_position(_shader.get_uniform_location("u_position")),
    _u_size(_shader.get_uniform_location("u_size")),
    _u_color(_shader.get_uniform_location("u_color")) {}

void Quad::render(const glm::vec2& position, const glm::vec2& size, const glm::vec3& color) {
  _shader.set_uniform(_u_position, position);
  _shader.set_uniform(_u_size, size);
  _shader.set_uniform(_u_color, color);
  _shader.use_program();
  _mesh.draw();
}
