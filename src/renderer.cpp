#include <renderer.hpp>
#include <window.hpp>
#include <store.hpp>
#include <sprite.hpp>
#include <texture.hpp>
#include <object.hpp>
#include <camera.hpp>
#include <quad.hpp>

namespace {
  Window& window = Window::instance();
  Store<Sprite>& sprite_store = Store<Sprite>::instance();
  Store<Texture>& texture_store = Store<Texture>::instance();
  Store<Object>& object_store = Store<Object>::instance();
  Camera& camera = Camera::instance();
  Quad& quad = Quad::instance();
}

void renderer::render() {
  glClear(GL_COLOR_BUFFER_BIT);

  camera.update();
  quad.set_projection(camera.get_projection());
  quad.set_view(glm::mat4(1.0f));

  texture_store.get(1).bind();
  quad.set_uv_offset({0.0f, 0.0f});
  quad.set_uv_scale({1.0f, 1.0f});
  quad.draw({0.0f, 0.0f}, window.get_size());

  quad.set_view(camera.get_view());

  for (const Object& object : object_store.get_all()) {
    const Sprite& sprite = sprite_store.get(object.get_sprite_id());
    texture_store.get(sprite.get_texture_id()).bind();
    quad.set_uv_offset(sprite.get_uv_offset());
    quad.set_uv_scale(sprite.get_uv_scale());
    quad.draw(object.get_position(), object.get_size());
  }

  window.swap_buffers();
}
