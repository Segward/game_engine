#include <quad.hpp>

namespace {
  const std::vector<Vertex> VERTICES = {
    {{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
    {{0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
    {{0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
    {{-0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
  };

  const std::vector<GLuint> INDICES = {0, 1, 2, 2, 3, 0};
}

Quad& Quad::instance() {
  static Quad quad;
  return quad;
}

void Quad::draw(const glm::vec2& position, const glm::vec2& size) {
  _program.use();

  _program.set_uniform(_position_location, position);
  _program.set_uniform(_size_location, size);

  _mesh.draw();
}

Quad::Quad() : _program("assets/quad_vert.glsl", "assets/quad_frag.glsl"), _mesh(VERTICES, INDICES) {
  _position_location = _program.get_location("u_position");
  _size_location = _program.get_location("u_size");
  _texture_location = _program.get_location("u_texture");
  _uv_offset_location = _program.get_location("u_uv_offset");
  _uv_scale_location = _program.get_location("u_uv_scale");
  _projection_location = _program.get_location("u_projection");

  _program.set_uniform(_texture_location, 0);
}
