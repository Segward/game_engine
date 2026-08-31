#include <init.hpp>
#include <window.hpp>
#include <camera.hpp>
#include <renderer.hpp>

int main() {
  try {
    init::glfw();
    Window& window = Window::instance();
    init::glad();

    init::textures();
    init::sprites();
    init::objects();

    Camera& camera = Camera::instance();
    Renderer& renderer = Renderer::instance();

    while (!window.should_close()) {
      window.poll_events();

      if (window.key_pressed(GLFW_KEY_W)) {
        camera.move({0.0f, 0.1f});
      }

      if (window.key_pressed(GLFW_KEY_A)) {
        camera.move({-0.1f, 0.0f});
      }

      if (window.key_pressed(GLFW_KEY_S)) {
        camera.move({0.0f, -0.1f});
      }

      if (window.key_pressed(GLFW_KEY_D)) {
        camera.move({0.1f, 0.0f});
      }

      renderer.render();
    }
  } catch (const std::exception& exception) {
    std::cout << exception.what() << "\n";
  }

  return 0;
}
