#ifndef QUAD_HPP
#define QUAD_HPP

#include <shader_program.hpp>
#include <mesh.hpp>

class Quad {
  public:
    static Quad& instance();

    Quad(const Quad&) = delete;
    Quad& operator=(const Quad&) = delete;
    Quad(Quad&&) = delete;
    Quad& operator=(Quad&&) = delete;

    void draw(const glm::vec2& position, const glm::vec2& size); 

    void set_uv_offset(const glm::vec2& uv_offset) { _program.set_uniform(_uv_offset_location, uv_offset); }
    void set_uv_scale(const glm::vec2& uv_scale) { _program.set_uniform(_uv_scale_location, uv_scale); }
    void set_projection(const glm::mat4& projection) { _program.set_uniform(_projection_location, projection); }

  private:
    ShaderProgram _program;
    Mesh _mesh;

    GLint _position_location;
    GLint _size_location;
    GLint _texture_location;
    GLint _uv_offset_location;
    GLint _uv_scale_location;
    GLint _projection_location;

    Quad();
};

#endif
