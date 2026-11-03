#include <controller.hpp>

namespace {
  float move_speed = 10.0f;
  float fast_move_speed = 40.0f;
  float mouse_sensitivity = 0.1f;
}

Controller& Controller::instance() {
  static Controller controller;
  return controller;
}

void Controller::handle_events() {
  if (_window.key_pressed(GLFW_KEY_ESCAPE)) _window.set_cursor_captured(false);
  if (!_window.cursor_captured() && _window.mouse_pressed(GLFW_MOUSE_BUTTON_LEFT)) {
    _window.set_cursor_captured(true);
    _previous_cursor = _window.get_cursor_position();
  }

  glm::vec2 cursor = _window.get_cursor_position();
  if (_window.cursor_captured()) _camera.rotate((cursor - _previous_cursor) * mouse_sensitivity);
  _previous_cursor = cursor;

  glm::vec3 direction{0.0f};
  if (_window.key_pressed(GLFW_KEY_W)) direction.z += 1.0f;
  if (_window.key_pressed(GLFW_KEY_S)) direction.z -= 1.0f;
  if (_window.key_pressed(GLFW_KEY_D)) direction.x += 1.0f;
  if (_window.key_pressed(GLFW_KEY_A)) direction.x -= 1.0f;

  if (_window.key_pressed(GLFW_KEY_SPACE)) direction.y += 1.0f;
  if (_window.key_pressed(GLFW_KEY_LEFT_CONTROL)) direction.y -= 1.0f;

  float speed = _window.key_pressed(GLFW_KEY_LEFT_SHIFT) ? fast_move_speed : move_speed;
  _camera.move(direction * speed);
}
