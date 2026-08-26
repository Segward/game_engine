#include <init.hpp>
#include <iostream>
#include <window.hpp>
#include <quad.hpp>

int main() {
  try {
    init::glfw();
    Window& window = Window::instance();
    init::glad();
    init::textures();

    while (!window.should_close()) {
      window.poll_events();

      if (window.key_pressed(GLFW_KEY_ESCAPE)) {
        window.set_should_close(true);
      }

      glClear(GL_COLOR_BUFFER_BIT);

      Quad::instance().draw({0.0f, 0.0f}, {64.0f, 64.0f}, sprite::grass_center);

      window.swap_buffers();
    }
  } catch (const std::exception& exception) {
    std::cout << exception.what() << "\n";
  }

  return 0;
}
