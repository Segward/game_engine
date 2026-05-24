#include <init.hpp>
#include <object.hpp>
#include <quad.hpp>
#include <window.hpp>
#include <world.hpp>

int main() {
  try {
    init::glfw();
    Window& window = Window::instance();
    init::glad();
    World& world = World::instance();
    Quad::instance();

    Object floor({0.0f, -300.0f}, {1000.0f, 50.0f}, {0.3f, 0.3f, 0.3f}, b2_staticBody);
    Object box_a({-200.0f, 100.0f}, {80.0f, 80.0f}, {1.0f, 0.3f, 0.2f}, b2_dynamicBody);
    Object box_b({-50.0f, 200.0f}, {60.0f, 60.0f}, {0.2f, 0.8f, 0.4f}, b2_dynamicBody);
    Object box_c({100.0f, 50.0f}, {100.0f, 100.0f}, {0.3f, 0.5f, 1.0f}, b2_dynamicBody);
    Object box_d({250.0f, 250.0f}, {70.0f, 70.0f}, {1.0f, 0.9f, 0.3f}, b2_dynamicBody);

    while (!window.should_close()) {
      window.poll_events();

      if (window.key_pressed(GLFW_KEY_ESCAPE)) {
        window.set_should_close(true);
      }

      world.step();

      glClear(GL_COLOR_BUFFER_BIT);
      floor.render();
      box_a.render();
      box_b.render();
      box_c.render();
      box_d.render();
      window.swap_buffers();
    }
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
