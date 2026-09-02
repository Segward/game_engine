#ifndef TEXTURE_HPP
#define TEXTURE_HPP

class Texture {
  public:
    Texture(const std::string& texture_path);
    ~Texture() { if (_handle) glDeleteTextures(1, &_handle); }

    Texture(const Texture&) = delete;
    Texture& operator=(const Texture&) = delete;
    Texture(Texture&&) noexcept;
    Texture& operator=(Texture&&) = delete;

    void bind() const;

    const glm::vec2& get_size() const { return _size; }
    float get_width() const { return _size.x; }
    float get_height() const { return _size.y; }

  private:
    GLuint _handle{0};
    glm::vec2 _size{0.0f};
};

#endif
