#include <object.hpp>
#include <sprite_store.hpp>

Object::Object(const int sprite_id, const glm::vec2& position, const glm::vec2& size) : _sprite_id(sprite_id), _position(position), _size(size) {}

const int Object::get_texture_id() const {
  return SpriteStore::instance().get_sprite(_sprite_id).get_texture_id();
}
