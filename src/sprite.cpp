#include <sprite.hpp>

Sprite& sprite::granny() {
  static Sprite sprite{
    .texture = &texture::granny(),
    .uv_offset = {0.0f, 0.0f},
    .uv_scale = {1.0f, 1.0f}
  };

  return sprite;
}

Sprite& sprite::half_granny() {
  static Sprite sprite{
    .texture = &texture::granny(),
    .uv_offset = {0.25f, 0.25f},
    .uv_scale = {0.5f, 0.5f}
  };

  return sprite;
}
