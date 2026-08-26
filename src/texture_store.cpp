#include <texture_store.hpp>

TextureStore& TextureStore::instance() {
  static TextureStore store;
  return store;
}

int TextureStore::store(const std::string& texture_path) {
  _textures.emplace_back(texture_path);
  return static_cast<int>(_textures.size()) - 1;
}
