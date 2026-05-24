#include <object.hpp>
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
  _objects.clear();
  b2DestroyWorld(_id);
}

Object& World::create_object(b2BodyType type) {
  _objects.push_back(std::make_unique<Object>(_id, type));
  return *_objects.back();
}

void World::render() const {
  for (const auto& object : _objects) {
    object->render();
  }
}

void World::step() {
  b2World_Step(_id, TIMESTEP, SUB_STEPS);
}
