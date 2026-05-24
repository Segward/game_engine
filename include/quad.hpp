#ifndef QUAD_HPP
#define QUAD_HPP

#include <mesh.hpp>
#include <shader.hpp>

class Quad {
public:
  static Quad& instance();

  Quad(const Quad&) = delete;
  Quad& operator=(const Quad&) = delete;
  Quad(Quad&&) = delete;
  Quad& operator=(Quad&&) = delete;

  void render(const glm::vec2& position, const glm::vec2& size, const glm::vec2& rotation, const glm::vec3& color);

private:
  Quad();

  Mesh _mesh;
  Shader _shader;
  GLint _u_position{-1};
  GLint _u_size{-1};
  GLint _u_rotation{-1};
  GLint _u_window_size{-1};
  GLint _u_color{-1};
};

#endif
