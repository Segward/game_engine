#include <shader_handle.hpp>
#include <shader_program.hpp>

namespace {
  std::string get_info_log(GLuint program) {
    GLint length = 0;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
    if (length <= 0) {
      return {};
    }

    std::string log(static_cast<size_t>(length - 1), '\0');
    glGetProgramInfoLog(program, length, nullptr, log.data());
    return log;
  }
}

ShaderProgram::ShaderProgram(const char* vertex_path, const char* fragment_path) {
  ShaderHandle vertex(GL_VERTEX_SHADER, vertex_path);
  ShaderHandle fragment(GL_FRAGMENT_SHADER, fragment_path);

  _program = glCreateProgram();
  if (!_program) {
    throw std::runtime_error("ShaderProgram failed to create program");
  }

  glAttachShader(_program, vertex.id());
  glAttachShader(_program, fragment.id());
  glLinkProgram(_program);

  GLint status = GL_FALSE;
  glGetProgramiv(_program, GL_LINK_STATUS, &status);
  if (status != GL_TRUE) {
    std::string log = get_info_log(_program);
    glDeleteProgram(_program);
    _program = 0;
    throw std::runtime_error("ShaderProgram failed to link: " + log);
  }
}

ShaderProgram::~ShaderProgram() {
  if (!_program) {
    return;
  }

  glDeleteProgram(_program);
}

GLint ShaderProgram::get_uniform_location(const char* name) const {
  return glGetUniformLocation(_program, name);
}

void ShaderProgram::set_uniform(GLint location, float value) const {
  glProgramUniform1f(_program, location, value);
}

void ShaderProgram::set_uniform(GLint location, const glm::vec2& value) const {
  glProgramUniform2fv(_program, location, 1, glm::value_ptr(value));
}

void ShaderProgram::set_uniform(GLint location, const glm::vec3& value) const {
  glProgramUniform3fv(_program, location, 1, glm::value_ptr(value));
}

void ShaderProgram::set_uniform(GLint location, const glm::mat4& value) const {
  glProgramUniformMatrix4fv(_program, location, 1, GL_FALSE, glm::value_ptr(value));
}

void ShaderProgram::use_program() const {
  glUseProgram(_program);
}
