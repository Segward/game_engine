#include <physics.hpp>

namespace {
  float pixels_per_meter = 50.0f;
  float gravity = -9.81f * pixels_per_meter;
  float time_step = 1.0f / 60.0f;
  int sub_step_count = 4;
}

Physics& Physics::instance() {
  static Physics physics;
  return physics;
}

Physics::Physics() {
  b2WorldDef world_def = b2DefaultWorldDef();
  world_def.gravity = (b2Vec2){0.0f, gravity};
  _world_id = b2CreateWorld(&world_def);
}

Physics::~Physics() {
  if (!b2World_IsValid(_world_id)) return;
  b2DestroyWorld(_world_id);
}

void Physics::step() {
  b2World_Step(_world_id, time_step, sub_step_count);
}
