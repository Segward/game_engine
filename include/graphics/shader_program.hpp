#ifndef SHADER_PROGRAM_HPP
#define SHADER_PROGRAM_HPP

class ShaderProgram {
  public:
    ShaderProgram(const char* vertex_path, const char* fragment_path);
    ~ShaderProgram();

    ShaderProgram(const ShaderProgram&) = delete;
    ShaderProgram(ShaderProgram&&) = delete;
    ShaderProgram& operator=(const ShaderProgram&) = delete;
    ShaderProgram& operator=(ShaderProgram&&) = delete;

    GLint get_uniform_location(const char* name) const;
    void set_uniform(GLint location, int value) const;
    void set_uniform(GLint location, float value) const;
    void set_uniform(GLint location, const glm::vec2& value) const;
    void set_uniform(GLint location, const glm::vec3& value) const;
    void set_uniform(GLint location, const glm::mat4& value) const;
    void use_program() const;

  private:
    GLuint _program{0};
};

#endif
