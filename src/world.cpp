#include <world.hpp>

World& World::instance() {
  static World world;
  return world;
}

void World::draw_background() {
  const Texture& texture = texture_store.get(1);
  texture.bind();

  const glm::vec2& window_size = window.get_size(); 
  const glm::vec2& texture_size = texture.get_size(); 

  float scale = std::max(window_size.x / texture_size.x, window_size.y / texture_size.y);
  glm::vec2 uv_scale = window_size / (texture_size * scale);

  quad.set_uv_scale(uv_scale);
  quad.set_uv_offset((1.0f - uv_scale) / 2.0f);
  quad.draw({0.0f, 0.0f}, window_size);
}

void World::draw_objects() {
  for (const Object& object : object_store.get_all()) {
    const Sprite& sprite = object.get_sprite();
    sprite.get_texture().bind();
    quad.set_uv_offset(sprite.get_uv_offset());
    quad.set_uv_scale(sprite.get_uv_scale());
    quad.draw(object.get_position(), object.get_size());
  }
}
