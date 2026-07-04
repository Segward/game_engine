#include <shader_handle.hpp>
#include <io.hpp>

namespace {
  std::string get_shader_info_log(GLuint shader) {
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

ShaderHandle::ShaderHandle(const std::string& path, GLenum type) {
  std::string source = io::read(path);
  const char* source_c = source.c_str();

  GLuint shader = glCreateShader(type);
  glShaderSource(shader, 1, &source_c, nullptr);
  glCompileShader(shader);

  GLint ok;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &ok);
  if (!ok) {
    std::string error = "shader handle error: " + get_shader_info_log(shader);
    glDeleteShader(shader);
    throw std::runtime_error(error);
  }
}

ShaderHandle::~ShaderHandle() {
  if (_handle) glDeleteShader(_handle);
}
