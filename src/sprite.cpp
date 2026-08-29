#include <sprite.hpp>
#include <quad.hpp>
#include <texture_store.hpp>
#include <camera.hpp>

Sprite::Sprite(const int texture_id, const glm::vec2& uv_offset, const glm::vec2& uv_scale) : _texture_id(texture_id), _uv_offset(uv_offset), _uv_scale(uv_scale) {}

void Sprite::draw(const glm::vec2& position, const glm::vec2& size) {
}
