#include <controller.hpp>

Controller& Controller::instance() {
  static Controller controller;
  return controller;
}

void Controller::handle_events() {
  if (_window.key_pressed(GLFW_KEY_W)) _camera.move({0.0f, 0.1f});
  if (_window.key_pressed(GLFW_KEY_A)) _camera.move({-0.1f, 0.0f});
  if (_window.key_pressed(GLFW_KEY_S)) _camera.move({0.0f, -0.1f});
  if (_window.key_pressed(GLFW_KEY_D)) _camera.move({0.1f, 0.0f});
}
