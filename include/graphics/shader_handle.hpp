#ifndef SHADER_HANDLE_HPP
#define SHADER_HANDLE_HPP

class ShaderHandle {
  public:
    ShaderHandle(GLenum stage, const char* path);
    ~ShaderHandle();

    ShaderHandle(const ShaderHandle&) = delete;
    ShaderHandle(ShaderHandle&&) = delete;
    ShaderHandle& operator=(const ShaderHandle&) = delete;
    ShaderHandle& operator=(ShaderHandle&&) = delete;

    GLuint id() const { return _handle; }

  private:
    GLuint _handle{0};
};

#endif
