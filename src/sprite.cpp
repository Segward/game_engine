#include <sprite.hpp>

Sprite::Sprite(int texture_id, const glm::vec2& uv_offset, const glm::vec2& uv_scale) : _texture_id(texture_id), _uv_offset(uv_offset), _uv_scale(uv_scale) {}
