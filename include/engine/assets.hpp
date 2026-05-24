#ifndef ASSETS_HPP
#define ASSETS_HPP

#include <texture.hpp>

class Assets {
  public:
    static Assets& instance();

    Assets(const Assets&) = delete;
    Assets(Assets&&) = delete;
    Assets& operator=(const Assets&) = delete;
    Assets& operator=(Assets&&) = delete;

    const Texture& get_texture(const char* path);

  private:
    Assets() = default;

    std::unordered_map<std::string, std::unique_ptr<Texture>> _textures;
};

#endif
