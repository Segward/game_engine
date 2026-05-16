#include "engine/objects/player.hpp"

#include "engine/graphics/window.hpp"

void Player::update(float delta, const Window& window) {
  glm::vec2 dir{0.0f, 0.0f};

  if (window.key_pressed(GLFW_KEY_W)) dir.y += 1.0f;
  if (window.key_pressed(GLFW_KEY_S)) dir.y -= 1.0f;
  if (window.key_pressed(GLFW_KEY_D)) dir.x += 1.0f;
  if (window.key_pressed(GLFW_KEY_A)) dir.x -= 1.0f;

  if (dir.x != 0.0f || dir.y != 0.0f) {
    velocity = glm::normalize(dir) * speed;
  } else {
    velocity = {0.0f, 0.0f};
  }
}
