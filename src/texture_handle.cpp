#include "common.hpp"
#include <texture_handle.hpp>
#include <io.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

TextureHandle::TextureHandle(const std::string& texture_path) {
  std::string source = io::read(texture_path);

  int channels = 0;
  unsigned char* pixels = stbi_load_from_memory(
    reinterpret_cast<const unsigned char*>(source.data()),
    static_cast<int>(source.size()),
    &_width, &_height, &channels, 4);

  if (!pixels) {
    std::string failure_reason = std::string(stbi_failure_reason());
    throw std::runtime_error("texture error: " + failure_reason);
  }

  glGenTextures(1, &_handle);
  glBindTexture(GL_TEXTURE_2D, _handle);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
  glGenerateMipmap(GL_TEXTURE_2D);

  stbi_image_free(pixels);
}

TextureHandle::~TextureHandle() {
  if (_handle) glDeleteTextures(1, &_handle);
}

TextureHandle::TextureHandle(TextureHandle&& other) noexcept : _handle(other._handle), _width(other._width), _height(other._height) {
  other._handle = 0;
}

void TextureHandle::bind(GLuint unit) const {
  glActiveTexture(GL_TEXTURE0 + unit);
  glBindTexture(GL_TEXTURE_2D, _handle);
}

TextureHandle& texture_handle::sprite_sheet() {
  static TextureHandle texture_handle("assets/sprite_sheet.png");
  return texture_handle;
}
