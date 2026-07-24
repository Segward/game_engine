#include <init.hpp>
#include <window.hpp>
#include <quad.hpp>
#include <texture.hpp>

int main() {
  try {
    init::glfw();
    Window& window = Window::instance();
    init::glad();
    Quad& quad = Quad::instance();
    Texture texture("assets/granny.png");

    while (!window.should_close()) {
      window.poll_events();

      if (window.key_pressed(GLFW_KEY_ESCAPE)) {
        window.set_should_close(true);
      }

      glClear(GL_COLOR_BUFFER_BIT);
      quad.draw({0.0f, 0.0f}, {0.5f, 0.5f}, texture);
      window.swap_buffers();
    }
  } catch (const std::exception& exception) {
    std::cout << exception.what() << "\n";
  }

  return 0;
}
