#ifndef QUAD_HPP
#define QUAD_HPP

#include <shader_program.hpp>
#include <mesh.hpp>
#include <texture.hpp>

struct QuadInstance {
  glm::vec2 position;
  glm::vec2 size;
  glm::vec3 color;
};

class Quad {
  public:
    static Quad& instance();

    Quad(const Quad&) = delete;
    Quad& operator=(const Quad&) = delete;
    Quad(Quad&&) = delete;
    Quad& operator=(Quad&&) = delete;

    void draw(const std::vector<QuadInstance>& instances, const Texture& texture);
    void set_projection(const glm::mat4& projection) { _program.use(); _program.set_uniform(_projection_location, projection); }

  private:
    ShaderProgram _program;
    Mesh _mesh;

    GLint _projection_location;

    Quad();
};

#endif
