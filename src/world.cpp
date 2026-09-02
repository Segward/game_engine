#include <world.hpp>

World& World::instance() {
  static World world;
  return world;
}

void World::draw() {
  _batches.resize(_texture_store.get_all().size());
  for (std::vector<Instance>& batch : _batches) batch.clear();

  for (const Object& object : _object_store.get_all()) {
    const Sprite& sprite = object.get_sprite();
    _batches[sprite.get_texture_id()].push_back({object.get_position(), object.get_size(), sprite.get_uv_offset(), sprite.get_uv_scale()});
  }

  for (size_t texture_id = 0; texture_id < _batches.size(); texture_id++) {
    const std::vector<Instance>& batch = _batches[texture_id];
    if (batch.empty()) continue;

    _texture_store.get(static_cast<int>(texture_id)).bind();
    _quad.draw(batch);
  }
}

void World::generate() {
  for (int x = -500; x <= 500; x++) {
    float wave = std::sin(x * 0.2f) * 150.0f;
    float offset = std::rand() % 101 - 50; 
    for (int y = -10; y * 50.0f <= wave + offset; y++) {
      glm::vec2 position = {x * 50, y * 50};
      _object_store.emplace_back(3, position, glm::vec2{50.0f, 50.0f});
    }
  }
}
