#include <face.hpp>

namespace {
  const std::vector<Vertex> vertices = {
    {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {1.0f, 1.0f}},
    {{0.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
  };

  const std::vector<GLuint> indices = {0, 1, 2, 2, 3, 0};
}

Face& Face::instance() {
  static Face face;
  return face;
}

Face::Face() : _program("assets/face_vert.glsl", "assets/face_frag.glsl"), _mesh(vertices, indices) {
  for (GLuint corner = 0; corner < 4; corner++) _mesh.add_instance_attribute(2 + corner, 3, sizeof(FaceInstance), offsetof(FaceInstance, positions) + corner * sizeof(glm::vec3));
  _mesh.add_instance_attribute(6, 3, sizeof(FaceInstance), offsetof(FaceInstance, color));

  _projection_location = _program.get_location("u_projection");
  _view_location = _program.get_location("u_view");

  _program.use();
  _program.set_uniform(_program.get_location("u_texture"), 0);
}

void Face::draw(const std::vector<FaceInstance>& faces, const Texture& texture) {
  _program.use();
  texture.bind();
  _mesh.draw(faces);
}
