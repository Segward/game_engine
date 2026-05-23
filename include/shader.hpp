#ifndef SHADER_HPP
#define SHADER_HPP

class Shader {
  public:
    Shader(const char* vertex_path, const char* fragment_path);
    ~Shader();

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;
    Shader(Shader&&) = delete;
    Shader& operator=(Shader&&) = delete;

    void use_program();

    GLint get_uniform_location(const char* name) const;

    void set_uniform(GLint location, float value);
    void set_uniform(GLint location, const glm::vec2& value);
    void set_uniform(GLint location, const glm::mat4& value);

  private:
    GLuint _program{0};
};

#endif
