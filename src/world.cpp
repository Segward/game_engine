#include <world.hpp>
#include <camera.hpp>

World& World::instance() {
  static World world;
  return world;
}

void World::update() {
  const glm::vec2& camera_position = _camera.get_position();
  const glm::vec2 window_view = _window.get_size() * 0.6f / _camera.get_zoom();

  _min_chunk_position = glm::ivec2(glm::floor((camera_position - window_view) / 500.0f));
  _max_chunk_position = glm::ivec2(glm::floor((camera_position + window_view) / 500.0f));

  std::erase_if(_active_chunks, [this](const glm::ivec2& position) {
    return !is_chunk_visible(position);
  });

  for (int x = _min_chunk_position.x; x <= _max_chunk_position.x; x++) {
    for (int y = _min_chunk_position.y; y <= _max_chunk_position.y; y++) {
      _active_chunks.insert({x, y});
    }
  }
}

void World::draw() {
  _batches.resize(_texture_store.get_all().size());
  for (std::vector<Instance>& batch : _batches) batch.clear();

  for (const glm::ivec2& chunk_position : _active_chunks) {
    std::unordered_map<glm::ivec2, Chunk>::iterator chunk_iterator = _chunks.find(chunk_position);
    if (chunk_iterator == _chunks.end()) continue;

    for (const Block& block : chunk_iterator->second.get_all()) {
      _batches[block.get_sprite().get_texture_id()].push_back(block.get_instance());
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
  for (int i = -50; i < 50; i++) {
    const glm::vec2 position = {i * 50 + 25, 0.0f};

    const glm::ivec2 chunk_position = {
      static_cast<int>(std::floor(position.x / 500.0f)),
      static_cast<int>(std::floor(position.y / 500.0f))
    };

    Chunk& chunk = _chunks.try_emplace(chunk_position, std::vector<Block>{}).first->second;
    chunk.emplace_back(1, position, glm::vec2{50.0f, 50.0f}, b2_staticBody);
  }

  for (int i = -5; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      const glm::vec2 position = {i * 60 + 30, j * 60 + 200};

      const glm::ivec2 chunk_position = {
        static_cast<int>(std::floor(position.x / 500.0f)),
        static_cast<int>(std::floor(position.y / 500.0f))
      };

      Chunk& chunk = _chunks.try_emplace(chunk_position, std::vector<Block>{}).first->second;
      chunk.emplace_back(0, position, glm::vec2{50.0f, 50.0f}, b2_dynamicBody);
    }
  }
}

bool World::is_chunk_visible(const glm::ivec2& chunk_position) const {
  return (chunk_position.x <= _max_chunk_position.x && 
          chunk_position.y <= _max_chunk_position.y && 
          chunk_position.x >= _min_chunk_position.x &&
          chunk_position.y >= _min_chunk_position.y);
}
