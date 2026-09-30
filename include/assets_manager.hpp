#ifndef ASSETS_MANAGER_HPP
#define ASSETS_MANAGER_HPP

#include <texture.hpp>
#include <sprite.hpp>

class AssetsManager {
  public:
    static AssetsManager& instance();

    AssetsManager(const AssetsManager&) = delete;
    AssetsManager& operator=(const AssetsManager&) = delete;
    AssetsManager(AssetsManager&&) = delete;
    AssetsManager& operator=(AssetsManager&&) = delete;

    Texture& get_texture(int id) { return _textures[id]; }
    void emplace_texture_back(const std::string& path) { _textures.emplace_back(path); }
    std::vector<Texture>& get_all_textures() { return _textures; }

    Sprite& get_sprite(int id) { return _sprites[id]; }
    void emplace_sprite_back(int texture_id, const glm::vec2& uv_offset, const glm::vec2& uv_scale) { _sprites.emplace_back(texture_id, uv_offset, uv_scale); }
    std::vector<Sprite>& get_all_sprites() { return _sprites; }

  private:
    std::vector<Texture> _textures;
    std::vector<Sprite> _sprites;

    AssetsManager() = default;
    ~AssetsManager() = default;
};

#endif
