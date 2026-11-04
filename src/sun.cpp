#include <sun.hpp>
#include <time.hpp>

namespace {
  constexpr float day_length = 60.0f;
  const glm::vec3 day_sky{0.55f, 0.75f, 0.95f};
  const glm::vec3 sunset_sky{0.9f, 0.5f, 0.3f};
  const glm::vec3 night_sky{0.04f, 0.05f, 0.12f};
}

Sun& Sun::instance() {
  static Sun sun;
  return sun;
}

void Sun::update() {
  _angle = std::fmod(_angle + glm::two_pi<float>() / day_length * Time::instance().get_delta(), glm::two_pi<float>());

  float height = std::sin(_angle);
  float day = glm::clamp(height * 2.0f, 0.0f, 1.0f);
  float daylight = glm::clamp(height * 4.0f, 0.0f, 1.0f);
  float twilight = glm::clamp(height * 3.0f + 0.3f, 0.0f, 1.0f);

  _direction = glm::normalize(glm::vec3{std::cos(_angle), height, 0.3f});
  _sky_color = glm::mix(night_sky, glm::mix(sunset_sky, day_sky, day), twilight);
  _color = glm::mix(sunset_sky, glm::vec3{1.0f}, day) * 0.6f * daylight;
  _ambient = _sky_color * 0.6f;
}
