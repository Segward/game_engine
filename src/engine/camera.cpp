#include "engine/camera.hpp"

#include "engine/objects/object.hpp"
#include "engine/graphics/window.hpp"

Camera::Camera(int viewport_width, int viewport_height)
  : _viewport_width{viewport_width}, _viewport_height{viewport_height} {}

void Camera::update(const Window&, float) {
  position = _target->position;
}

void Camera::zoom_by(float factor) {
  zoom *= factor;
}

void Camera::set_viewport(int width, int height) {
  _viewport_width = width;
  _viewport_height = height;
}

glm::mat4 Camera::view_projection() const {
  float aspect = _viewport_height > 0
    ? static_cast<float>(_viewport_width) / static_cast<float>(_viewport_height)
    : 1.0f;
  float half = 1.0f / zoom;

  glm::mat4 projection = glm::ortho(-aspect * half, aspect * half, -half, half, -1.0f, 1.0f);
  glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-position, 0.0f));

  return projection * view;
}
