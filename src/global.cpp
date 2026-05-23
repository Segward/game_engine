#include <global.hpp>
#include <init.hpp>

Global& Global::instance() {
  static Global global;
  return global;
}

Global::Global() {
  init::glfw();
  Window::instance();
  init::glad();
  Quad::instance();
}
