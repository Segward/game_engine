#include <global.hpp>
#include <init.hpp>

int main() {
  try {
    Init::glfw();

    Window& window = Global::instance().window;

    Init::glad();
    while (!window.should_close()) {
      window.poll_events();

      if (window.key_pressed(GLFW_KEY_ESCAPE)) {
        window.set_should_close(true);
      }

      glClear(GL_COLOR_BUFFER_BIT);
      window.swap_buffers();
    }
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    glfwTerminate();
    return EXIT_FAILURE;
  }

  glfwTerminate();
  return EXIT_SUCCESS;
}
