#ifndef CAMERA_HPP
#define CAMERA_HPP

class Camera {
  public:
    static Camera& instance();

    Camera(const Camera&) = delete;
    Camera& operator=(const Camera&) = delete;
    Camera(Camera&&) = delete;
    Camera& operator=(Camera&&) = delete;

    void update();
    const glm::mat4& get_projection() const { return _projection; }

  private:
    glm::mat4 _projection{0};

    Camera() = default;
};

#endif
