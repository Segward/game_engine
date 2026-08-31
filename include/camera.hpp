#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <time.hpp>

class Camera {
  public:
    static Camera& instance();

    Camera(const Camera&) = delete;
    Camera& operator=(const Camera&) = delete;
    Camera(Camera&&) = delete;
    Camera& operator=(Camera&&) = delete;

    void update();

    void move(const glm::vec2& position) { _position += position * Time::instance().get_fps(); }
    const glm::vec2& get_position() const { return _position; }
    const glm::mat4& get_projection() const { return _projection; }
    const glm::mat4& get_view() const { return _view; }

  private:
    glm::vec2 _position{0.0f};
    glm::mat4 _projection{0};
    glm::mat4 _view{0};

    Camera() = default;
};

#endif
