#include <world.hpp>

World& World::instance() {
  static World world;
  return world;
}

World::World() {
  b2WorldDef world_def = b2DefaultWorldDef();
  world_def.gravity = GRAVITY;
  world_def.restitutionThreshold = 0.0f;
  _id = b2CreateWorld(&world_def);
}

World::~World() {
  b2DestroyWorld(_id);
}

void World::step() {
  b2World_Step(_id, 1.0f / 60.0f, 4);
}
