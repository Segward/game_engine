#include "engine/physics/physics.hpp"

void Physics::step(std::vector<std::unique_ptr<Object>>& objects,
                   float delta, const Window& window) const {
  for (auto& object : objects) {
    object->update(delta, window);
  }

  for (auto& object : objects) {
    if (object->velocity.x == 0.0f && object->velocity.y == 0.0f) continue;

    for (int axis = 0; axis < 2; ++axis) {
      object->position[axis] += object->velocity[axis] * delta;
      if (!object->solid) continue;

      for (auto& other : objects) {
        if (other.get() == object.get() || !other->solid) continue;
        if (!object->overlaps(*other)) continue;

        float half_self = object->size[axis] * 0.5f;
        float half_other = other->size[axis] * 0.5f;
        if (object->velocity[axis] > 0.0f) {
          object->position[axis] = other->position[axis] - half_other - half_self;
        } else if (object->velocity[axis] < 0.0f) {
          object->position[axis] = other->position[axis] + half_other + half_self;
        }
        object->velocity[axis] = 0.0f;
        break;
      }
    }
  }
}
