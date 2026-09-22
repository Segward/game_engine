#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <sprite.hpp>
#include <mesh.hpp>

class Block {
  public:
    Block(const int sprite_id, const glm::vec2& position, const glm::vec2& size, const b2BodyType type);
    ~Block();

    Block(const Block&) = delete;
    Block& operator=(const Block&) = delete;
    Block(Block&&) noexcept;
    Block& operator=(Block&&) = delete;

    void set_body_type(const b2BodyType type) { b2Body_SetType(_body_id, type); }
    Sprite& get_sprite() const { return Store<Sprite>::instance().get(_sprite_id); }
    const Instance get_instance() const;

  private:
    b2BodyId _body_id{b2_nullBodyId};
    int _sprite_id;
    glm::vec2 _position;
    glm::vec2 _size;
};

#endif
