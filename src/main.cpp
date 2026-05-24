#include <engine.hpp>
#include <world.hpp>

int main() {
  try {
    Engine& engine = Engine::instance();
    World& world = World::instance();

    world.create_object(b2_staticBody);
    world.create_object(b2_dynamicBody);
    world.create_object(b2_dynamicBody);
    world.create_object(b2_dynamicBody);
    world.create_object(b2_dynamicBody);

    engine.run();
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
