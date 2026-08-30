#include <object_store.hpp>

ObjectStore& ObjectStore::instance() {
  static ObjectStore store;
  return store;
}

int ObjectStore::store(const int sprite_id, const glm::vec2& position, const glm::vec2& size) {
  _objects.emplace_back(sprite_id, position, size);
  return static_cast<int>(_objects.size()) - 1;
}
