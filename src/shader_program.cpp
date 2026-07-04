#include <shader_program.hpp>
#include <shader_handle.hpp>

namespace {
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
}

ShaderProgram::ShaderProgram(const std::string& vertex_path, const std::string& fragment_path) {
  ShaderHandle vertex(vertex_path, GL_VERTEX_SHADER);
  ShaderHandle fragment(fragment_path, GL_FRAGMENT_SHADER);

  _program = glCreateProgram();
  glAttachShader(_program, vertex.id());
  glAttachShader(_program, fragment.id());
  glLinkProgram(_program);

  GLint ok;
  glGetProgramiv(_program, GL_LINK_STATUS, &ok);
  if (!ok) {
    std::string error = "shader program error: " + get_program_info_log(_program);
    glDeleteProgram(_program);
    throw std::runtime_error(error);
  }
}

ShaderProgram::~ShaderProgram() {
  if (_program) glDeleteProgram(_program);
}

void ShaderProgram::use() const {
  glUseProgram(_program);
}

GLint ShaderProgram::get_location(const std::string& name) const {
  return glGetUniformLocation(_program, name.c_str());
}

void ShaderProgram::set_uniform(GLint location, const glm::vec2& value) {
  glUniform2fv(location, 1, glm::value_ptr(value));
}

void ShaderProgram::set_uniform(GLint location, const glm::vec3& value) {
  glUniform3fv(location, 1, glm::value_ptr(value));
}

void ShaderProgram::set_uniform(GLint location, const glm::mat4& value) {
  glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}
