#ifndef SPRITE_HPP
#define SPRITE_HPP

class Sprite {
  public:
    Sprite(const int texture_id, const glm::vec2& uv_offset, const glm::vec2& uv_scale);

    Sprite(const Sprite&) = delete;
    Sprite& operator=(const Sprite&) = delete;
    Sprite(Sprite&&) noexcept = default;
    Sprite& operator=(Sprite&&) = delete;

    void draw(const glm::vec2& position, const glm::vec2& size);

    const int get_texture_id() const { return _texture_id; }
    const glm::vec2 get_uv_offset() const { return _uv_offset; }
    const glm::vec2 get_uv_scale() const { return _uv_scale; }

  private:
    int _texture_id;
    glm::vec2 _uv_offset;
    glm::vec2 _uv_scale;
};

#endif
