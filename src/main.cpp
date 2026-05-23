#include <global.hpp>

int main() {
  try {
    Window& window = Global::instance().window();
    Quad& quad = Global::instance().quad();

    while (!window.should_close()) {
      window.poll_events();

      if (window.key_pressed(GLFW_KEY_ESCAPE)) {
        window.set_should_close(true);
      }

      glClear(GL_COLOR_BUFFER_BIT);
      quad.render({0.0f, 0.0f}, {0.5f, 0.5f}, {1.0f, 0.3f, 0.2f});
      window.swap_buffers();
    }
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
