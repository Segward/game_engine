#include <camera.hpp>
#include <window.hpp>

Camera& Camera::instance() {
  static Camera camera;
  return camera;
}

void Camera::update() {
  Window& window = Window::instance();
  _projection = glm::ortho(0.0f, window.get_width(), 0.0f, window.get_height());
}
