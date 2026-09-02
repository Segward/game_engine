#include <world.hpp>
#include <camera.hpp>

namespace {
  float get_terrain_height(int x) {
    float large = std::sin(x * 0.012f) * 200.0f;
    float medium = std::sin(x * 0.035f) * 80.0f;
    float small = std::sin(x * 0.11f) * 30.0f;
    float bumps = std::sin(x * 0.25f) * 10.0f;
    float random = std::rand() % 31 - 15.0f;
    return (large + medium + small + bumps + random) / pixels_per_object;
  }
}

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
  for (int x = -1000; x <= 1000; x++) {
    float height = get_terrain_height(x);
    for (int y = -20; y <= height; y++)
      _object_store.emplace_back(3, glm::vec2{x, y}, glm::vec2{1.0f, 1.0f});
  }
}
