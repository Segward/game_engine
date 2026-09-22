#include <chunk.hpp>

Chunk::Chunk(std::vector<Block>&& blocks) : _blocks(std::move(blocks)) {}

int Chunk::emplace_back(const int sprite_id, const glm::vec2& position, const glm::vec2& size, const b2BodyType type) {
  _blocks.emplace_back(sprite_id, position, size, type);
  return static_cast<int>(_blocks.size()) - 1;
}
