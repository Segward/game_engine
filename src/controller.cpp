#include <controller.hpp>

namespace {
  float velocity_speed = 500.0f;
  float zoom_speed = 1.0f;
}

Controller& Controller::instance() {
  static Controller controller;
  return controller;
}

void Controller::handle_events() {
  if (_window.key_pressed(GLFW_KEY_W)) _camera.move({0.0f, velocity_speed});
  if (_window.key_pressed(GLFW_KEY_A)) _camera.move({-velocity_speed, 0.0f});
  if (_window.key_pressed(GLFW_KEY_S)) _camera.move({0.0f, -velocity_speed});
  if (_window.key_pressed(GLFW_KEY_D)) _camera.move({velocity_speed, 0.0f});

  if (_window.key_pressed(GLFW_KEY_I)) _camera.zoom(zoom_speed);
  if (_window.key_pressed(GLFW_KEY_O)) _camera.zoom(-zoom_speed);
}
