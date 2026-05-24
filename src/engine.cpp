#include <engine.hpp>
#include <init.hpp>
#include <quad.hpp>
#include <window.hpp>
#include <world.hpp>

Engine& Engine::instance() {
  static Engine engine;
  return engine;
}

Engine::Engine() {
  init::glfw();
  Window::instance();
  init::glad();
  World::instance();
  Quad::instance();
}

void Engine::run() {
  Window& window = Window::instance();
  World& world = World::instance();

  while (!window.should_close()) {
    window.poll_events();

    if (window.key_pressed(GLFW_KEY_ESCAPE)) {
      window.set_should_close(true);
    }

    world.step();

    glClear(GL_COLOR_BUFFER_BIT);
    world.render();
    window.swap_buffers();
  }
}
