#include <renderer.hpp>
#include <window.hpp>
#include <world.hpp>
#include <camera.hpp>
#include <quad.hpp>

void renderer::render() {
  Window& window = Window::instance();
  World& world = World::instance();
  Camera& camera = Camera::instance();
  Quad& quad = Quad::instance();

  glClear(GL_COLOR_BUFFER_BIT);

  camera.update();
  quad.set_projection(camera.get_projection());
  quad.set_view(camera.get_view());

  world.draw_background();
  world.draw_objects();

  window.swap_buffers();
}
