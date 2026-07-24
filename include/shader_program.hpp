#ifndef SHADER_PROGRAM_HPP
#define SHADER_PROGRAM_HPP

class ShaderProgram {
  public:
    ShaderProgram(const std::string& vertex_path, const std::string& fragment_path);
    ~ShaderProgram();

    ShaderProgram(const ShaderProgram&) = delete;
    ShaderProgram(ShaderProgram&&) = delete;
    ShaderProgram& operator=(const ShaderProgram&) = delete;
    ShaderProgram& operator=(ShaderProgram&&) = delete;

    void use() const;
    GLint get_location(const std::string& name) const;
    void set_uniform(GLint location, GLint value);
    void set_uniform(GLint location, const glm::vec2& value);
    void set_uniform(GLint location, const glm::vec3& value);
    void set_uniform(GLint location, const glm::mat4& value);

  private:
    GLuint _program{0};
};

#endif
