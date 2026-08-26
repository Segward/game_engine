#include <camera.hpp>
#include <window.hpp>

Camera& Camera::instance() {
  static Camera camera;
  return camera;
}

void Camera::update() {
  Window& window = Window::instance();
  float width = static_cast<float>(window.get_width());
  float height = static_cast<float>(window.get_height());
  _projection = glm::ortho(0.0f, width, 0.0f, height);
}
