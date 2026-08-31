#include <object.hpp>
#include <store.hpp>
#include <sprite.hpp>

Object::Object(int sprite_id, const glm::vec2& position, const glm::vec2& size) : _sprite_id(sprite_id), _position(position), _size(size) {}
