#ifndef QUAD_HPP
#define QUAD_HPP

#include <shader_program.hpp>
#include <mesh.hpp>
#include <texture.hpp>

class Quad {
  public:
    static Quad& instance();

    Quad(const Quad&) = delete;
    Quad& operator=(const Quad&) = delete;
    Quad(Quad&&) = delete;
    Quad& operator=(Quad&&) = delete;

    void draw(const glm::vec2& position, const glm::vec2& size, 
        const Texture& texture, const glm::vec2& uv_offset, const glm::vec2& uv_scale);

  private:
    ShaderProgram _program;
    Mesh _mesh;

    Quad();
};

#endif
