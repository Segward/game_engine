#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <shader_program.hpp>
#include <texture.hpp>

struct TriangleInstance {
  glm::vec3 positions[3];
  glm::vec2 uvs[3];
  glm::vec3 color;
};

class Triangle {
  public:
    static Triangle& instance();

    Triangle(const Triangle&) = delete;
    Triangle& operator=(const Triangle&) = delete;
    Triangle(Triangle&&) = delete;
    Triangle& operator=(Triangle&&) = delete;

    void draw(const std::vector<TriangleInstance>& triangles, const Texture& texture);
    void set_projection(const glm::mat4& projection) { _program.use(); _program.set_uniform(_projection_location, projection); }
    void set_view(const glm::mat4& view) { _program.use(); _program.set_uniform(_view_location, view); }

  private:
    ShaderProgram _program;
    GLuint _vao{0};
    GLuint _vbo{0};

    GLint _projection_location;
    GLint _view_location;

    Triangle();
    ~Triangle();
};

#endif
