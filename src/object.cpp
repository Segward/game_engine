#include <object.hpp>
#include <store.hpp>
#include <sprite.hpp>

Object::Object(const int sprite_id, const glm::vec2& position, const glm::vec2& size) : _sprite_id(sprite_id), _position(position), _size(size) {}

const int Object::get_texture_id() const {
  return Store<Sprite>::instance().get(_sprite_id).get_texture_id();
}
