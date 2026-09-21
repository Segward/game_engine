#include <chunk.hpp>

Chunk::Chunk(std::vector<Object>&& objects) : _objects(std::move(objects)) {}

int Chunk::emplace_back(const int sprite_id, const glm::vec2& position, const glm::vec2& size) {
  _objects.emplace_back(sprite_id, position, size);
  return static_cast<int>(_objects.size()) - 1;
}

void Chunk::load() {
  if (_loaded) return;

  _loaded = true;
}

void Chunk::unload() {

  _loaded = false;
}
