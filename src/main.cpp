#include <init.hpp>
#include <window.hpp>

int main() {
  try {
    init::glfw();
    Window& window = Window::instance();

    while (!window.should_close()) {
      window.poll_events();

      if (window.key_pressed(GLFW_KEY_ESCAPE)) {
        window.set_should_close(true);
      }

      glClear(GL_COLOR_BUFFER_BIT);
      window.swap_buffers();
    }
  } catch (const std::exception& exception) {
    std::cout << exception.what() << "\n";
  }

  return 0;
}
