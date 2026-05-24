#include <assets.hpp>

Assets& Assets::instance() {
  static Assets assets;
  return assets;
}

const Texture& Assets::get_texture(const char* path) {
  auto it = _textures.find(path);
  if (it != _textures.end()) {
    return *it->second;
  }

  auto [inserted, _] = _textures.emplace(path, std::make_unique<Texture>(path));
  return *inserted->second;
}
