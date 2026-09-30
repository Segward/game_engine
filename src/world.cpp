#include <world.hpp>
#include <camera.hpp>

World& World::instance() {
  static World world;
  return world;
}

void World::draw() {
  _batches.resize(_assets_manager.get_all_textures().size());
  for (std::vector<Instance>& batch : _batches) batch.clear();

  for (Block* block : _physics.get_render_blocks()) {
    _batches[block->get_sprite().get_texture_id()].push_back(block->get_instance());
  }

  for (size_t texture_id = 0; texture_id < _batches.size(); texture_id++) {
    const std::vector<Instance>& batch = _batches[texture_id];
    if (batch.empty()) continue;

    _assets_manager.get_texture(static_cast<int>(texture_id)).bind();
    _quad.draw(batch);
  }
}

void World::generate() {
  for (int i = -50; i < 50; i++) _blocks.emplace_back(1, glm::vec2{i * 50 + 25, 0.0f}, glm::vec2{50.0f, 50.0f}, b2_staticBody);
  for (int i = 0; i < 20; i++) _blocks.emplace_back(1, glm::vec2{0.0f, i * 50 + 25}, glm::vec2{50.0f, 50.0f}, b2_dynamicBody);
}
