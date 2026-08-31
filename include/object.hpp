#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <store.hpp>
#include <sprite.hpp>

class Object {
  public:
    Object(int sprite_id, const glm::vec2& position, const glm::vec2& size);

    Object(const Object&) = delete;
    Object& operator=(const Object&) = delete;
    Object(Object&&) noexcept = default;
    Object& operator=(Object&&) = delete;

    int get_sprite_id() const { return _sprite_id; }
    const Sprite& get_sprite() const { return Store<Sprite>::instance().get(_sprite_id); }
    glm::vec2 get_position() const { return _position; }
    glm::vec2 get_size() const { return _size; }

  private:
    int _sprite_id;
    glm::vec2 _position;
    glm::vec2 _size;
};

#endif
