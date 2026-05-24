#ifndef TEXTURE_HPP
#define TEXTURE_HPP

class Texture {
  public:
    Texture(const char* path);
    ~Texture();

    Texture(const Texture&) = delete;
    Texture(Texture&&) = delete;
    Texture& operator=(const Texture&) = delete;
    Texture& operator=(Texture&&) = delete;

    GLuint id() const { return _handle; }
    int width() const { return _width; }
    int height() const { return _height; }
    void bind(GLuint unit = 0) const;

  private:
    GLuint _handle{0};
    int _width{0};
    int _height{0};
};

#endif
