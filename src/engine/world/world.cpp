#include "engine/world/world.hpp"

#include "engine/graphics/quad.hpp"

Object& World::add(std::unique_ptr<Object> object) {
  _objects.push_back(std::move(object));
  return *_objects.back();
}

void World::draw(const glm::mat4& view_projection, const Quad& quad) const {
  for (const auto& object : _objects) {
    quad.draw(object->position, object->size, object->color, view_projection);
  }
}
