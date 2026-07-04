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

  private:
    GLuint _program{0};
};

#endif
