#ifndef OBJECT_HPP
#define OBJECT_HPP

class Object {
public:
  glm::vec2 size;
  glm::vec3 color;
  b2BodyId body;

  Object(const glm::vec2& position, const glm::vec2& size, const glm::vec3& color, b2BodyType type);

  void render() const;
};

#endif
