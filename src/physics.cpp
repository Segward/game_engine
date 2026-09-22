#include <physics.hpp>

namespace {
  bool on_overlap(b2ShapeId shape_id, void* context) {
    std::vector<Block*>* render_blocks = static_cast<std::vector<Block*>*>(context);
    Block* block = static_cast<Block*>(b2Body_GetUserData(b2Shape_GetBody(shape_id)));
    render_blocks->push_back(block);
    return true;
  }
}

Physics& Physics::instance() {
  static Physics physics;
  return physics;
}

Physics::Physics() {
  b2WorldDef world_def = b2DefaultWorldDef();
  world_def.gravity = (b2Vec2){0.0f, -9.81f * 50.0f};
  _world_id = b2CreateWorld(&world_def);
}

Physics::~Physics() {
  if (!b2World_IsValid(_world_id)) return;
  b2DestroyWorld(_world_id);
}

void Physics::step() {
  b2World_Step(_world_id, 1.0f / 60.0f, 4);
  _render_blocks.clear();

  const glm::vec2 position = _camera.get_position();
  const glm::vec2 half_view = _window.get_size() * 0.6f / _camera.get_zoom();
  const glm::vec2 minimum = position - half_view;
  const glm::vec2 maximum = position + half_view;

  b2World_OverlapAABB(_world_id, {{minimum.x, minimum.y}, {maximum.x, maximum.y}}, b2DefaultQueryFilter(), on_overlap, &_render_blocks);
}
