#ifndef SPRITE_HPP
#define SPRITE_HPP

struct Sprite {
  int id;
  glm::vec2 uv_offset;
  glm::vec2 uv_scale;
};

namespace sprite {
  inline Sprite grass_up_left{0, {0.0f / 64.0f, 0.0f / 64.0f}, {16.0f / 64.0f, 16.0f / 64.0f}};
  inline Sprite grass_up{0, {16.0f / 64.0f, 0.0f / 64.0f}, {16.0f / 64.0f, 16.0f / 64.0f}};
  inline Sprite grass_up_right{0, {32.0f / 64.0f, 0.0f / 64.0f}, {16.0f / 64.0f, 16.0f / 64.0f}};
  inline Sprite grass_center_left{0, {0.0f / 64.0f, 16.0f / 64.0f}, {16.0f / 64.0f, 16.0f / 64.0f}};
  inline Sprite grass_center{0, {16.0f / 64.0f, 16.0f / 64.0f}, {16.0f / 64.0f, 16.0f / 64.0f}};
  inline Sprite grass_center_right{0, {32.0f / 64.0f, 16.0f / 64.0f}, {16.0f / 64.0f, 16.0f / 64.0f}};
  inline Sprite grass_down_left{0, {0.0f / 64.0f, 32.0f / 64.0f}, {16.0f / 64.0f, 16.0f / 64.0f}};
  inline Sprite grass_down{0, {16.0f / 64.0f, 32.0f / 64.0f}, {16.0f / 64.0f, 16.0f / 64.0f}};
  inline Sprite grass_down_right{0, {32.0f / 64.0f, 32.0f / 64.0f}, {16.0f / 64.0f, 16.0f / 64.0f}};
}

#endif
