#include <world.hpp>

World& World::instance() {
  static World world;
  return world;
}

void World::draw() {
  for (const Object& object : _object_store.get_all()) {
    const Sprite& sprite = object.get_sprite();
    sprite.get_texture().bind();
    _quad.set_uv_offset(sprite.get_uv_offset());
    _quad.set_uv_scale(sprite.get_uv_scale());
    _quad.draw(object.get_position(), object.get_size());
  }
}
