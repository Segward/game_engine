#include <io.hpp>
#include <shader.hpp>

static std::string get_info_log(GLuint object, GLenum kind) {
  GLint length = 0;
  if (kind == GL_SHADER) {
    glGetShaderiv(object, GL_INFO_LOG_LENGTH, &length);
  } else {
    glGetProgramiv(object, GL_INFO_LOG_LENGTH, &length);
  }
  if (length <= 0) {
    return {};
  }

  std::string log(static_cast<size_t>(length - 1), '\0');
  if (kind == GL_SHADER) {
    glGetShaderInfoLog(object, length, nullptr, log.data());
  } else {
    glGetProgramInfoLog(object, length, nullptr, log.data());
  }
  return log;
}

static GLuint compile_stage(GLenum stage, const char* path) {
  std::string source = IO::read(path);
  const char* source_ptr = source.c_str();

  GLuint shader = glCreateShader(stage);
  glShaderSource(shader, 1, &source_ptr, nullptr);
  glCompileShader(shader);

  GLint status = GL_FALSE;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
  if (status != GL_TRUE) {
    std::string log = get_info_log(shader, GL_SHADER);
    glDeleteShader(shader);
    throw std::runtime_error(std::string("compile_stage failed to compile ") + path + ": " + log);
  }

  return shader;
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
  glAttachShader(_program, vertex);
  glAttachShader(_program, fragment);
  glLinkProgram(_program);

  glDeleteShader(vertex);
  glDeleteShader(fragment);

  GLint status = GL_FALSE;
  glGetProgramiv(_program, GL_LINK_STATUS, &status);
  if (status != GL_TRUE) {
    std::string log = get_info_log(_program, GL_PROGRAM);
    glDeleteProgram(_program);
    _program = 0;
    throw std::runtime_error("Shader failed to link program: " + log);
  }
}

Shader::~Shader() {
  if (!_program) {
    return;
  }

  glDeleteProgram(_program);
}

void Shader::use_program() {
  glUseProgram(_program);
}

void Shader::set_uniform(const char* name, float value) {
  glProgramUniform1f(_program, glGetUniformLocation(_program, name), value);
}

void Shader::set_uniform(const char* name, const glm::vec2& value) {
  glProgramUniform2fv(_program, glGetUniformLocation(_program, name), 1, glm::value_ptr(value));
}

void Shader::set_uniform(const char* name, const glm::mat4& value) {
  glProgramUniformMatrix4fv(_program, glGetUniformLocation(_program, name), 1, GL_FALSE, glm::value_ptr(value));
}
