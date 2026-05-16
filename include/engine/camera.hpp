#ifndef CAMERA_HPP
#define CAMERA_HPP

class Window;
class Object;

class Camera {
  public:
    Camera(int viewport_width, int viewport_height);

    void update(const Window& window, float dt);
    void zoom_by(float factor);
    void set_viewport(int width, int height);
    void set_target(const Object* target) { _target = target; }

    glm::mat4 view_projection() const;

    glm::vec2 position{0.0f, 0.0f};
    float zoom{1.0f};

  private:
    int _viewport_width;
    int _viewport_height;
    const Object* _target{nullptr};
};

#endif
