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

    void draw(const std::vector<Instance>& instances);

    void use_shader_program() { _program.use(); }
    void set_projection(const glm::mat4& projection) { _program.set_uniform(_projection_location, projection); }
    void set_view(const glm::mat4& view) { _program.set_uniform(_view_location, view); }

  private:
    ShaderProgram _program;
    Mesh _mesh;

    GLint _projection_location;
    GLint _view_location;

    Quad();
};

#endif
