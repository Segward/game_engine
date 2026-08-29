#include <sprite_store.hpp>
#include <quad.hpp>
#include <texture_store.hpp>

SpriteStore& SpriteStore::instance() {
  static SpriteStore store;
  return store;
}

int SpriteStore::store(const int texture_id, const glm::vec2 uv_offset, const glm::vec2 uv_scale) {
  _sprites.emplace_back(texture_id, uv_offset, uv_scale);
  return static_cast<int>(_sprites.size()) - 1;
}
