#include <background.hpp>
#include <window.hpp>
#include <store.hpp>
#include <texture.hpp>
#include <quad.hpp>

Background& Background::instance() {
  static Background background;
  return background;
}

void Background::draw() {
  Window& window = Window::instance();
  Store<Texture>& texture_store = Store<Texture>::instance();
  Quad& quad = Quad::instance();

  const Texture& texture = texture_store.get(1);
  float aspect = (window.get_width() * texture.get_height()) / (window.get_height() * texture.get_width());
  glm::vec2 uv_scale = glm::min(glm::vec2(aspect, 1.0f / aspect), 1.0f);

  quad.set_view(glm::mat4(1.0f));
  texture.bind();

  quad.set_uv_offset((1.0f - uv_scale) * 0.5f);
  quad.set_uv_scale(uv_scale);
  quad.draw({0.0f, 0.0f}, window.get_size());
}
