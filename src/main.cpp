#include <init.hpp>
#include <load.hpp>
#include <window.hpp>
#include <controller.hpp>
#include <renderer.hpp>
#include <world.hpp>

int main() {
  try {
    init::glfw();
    Window& window = Window::instance();
    init::glad();

    Controller& controller = Controller::instance();
    Renderer& renderer = Renderer::instance();

    load::textures();
    load::sprites();

    World::instance().generate();

    while (!window.should_close()) {
      window.poll_events();
      controller.handle_events();
      renderer.render();
    }
  } catch (const std::exception& exception) {
    std::cout << exception.what() << "\n";
  }

  return 0;
}
