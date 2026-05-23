#include <global.hpp>
#include <init.hpp>

Global& Global::instance() {
  static Global global;
  return global;
}

Global::Global() {
  try {
    init::glfw();
    _window = std::make_unique<Window>(1280, 720, "game engine");
    init::glad();
  } catch (...) {
    _window.reset();
    glfwTerminate();
    throw;
  }
}

Global::~Global() {
  _window.reset();
  glfwTerminate();
}
