#include <io.hpp>
#include <shader_handle.hpp>

namespace {
  std::string get_info_log(GLuint shader) {
    GLint length = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
    if (length <= 0) {
      return {};
    }

    std::string log(static_cast<size_t>(length - 1), '\0');
    glGetShaderInfoLog(shader, length, nullptr, log.data());
    return log;
  }
}

ShaderHandle::ShaderHandle(GLenum stage, const char* path) {
  std::string source = io::read(path);
  const char* source_ptr = source.c_str();
  const GLint source_len = static_cast<GLint>(source.size());

  _handle = glCreateShader(stage);
  if (!_handle) {
    std::string message = std::string("ShaderHandle failed to create shader for ") + path;
    throw std::runtime_error(message);
  }

  glShaderSource(_handle, 1, &source_ptr, &source_len);
  glCompileShader(_handle);

  GLint status = GL_FALSE;
  glGetShaderiv(_handle, GL_COMPILE_STATUS, &status);
  if (status != GL_TRUE) {
    std::string log = get_info_log(_handle);
    glDeleteShader(_handle);
    _handle = 0;
    std::string message = std::string("ShaderHandle failed to compile ") + path + ": " + log;
    throw std::runtime_error(message);
  }
}

ShaderHandle::~ShaderHandle() {
  if (!_handle) {
    return;
  }

  glDeleteShader(_handle);
}
