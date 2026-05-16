#include "engine/engine.hpp"

Engine::Engine()
  : _window(1280, 720, "window"),
    _quad(),
    _camera(_window.width(), _window.height()),
    _physics(),
    _world() {}

void Engine::run() {
  double last_time = glfwGetTime();

  while (!_window.should_close()) {
    _window.poll_events();

    double now = glfwGetTime();
    float dt = static_cast<float>(now - last_time);
    last_time = now;

    if (_window.key_pressed(GLFW_KEY_ESCAPE)) {
      _window.set_should_close(true);
    }

    _camera.update(_window, dt);
    _camera.set_viewport(_window.width(), _window.height());

    _physics.step(_world.objects(), dt, _window);

    glClearColor(0.10f, 0.10f, 0.12f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    _world.draw(_camera.view_projection(), _quad);

    _window.swap_buffers();
  }
}
