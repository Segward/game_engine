#include <init.hpp>
#include <object.hpp>
#include <quad.hpp>
#include <window.hpp>
#include <world.hpp>

int main() {
  try {
    init::all();
    Window& window = Window::instance();
    World& world = World::instance();

    Object floor(b2_staticBody);
    Object box_a(b2_dynamicBody);
    Object box_b(b2_dynamicBody);
    Object box_c(b2_dynamicBody);
    Object box_d(b2_dynamicBody);

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
