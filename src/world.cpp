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

void World::generate() {
  for (int x = -100; x <= 100; x++) {
    float wave = std::sin(x * 0.2f) * 150.0f;
    float offset = std::rand() % 101 - 50; 
    for (int y = -10; y * 50.0f <= wave + offset; y++) {
      glm::vec2 position = {x * 50, y * 50};
      _object_store.emplace_back(3, position, glm::vec2{50.0f, 50.0f});
    }
  }
}
