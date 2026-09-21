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
  const glm::vec2 window_view = _window.get_size() * 0.6f / _camera.get_zoom();

  const glm::ivec2 min_chunk_position = {
    static_cast<int>(std::floor((camera_position.x - window_view.x) / 500.0f)),
    static_cast<int>(std::floor((camera_position.y - window_view.y) / 500.0f))
  };

  const glm::ivec2 max_chunk_position = {
    static_cast<int>(std::floor((camera_position.x + window_view.x) / 500.0f)),
    static_cast<int>(std::floor((camera_position.y + window_view.y) / 500.0f))
  };

  for (int x = min_chunk_position.x; x <= max_chunk_position.x; x++) {
    for (int y = min_chunk_position.y; y <= max_chunk_position.y; y++) {
      std::unordered_map<glm::ivec2, Chunk>::iterator chunk_iterator = _chunks.find({x, y});
      if (chunk_iterator == _chunks.end()) continue;

      for (const Object& object : chunk_iterator->second.get_all()) {
        const Sprite& sprite = object.get_sprite();
        _batches[sprite.get_texture_id()].push_back({object.get_position(), object.get_size(), sprite.get_uv_offset(), sprite.get_uv_scale()});
      }
    }
  }

  for (size_t texture_id = 0; texture_id < _batches.size(); texture_id++) {
    const std::vector<Instance>& batch = _batches[texture_id];
    if (batch.empty()) continue;

    _texture_store.get(static_cast<int>(texture_id)).bind();
    _quad.draw(batch);
  }
}

void World::generate() {
  for (int i = -1000; i <= 1000; i++) {
    for (int j = -1000; j <= 1000; j++) {
      const glm::vec2 position = {i * 50, j * 50};

      const glm::ivec2 chunk_position = {
        static_cast<int>(std::floor(position.x / 500.0f)),
        static_cast<int>(std::floor(position.y / 500.0f))
      };

      Chunk& chunk = _chunks.try_emplace(chunk_position, std::vector<Object>{}).first->second;
      chunk.emplace_back(1, position, glm::vec2{50.0f, 50.0f});
    }
  }
}
