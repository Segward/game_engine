#ifndef SPRITE_STORE_HPP
#define SPRITE_STORE_HPP

#include <sprite.hpp>

class SpriteStore {
  public:
    static SpriteStore& instance();

    SpriteStore(const SpriteStore&) = delete;
    SpriteStore& operator=(const SpriteStore&) = delete;
    SpriteStore(SpriteStore&&) = delete;
    SpriteStore& operator=(SpriteStore&&) = delete;

    int store(const int texture_id, const glm::vec2 uv_offset, const glm::vec2 uv_scale);
    const Sprite& get_sprite(const int sprite_id) { return _sprites[sprite_id]; }

  private:
    std::vector<Sprite> _sprites;

    SpriteStore() = default;
};

#endif
