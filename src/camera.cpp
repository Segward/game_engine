#include <camera.hpp>
#include <window.hpp>

Camera& Camera::instance() {
  static Camera camera;
  return camera;
}

void Camera::update() {
  Window& window = Window::instance();
  float half_width = window.get_width() * 0.5f;
  float half_height = window.get_height() * 0.5f;

  _projection = glm::ortho(-half_width, half_width, -half_height, half_height);
  _view = glm::translate(glm::mat4(1.0f), glm::vec3(-_position, 0.0f));
}
