#include <engine.hpp>
#include <init.hpp>

Engine& Engine::instance() {
  static Engine engine;
  return engine;
}

void Engine::init() {
  init::textures();
  init::sprites();
  init::objects();
}

void Engine::start() {
  while (!_window.should_close()) {
    _window.poll_events();

    if (_window.key_pressed(GLFW_KEY_ESCAPE)) {
      _window.set_should_close(true);
    }

    _renderer.draw();

    _window.swap_buffers();
  }
}
