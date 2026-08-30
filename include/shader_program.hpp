#ifndef SHADER_PROGRAM_HPP
#define SHADER_PROGRAM_HPP

class ShaderProgram {
  public:
    ShaderProgram(const std::string& vertex_path, const std::string& fragment_path);
    ~ShaderProgram() { if (_program) glDeleteProgram(_program); }

    ShaderProgram(const ShaderProgram&) = delete;
    ShaderProgram(ShaderProgram&&) = delete;
    ShaderProgram& operator=(const ShaderProgram&) = delete;
    ShaderProgram& operator=(ShaderProgram&&) = delete;

    void use() const { glUseProgram(_program); }
    GLint get_location(const std::string& name) const { return glGetUniformLocation(_program, name.c_str()); }
    void set_uniform(GLint location, GLint value) { glUniform1i(location, value); }
    void set_uniform(GLint location, const glm::vec2& value) { glUniform2fv(location, 1, glm::value_ptr(value)); }
    void set_uniform(GLint location, const glm::mat4& value) { glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value)); }

  private:
    GLuint _program{0};
};

#endif
