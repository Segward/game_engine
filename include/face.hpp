#ifndef FACE_HPP
#define FACE_HPP

#include <shader_program.hpp>
#include <mesh.hpp>
#include <texture.hpp>

struct FaceInstance {
  glm::vec3 positions[4];
  glm::vec3 color;
};

class Face {
  public:
    static Face& instance();

    Face(const Face&) = delete;
    Face& operator=(const Face&) = delete;
    Face(Face&&) = delete;
    Face& operator=(Face&&) = delete;

    void draw(const std::vector<FaceInstance>& faces, const Texture& texture);
    void set_projection(const glm::mat4& projection) { _program.use(); _program.set_uniform(_projection_location, projection); }
    void set_view(const glm::mat4& view) { _program.use(); _program.set_uniform(_view_location, view); }

  private:
    ShaderProgram _program;
    Mesh _mesh;

    GLint _projection_location;
    GLint _view_location;

    Face();
};

#endif
