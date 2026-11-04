#include <renderer.hpp>
#include <sun.hpp>

Renderer& Renderer::instance() {
  static Renderer renderer;
  return renderer;
}

void Renderer::render() {
  const glm::vec3& sky_color = Sun::instance().get_sky_color();
  glClearColor(sky_color.r, sky_color.g, sky_color.b, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  _camera.update();
  _triangle.set_projection(_camera.get_projection());
  _triangle.set_view(_camera.get_view());
  _terrain.draw();
  _window.swap_buffers();
}
