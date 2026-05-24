#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <texture.hpp>

Texture::Texture(const char* path) {
  stbi_set_flip_vertically_on_load(1);

  int channels = 0;
  stbi_uc* pixels = stbi_load(path, &_width, &_height, &channels, 4);
  if (!pixels) {
    std::string reason = stbi_failure_reason();
    throw std::runtime_error("Texture failed to load " + std::string(path) + ": " + reason);
  }

  glGenTextures(1, &_handle);
  glBindTexture(GL_TEXTURE_2D, _handle);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  stbi_image_free(pixels);
}

Texture::~Texture() {
  if (!_handle) {
    return;
  }

  glDeleteTextures(1, &_handle);
}

void Texture::bind(GLuint unit) const {
  glActiveTexture(GL_TEXTURE0 + unit);
  glBindTexture(GL_TEXTURE_2D, _handle);
}
