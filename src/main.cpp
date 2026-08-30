#include <init.hpp>
#include <window.hpp>
#include <renderer.hpp>

int main() {
  try {
    init::glfw();
    Window& window = Window::instance();
    init::glad();
    init::renderer();
    init::textures();
    init::sprites();
    init::objects();

    while (!window.should_close()) {
      window.poll_events();

      if (window.key_pressed(GLFW_KEY_ESCAPE)) {
        window.set_should_close(true);
      }

      renderer::render();
    }
  } catch (const std::exception& exception) {
    std::cout << exception.what() << "\n";
  }

  return 0;
}
