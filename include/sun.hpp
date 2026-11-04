#ifndef SUN_HPP
#define SUN_HPP

class Sun {
  public:
    static Sun& instance();

    Sun(const Sun&) = delete;
    Sun& operator=(const Sun&) = delete;
    Sun(Sun&&) = delete;
    Sun& operator=(Sun&&) = delete;

    void update();

    const glm::vec3& get_direction() const { return _direction; }
    const glm::vec3& get_color() const { return _color; }
    const glm::vec3& get_ambient() const { return _ambient; }
    const glm::vec3& get_sky_color() const { return _sky_color; }

  private:
    float _angle{0.6f};
    glm::vec3 _direction{0.0f, 1.0f, 0.0f};
    glm::vec3 _color{0.0f};
    glm::vec3 _ambient{0.0f};
    glm::vec3 _sky_color{0.0f};

    Sun() = default;
};

#endif
