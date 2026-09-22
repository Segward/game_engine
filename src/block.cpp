#include <block.hpp>
#include <box2d/box2d.h>
#include <physics.hpp>

namespace {
  float density = 1.0f;
  float friction = 0.6f;
}

Block::Block(const int sprite_id, const glm::vec2& position, const glm::vec2& size, const b2BodyType type) : _sprite_id(sprite_id), _position(position), _size(size) {
  b2BodyDef body_def = b2DefaultBodyDef();
  body_def.type = type;
  body_def.position = (b2Vec2){position.x, position.y};
  _body_id = b2CreateBody(Physics::instance().get_world_id(), &body_def);

  b2ShapeDef shape_def = b2DefaultShapeDef();
  shape_def.density = density;
  shape_def.material.friction = friction;

  b2Polygon polygon = b2MakeBox(size.x * 0.5f, size.y * 0.5f);
  b2CreatePolygonShape(_body_id, &shape_def, &polygon);
}

Block::~Block() {
  if (!b2Body_IsValid(_body_id)) return;
  b2DestroyBody(_body_id);
}

Block::Block(Block&& other) noexcept : _body_id(other._body_id), _sprite_id(other._sprite_id), _position(other._position), _size(other._size) {
  other._body_id = b2_nullBodyId;
}

const Instance Block::get_instance() const {
  const Sprite& sprite = get_sprite();
  const b2Vec2 position = b2Body_GetPosition(_body_id);
  return {{position.x, position.y}, _size, sprite.get_uv_offset(), sprite.get_uv_scale()};
}
