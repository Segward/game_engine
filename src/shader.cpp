#include <io.hpp>
#include <shader.hpp>

namespace {
std::string get_info_log(GLuint object, GLenum kind) {
  auto getiv = (kind == GL_SHADER) ? glGetShaderiv : glGetProgramiv;
  auto getlog = (kind == GL_SHADER) ? glGetShaderInfoLog : glGetProgramInfoLog;

  GLint length = 0;
  getiv(object, GL_INFO_LOG_LENGTH, &length);
  if (length <= 0) {
    return {};
  }

  std::string log(static_cast<size_t>(length - 1), '\0');
  getlog(object, length, nullptr, log.data());
  return log;
}

std::optional<std::string> check_status(GLuint object, GLenum status_pname, GLenum kind) {
  auto getiv = (kind == GL_SHADER) ? glGetShaderiv : glGetProgramiv;

  GLint status = GL_FALSE;
  getiv(object, status_pname, &status);
  if (status == GL_TRUE) {
    return std::nullopt;
  }

  return get_info_log(object, kind);
}

GLuint compile_stage(GLenum stage, const char* path) {
  std::string source = io::read(path);
  const char* source_ptr = source.c_str();
  const GLint source_len = static_cast<GLint>(source.size());

  GLuint shader = glCreateShader(stage);
  if (!shader) {
    std::string message = std::string("compile_stage failed to create shader for ") + path;
    throw std::runtime_error(message);
  }

  glShaderSource(shader, 1, &source_ptr, &source_len);
  glCompileShader(shader);

  if (auto log = check_status(shader, GL_COMPILE_STATUS, GL_SHADER)) {
    glDeleteShader(shader);
    std::string message = std::string("compile_stage failed to compile ") + path + ": " + *log;
    throw std::runtime_error(message);
  }

  return shader;
}
}

Shader::Shader(const char* vertex_path, const char* fragment_path) {
  GLuint vertex = compile_stage(GL_VERTEX_SHADER, vertex_path);

  GLuint fragment;
  try {
    fragment = compile_stage(GL_FRAGMENT_SHADER, fragment_path);
  } catch (...) {
    glDeleteShader(vertex);
    throw;
  }

  _program = glCreateProgram();
  if (!_program) {
    glDeleteShader(vertex);
    glDeleteShader(fragment);
    throw std::runtime_error("Shader failed to create program");
  }

  glAttachShader(_program, vertex);
  glAttachShader(_program, fragment);
  glLinkProgram(_program);

  glDeleteShader(vertex);
  glDeleteShader(fragment);

  if (auto log = check_status(_program, GL_LINK_STATUS, GL_PROGRAM)) {
    glDeleteProgram(_program);
    _program = 0;
    std::string message = "Shader failed to link program: " + *log;
    throw std::runtime_error(message);
  }
}

Shader::~Shader() {
  if (!_program) {
    return;
  }

  glDeleteProgram(_program);
}

GLint Shader::get_uniform_location(const char* name) const {
  return glGetUniformLocation(_program, name);
}

void Shader::set_uniform(GLint location, float value) {
  glProgramUniform1f(_program, location, value);
}

void Shader::set_uniform(GLint location, const glm::vec2& value) {
  glProgramUniform2fv(_program, location, 1, glm::value_ptr(value));
}

void Shader::set_uniform(GLint location, const glm::vec3& value) {
  glProgramUniform3fv(_program, location, 1, glm::value_ptr(value));
}

void Shader::set_uniform(GLint location, const glm::mat4& value) {
  glProgramUniformMatrix4fv(_program, location, 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::use_program() {
  glUseProgram(_program);
}
