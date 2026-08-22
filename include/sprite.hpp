#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <texture.hpp>

struct Sprite {
  const Texture* texture;
  glm::vec2 uv_offset;
  glm::vec2 uv_scale;
};

namespace sprite {
  Sprite& granny();
  Sprite& half_granny();
}

#endif
