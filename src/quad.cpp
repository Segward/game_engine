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

void Quad::draw(const glm::vec2& position, const glm::vec2& size, const Sprite& sprite) {
  _program.use();

  GLint position_location = _program.get_location("u_position");
  GLint size_location = _program.get_location("u_size");
  GLint texture_location = _program.get_location("u_texture");
  GLint uv_offset_location = _program.get_location("u_uv_offset");
  GLint uv_scale_location = _program.get_location("u_uv_scale");

  _program.set_uniform(position_location, position);
  _program.set_uniform(size_location, size);
  _program.set_uniform(texture_location, 0);
  _program.set_uniform(uv_offset_location, sprite.uv_offset);
  _program.set_uniform(uv_scale_location, sprite.uv_scale);

  sprite.texture->bind(0);
  _mesh.draw();
}

Quad::Quad() : _program("assets/quad_vert.glsl", "assets/quad_frag.glsl"), _mesh(VERTICES, INDICES) {}
