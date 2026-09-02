#include <renderer.hpp>

Renderer& Renderer::instance() {
  static Renderer renderer;
  return renderer;
}

void Renderer::render() {
  _time.update();

  glClear(GL_COLOR_BUFFER_BIT);

  _camera.update();
  
  _quad.set_projection(_camera.get_projection());
  _quad.set_view(_camera.get_view());

  _background.draw();
  _world.draw();

  _window.swap_buffers();
}
