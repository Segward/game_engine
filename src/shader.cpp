#include <shader.hpp>
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

  std::string get_program_info_log(GLuint program) {
    GLint length = 0;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
    if (length <= 0) {
      return {};
    }

    std::string log(static_cast<size_t>(length - 1), '\0');
    glGetProgramInfoLog(program, length, nullptr, log.data());
    return log;
  }

  GLuint get_shader_handle(const std::string& path, GLenum type) {
    std::string source = io::read(path);
    const char* source_c = source.c_str();

    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source_c, nullptr);
    glCompileShader(shader);

    GLint ok;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &ok);
    if (!ok) {
      std::string error = "shader error: " + get_shader_info_log(shader);
      glDeleteShader(shader);
      throw std::runtime_error(error);
    }

    return shader;
  }

  GLuint link_program(GLuint vertex_shader, GLuint fragment_shader) {
    GLuint program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    GLint link_ok;
    glGetProgramiv(program, GL_LINK_STATUS, &link_ok);

    glDetachShader(program, vertex_shader);
    glDetachShader(program, fragment_shader);
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    if (!link_ok) {
      std::string error = "shader program link error: " + get_program_info_log(program);
      glDeleteProgram(program);
      throw std::runtime_error(error);
    }

    return program;
  }
}

Shader::Shader(const std::string& vertex_path, const std::string& fragment_path) {
  GLuint vertex_shader = get_shader_handle(vertex_path, GL_VERTEX_SHADER);

  GLuint fragment_shader;
  try {
    fragment_shader = get_shader_handle(fragment_path, GL_FRAGMENT_SHADER);
  } catch (...) {
    glDeleteShader(vertex_shader);
    throw;
  }

  _program = link_program(vertex_shader, fragment_shader);
}

Shader::~Shader() {
  if (_program) glDeleteProgram(_program);
}
