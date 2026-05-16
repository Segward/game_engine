#include "engine/graphics/shader.hpp"

static GLuint compile_stage(GLenum stage_type, const std::string& source) {
  GLuint stage = glCreateShader(stage_type);
  const char* source_cstr = source.c_str();
  glShaderSource(stage, 1, &source_cstr, nullptr);
  glCompileShader(stage);

  GLint success = GL_FALSE;
  glGetShaderiv(stage, GL_COMPILE_STATUS, &success);
  if (!success) {
    GLint length = 0;
    glGetShaderiv(stage, GL_INFO_LOG_LENGTH, &length);
    std::string log(length, '\0');
    glGetShaderInfoLog(stage, length, nullptr, log.data());
    glDeleteShader(stage);
    throw std::runtime_error("shader compile failed: " + log);
  }

  return stage;
}

Shader::Shader(const std::string& vertex_source, const std::string& fragment_source) {
  GLuint vertex_stage = compile_stage(GL_VERTEX_SHADER, vertex_source);
  GLuint fragment_stage = compile_stage(GL_FRAGMENT_SHADER, fragment_source);

  _program = glCreateProgram();
  glAttachShader(_program, vertex_stage);
  glAttachShader(_program, fragment_stage);
  glLinkProgram(_program);

  GLint success = GL_FALSE;
  glGetProgramiv(_program, GL_LINK_STATUS, &success);
  if (!success) {
    GLint length = 0;
    glGetProgramiv(_program, GL_INFO_LOG_LENGTH, &length);
    std::string log(length, '\0');
    glGetProgramInfoLog(_program, length, nullptr, log.data());
    glDeleteProgram(_program);
    glDeleteShader(vertex_stage);
    glDeleteShader(fragment_stage);
    _program = 0;
    throw std::runtime_error("program link failed: " + log);
  }

  glDetachShader(_program, vertex_stage);
  glDetachShader(_program, fragment_stage);
  glDeleteShader(vertex_stage);
  glDeleteShader(fragment_stage);
}

Shader::~Shader() {
  if (_program) {
    glDeleteProgram(_program);
  }
}

void Shader::use() const {
  glUseProgram(_program);
}

int Shader::uniform_location(const char* name) const {
  auto cached = _uniform_cache.find(name);
  if (cached != _uniform_cache.end()) {
    return cached->second;
  }

  int location = glGetUniformLocation(_program, name);
  _uniform_cache.emplace(name, location);

  return location;
}

void Shader::set_vec2(const char* name, const glm::vec2& value) const {
  glUniform2fv(uniform_location(name), 1, glm::value_ptr(value));
}

void Shader::set_vec4(const char* name, const glm::vec4& value) const {
  glUniform4fv(uniform_location(name), 1, glm::value_ptr(value));
}

void Shader::set_mat4(const char* name, const glm::mat4& value) const {
  glUniformMatrix4fv(uniform_location(name), 1, GL_FALSE, glm::value_ptr(value));
}
