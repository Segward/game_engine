#ifndef OBJECT_HPP
#define OBJECT_HPP

class Object {
  public:
    Object(b2WorldId world, b2BodyType type);
    ~Object();

    Object(const Object&) = delete;
    Object(Object&&) = delete;
    Object& operator=(const Object&) = delete;
    Object& operator=(Object&&) = delete;

    glm::vec3 color() const { return _color; }
    glm::vec2 size() const { return _size; }

    glm::vec2 position() const;
    void render() const;
    float rotation() const;
    void set_color(const glm::vec3& color) { _color = color; }
    void set_position(const glm::vec2& position);
    void set_rotation(float rotation);
    void set_size(const glm::vec2& size);

  private:
    b2BodyId _body;
    b2ShapeId _shape;
    glm::vec2 _size = {50.0f, 50.0f};
    glm::vec3 _color = {0.5f, 0.5f, 0.5f};
};

#endif
