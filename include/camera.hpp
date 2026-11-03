#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <time.hpp>
#include <window.hpp>

class Camera {
  public:
    static Camera& instance();

    Camera(const Camera&) = delete;
    Camera& operator=(const Camera&) = delete;
    Camera(Camera&&) = delete;
    Camera& operator=(Camera&&) = delete;

    void update();
    void move(const glm::vec3& direction);
    void rotate(const glm::vec2& offset);

    const glm::vec3& get_position() const { return _position; }
    const glm::mat4& get_projection() const { return _projection; }
    const glm::mat4& get_view() const { return _view; }

  private:
    Window& _window{Window::instance()};

    glm::vec3 _position{0.0f, 35.0f, 90.0f};
    float _yaw{-90.0f};
    float _pitch{-25.0f};
    glm::mat4 _projection{0};
    glm::mat4 _view{0};

    glm::vec3 front() const;

    Camera() = default;
};

#endif
