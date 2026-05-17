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

    void set_uniform(const char* name, float value);
    void set_uniform(const char* name, const glm::vec2& value);
    void set_uniform(const char* name, const glm::mat4& value);

  private:
    GLuint _program{0};
};

#endif
