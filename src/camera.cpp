#include <camera.hpp>

namespace {
  const glm::vec3 world_up{0.0f, 1.0f, 0.0f};
}

Camera& Camera::instance() {
  static Camera camera;
  return camera;
}

glm::vec3 Camera::front() const {
  float yaw = glm::radians(_yaw);
  float pitch = glm::radians(_pitch);
  return glm::normalize(glm::vec3{std::cos(yaw) * std::cos(pitch), std::sin(pitch), std::sin(yaw) * std::cos(pitch)});
}

void Camera::move(const glm::vec3& direction) {
  glm::vec3 forward = front();
  glm::vec3 right = glm::normalize(glm::cross(forward, world_up));
  _position += (right * direction.x + world_up * direction.y + forward * direction.z) * Time::instance().get_delta();
}

void Camera::rotate(const glm::vec2& offset) {
  _yaw += offset.x;
  _pitch = glm::clamp(_pitch - offset.y, -89.0f, 89.0f);
}

void Camera::update() {
  _projection = glm::perspective(glm::radians(70.0f), _window.get_width() / _window.get_height(), 0.1f, 1000.0f);
  _view = glm::lookAt(_position, _position + front(), world_up);
}
