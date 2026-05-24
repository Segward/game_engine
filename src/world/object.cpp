#include <object.hpp>
#include <quad.hpp>
#include <world.hpp>

Object::Object(b2WorldId world, b2BodyType type) {
  b2BodyDef body_def = b2DefaultBodyDef();
  body_def.type = type;
  body_def.enableSleep = false;
  _body = b2CreateBody(world, &body_def);

  float half_width = _size.x * 0.5f / World::PIXELS_PER_METER;
  float half_height = _size.y * 0.5f / World::PIXELS_PER_METER;
  b2Polygon polygon = b2MakeBox(half_width, half_height);

  b2ShapeDef shape_def = b2DefaultShapeDef();
  shape_def.density = 1.0f;
  shape_def.material.restitution = 0.8f;
  _shape = b2CreatePolygonShape(_body, &shape_def, &polygon);
}

Object::~Object() {
  b2DestroyBody(_body);
}

glm::vec2 Object::position() const {
  b2Vec2 position_meters = b2Body_GetPosition(_body);
  float x = position_meters.x * World::PIXELS_PER_METER;
  float y = position_meters.y * World::PIXELS_PER_METER;
  return {x, y};
}

void Object::render() const {
  b2Vec2 position_meters = b2Body_GetPosition(_body);
  float x = position_meters.x * World::PIXELS_PER_METER;
  float y = position_meters.y * World::PIXELS_PER_METER;
  glm::vec2 position_pixels = {x, y};

  b2Rot rotation = b2Body_GetRotation(_body);
  glm::vec2 rotation_basis = {rotation.c, rotation.s};

  Quad::instance().render(position_pixels, _size, rotation_basis, _color);
}

float Object::rotation() const {
  b2Rot body_rotation = b2Body_GetRotation(_body);
  return b2Rot_GetAngle(body_rotation);
}

void Object::set_position(const glm::vec2& position) {
  float x = position.x / World::PIXELS_PER_METER;
  float y = position.y / World::PIXELS_PER_METER;
  b2Vec2 position_meters = {x, y};
  b2Rot current_rotation = b2Body_GetRotation(_body);
  b2Body_SetTransform(_body, position_meters, current_rotation);
}

void Object::set_rotation(float rotation) {
  b2Vec2 current_position = b2Body_GetPosition(_body);
  b2Rot new_rotation = b2MakeRot(rotation);
  b2Body_SetTransform(_body, current_position, new_rotation);
}

void Object::set_size(const glm::vec2& size) {
  _size = size;
  float half_width = size.x * 0.5f / World::PIXELS_PER_METER;
  float half_height = size.y * 0.5f / World::PIXELS_PER_METER;
  b2Polygon polygon = b2MakeBox(half_width, half_height);
  b2Shape_SetPolygon(_shape, &polygon);
}
