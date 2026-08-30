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

    void bind(GLuint unit = 0) const;

    const int get_width() const { return _width; }
    const int get_height() const { return _height; }

  private:
    GLuint _handle{0};
    int _width{0};
    int _height{0};
};

namespace texture_handle {
  Texture& sprite_sheet();
}

#endif
