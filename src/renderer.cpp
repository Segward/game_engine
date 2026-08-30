#include <renderer.hpp>
#include <init.hpp>

Renderer& Renderer::instance() {
  static Renderer Renderer;
  return Renderer;
}

void Renderer::draw() {
  glClear(GL_COLOR_BUFFER_BIT);

  _camera.update();
  _quad.set_projection(_camera.get_projection());

  for (const Object& object : _object_store.get_all()) {
    _texture_store.get(object.get_texture_id()).bind();

    const Sprite& sprite = _sprite_store.get(object.get_sprite_id());
    _quad.set_uv_offset(sprite.get_uv_offset());
    _quad.set_uv_scale(sprite.get_uv_scale());

    _quad.draw(object.get_position(), object.get_size());
  }
}
