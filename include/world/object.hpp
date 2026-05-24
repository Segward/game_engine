#ifndef OBJECT_HPP
#define OBJECT_HPP

class Texture;

class Object {
  public:
    Object(b2WorldId world, b2BodyType type);
    ~Object();

    Object(const Object&) = delete;
    Object(Object&&) = delete;
    Object& operator=(const Object&) = delete;
    Object& operator=(Object&&) = delete;

    glm::vec2 size() const { return _size; }

    glm::vec2 position() const;
    void render() const;
    float rotation() const;
    void set_position(const glm::vec2& position);
    void set_rotation(float rotation);
    void set_size(const glm::vec2& size);
    void set_texture(const char* path);
    void set_tiled(bool tiled) { _tiled = tiled; }

  private:
    b2BodyId _body;
    b2ShapeId _shape;
    glm::vec2 _size = {50.0f, 50.0f};
    const Texture* _texture{nullptr};
    bool _tiled{false};
};

#endif
