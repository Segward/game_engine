#ifndef OBJECT_HPP
#define OBJECT_HPP

class Window;

class Object {
  public:
    virtual ~Object() = default;

    virtual void update(float delta, const Window& window) {}

    glm::vec2 aabb_min() const { return position - size * 0.5f; }
    glm::vec2 aabb_max() const { return position + size * 0.5f; }
    bool overlaps(const Object& other) const {
      return aabb_min().x < other.aabb_max().x &&
             aabb_max().x > other.aabb_min().x &&
             aabb_min().y < other.aabb_max().y &&
             aabb_max().y > other.aabb_min().y;
    }

    glm::vec2 position{0.0f, 0.0f};
    glm::vec2 size{1.0f, 1.0f};
    glm::vec4 color{1.0f, 1.0f, 1.0f, 1.0f};
    glm::vec2 velocity{0.0f, 0.0f};
    bool solid{true};
};

#endif
