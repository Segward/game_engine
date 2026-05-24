#include <engine.hpp>
#include <object.hpp>
#include <world.hpp>

int main() {
  try {
    Engine& engine = Engine::instance();
    World& world = World::instance();

    Object& floor = world.create_object(b2_staticBody);
    floor.set_size({1200.0f, 40.0f});
    floor.set_position({0.0f, -300.0f});
    floor.set_texture("assets/grass.jpg");
    floor.set_tiled(true);

    Object& box_a = world.create_object(b2_dynamicBody);
    box_a.set_size({100.0f, 100.0f});
    box_a.set_position({-200.0f, 100.0f});
    box_a.set_texture("assets/crate.png");

    Object& box_b = world.create_object(b2_dynamicBody);
    box_b.set_size({150.0f, 150.0f});
    box_b.set_position({50.0f, 200.0f});
    box_b.set_texture("assets/crate.png");

    Object& box_c = world.create_object(b2_dynamicBody);
    box_c.set_size({100.0f, 100.0f});
    box_c.set_position({200.0f, 400.0f});
    box_c.set_texture("assets/crate.png");

    engine.run();
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
