#include <world.hpp>
#include <camera.hpp>

World& World::instance() {
  static World world;
  return world;
}

void World::draw() {
  _batches.resize(_texture_store.get_all().size());
  for (std::vector<Instance>& batch : _batches) batch.clear();

  for (Block* block : _physics.get_render_blocks()) {
    _batches[block->get_sprite().get_texture_id()].push_back(block->get_instance());
  }

  for (size_t texture_id = 0; texture_id < _batches.size(); texture_id++) {
    const std::vector<Instance>& batch = _batches[texture_id];
    if (batch.empty()) continue;

    _texture_store.get(static_cast<int>(texture_id)).bind();
    _quad.draw(batch);
  }
}

void World::generate() {
  _block_store.reserve(200);

  for (int i = -50; i < 50; i++) {
    _block_store.emplace_back(1, glm::vec2{i * 50 + 25, 0.0f}, glm::vec2{50.0f, 50.0f}, b2_staticBody);
  }

  for (int i = -5; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      _block_store.emplace_back(0, glm::vec2{i * 60 + 30, j * 60 + 200}, glm::vec2{50.0f, 50.0f}, b2_dynamicBody);
    }
  }
}
