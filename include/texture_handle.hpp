#ifndef TEXTURE_HANDLE_HPP
#define TEXTURE_HANDLE_HPP

class TextureHandle {
  public:
    TextureHandle(const std::string& texture_path);
    ~TextureHandle();

    TextureHandle(const TextureHandle&) = delete;
    TextureHandle& operator=(const TextureHandle&) = delete;
    TextureHandle(TextureHandle&&) noexcept;
    TextureHandle& operator=(TextureHandle&&) = delete;

    void bind(GLuint unit = 0) const;

    int get_width() const { return _width; }
    int get_height() const { return _height; }

  private:
    GLuint _handle{0};
    int _width{0};
    int _height{0};
};

namespace texture_handle {
  TextureHandle& sprite_sheet();
}

#endif
