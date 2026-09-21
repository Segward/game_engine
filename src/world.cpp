#include <world.hpp>
#include <camera.hpp>

World& World::instance() {
  static World world;
  return world;
}

void World::draw() {
  _batches.resize(_texture_store.get_all().size());
  for (std::vector<Instance>& batch : _batches) batch.clear();

  const glm::vec2& camera_position = _camera.get_position();
  const glm::vec2 render_view = _window.get_size() * 0.6f / _camera.get_zoom();
  std::cout << render_view.x << " " << render_view.y << "\n";

  for (const Object& object : _object_store.get_all()) {
    const glm::vec2 offset = glm::abs(object.get_position() - camera_position);
    if (offset.x > render_view.x || offset.y > render_view.y) continue;

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
  for (int x = -100; x <= 100; x++) {
    for (int y = -100; y <= 100; y++) {
      _object_store.emplace_back(1, glm::vec2{x * 50, y * 50}, glm::vec2{50.0f, 50.0f});
    }
  }
}
