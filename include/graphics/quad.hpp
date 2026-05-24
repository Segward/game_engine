#ifndef QUAD_HPP
#define QUAD_HPP

#include <mesh.hpp>
#include <shader_program.hpp>

class Texture;

class Quad {
  public:
    static Quad& instance();

    Quad(const Quad&) = delete;
    Quad(Quad&&) = delete;
    Quad& operator=(const Quad&) = delete;
    Quad& operator=(Quad&&) = delete;

    void render(const glm::vec2& position, const glm::vec2& size, const glm::vec2& rotation_basis, const glm::vec2& uv_scale, const Texture& texture) const;

  private:
    Quad();

    Mesh _mesh;
    ShaderProgram _shader;
    GLint _u_position{-1};
    GLint _u_rotation{-1};
    GLint _u_size{-1};
    GLint _u_window_size{-1};
    GLint _u_uv_scale{-1};
};

#endif
