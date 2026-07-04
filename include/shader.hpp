#ifndef SHADER_HPP
#define SHADER_HPP

class Shader {
  public:
    Shader(const std::string& vertex_path, const std::string& fragment_path);
    ~Shader();

    Shader(const Shader&) = delete;
    Shader(Shader&&) = delete;
    Shader& operator=(const Shader&) = delete;
    Shader& operator=(Shader&&) = delete;

  private:
    GLuint _program{0};
};

#endif
