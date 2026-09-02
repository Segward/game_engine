#include <background.hpp>

Background& Background::instance() {
  static Background world;
  return world;
}

void Background::draw() {
  const Texture& texture = _texture_store.get(1);
  texture.bind();

  const glm::vec2& window_size = _window.get_size();
  const glm::vec2& texture_size = texture.get_size();

  float scale = std::max(window_size.x / texture_size.x, window_size.y / texture_size.y);

  glm::vec2 uv_scale = window_size / (texture_size * scale);
  glm::vec2 uv_offset = (1.0f - uv_scale) / 2.0f;

  _quad.draw({{_camera.get_position(), window_size / _camera.get_zoom() / pixels_per_object, uv_offset, uv_scale}});
}
