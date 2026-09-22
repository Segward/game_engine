#include <init.hpp>
#include <window.hpp>
#include <controller.hpp>
#include <renderer.hpp>
#include <world.hpp>
#include <physics.hpp>
#include <time.hpp>

int main() {
  try {
    init::glfw();
    Window& window = Window::instance();
    init::glad();

    Physics& physics = Physics::instance();
    World& world = World::instance();
    Controller& controller = Controller::instance();
    Renderer& renderer = Renderer::instance();
    Time& time = Time::instance();

    init::textures();
    init::sprites();
    world.generate();

    while (!window.should_close()) {
      window.poll_events();
      time.update();
      controller.handle_events();
      physics.step();
      renderer.render();
    }
  } catch (const std::exception& exception) {
    std::cout << exception.what() << "\n";
  }

  return 0;
}
