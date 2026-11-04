#include <init.hpp>
#include <window.hpp>
#include <controller.hpp>
#include <renderer.hpp>
#include <terrain.hpp>
#include <time.hpp>

int main() {
  try {
    init::glfw();
    Window& window = Window::instance();
    init::glad();

    Controller& controller = Controller::instance();
    Renderer& renderer = Renderer::instance();
    Time& time = Time::instance();

    Terrain& terrain = Terrain::instance();
    terrain.generate();

    while (!window.should_close()) {
      window.poll_events();
      time.update();
      controller.handle_events();
      renderer.render();
    }
  } catch (const std::exception& exception) {
    std::cout << exception.what() << "\n";
  }

  return 0;
}
