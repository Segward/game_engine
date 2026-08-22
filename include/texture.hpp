#ifndef TEXTURE_HPP
#define TEXTURE_HPP

class Texture {
  public:
    int _width{0};
    int _height{0};

    Texture(const std::string& texture_path);
    ~Texture();

    Texture(const Texture&) = delete;
    Texture(Texture&&) = delete;
    Texture& operator=(const Texture&) = delete;
    Texture& operator=(Texture&&) = delete;

    void bind(GLuint unit = 0) const;

  private:
    GLuint _handle{0};
};

#endif
