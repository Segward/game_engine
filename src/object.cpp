#include <object.hpp>
#include <quad.hpp>
#include <world.hpp>

Object::Object(const glm::vec2& position, const glm::vec2& size, const glm::vec3& color, b2BodyType type)
    : size(size), color(color) {
  b2BodyDef body_def = b2DefaultBodyDef();
  body_def.type = type;
  body_def.position = {position.x / World::PIXELS_PER_METER, position.y / World::PIXELS_PER_METER};
  body_def.enableSleep = false;
  body = b2CreateBody(World::instance().id(), &body_def);

  b2Polygon polygon = b2MakeBox(
      size.x * 0.5f / World::PIXELS_PER_METER,
      size.y * 0.5f / World::PIXELS_PER_METER);

  b2ShapeDef shape_def = b2DefaultShapeDef();
  shape_def.density = 1.0f;
  shape_def.material.restitution = 0.8f;
  b2CreatePolygonShape(body, &shape_def, &polygon);
}

void Object::render() const {
  b2Vec2 position_meters = b2Body_GetPosition(body);
  b2Rot rotation = b2Body_GetRotation(body);
  glm::vec2 position_pixels = {
      position_meters.x * World::PIXELS_PER_METER,
      position_meters.y * World::PIXELS_PER_METER,
  };

  Quad::instance().render(position_pixels, size, {rotation.c, rotation.s}, color);
}
