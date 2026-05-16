#include "engine/graphics/quad.hpp"

#include "util/io.hpp"
#include "engine/graphics/shader.hpp"

bool Quad::_exists = false;

Quad::Quad() {
  if (_exists) {
    throw std::runtime_error("only one quad allowed");
  }

  _program = std::make_unique<Shader>(
    Io::read_file("assets/shaders/quad.vert"),
    Io::read_file("assets/shaders/quad.frag"));

  static const float vertices[] = {
    -0.5f, -0.5f,
     0.5f, -0.5f,
     0.5f,  0.5f,
    -0.5f,  0.5f,
  };

  static const unsigned int indices[] = {
    0, 1, 2,
    2, 3, 0,
  };

  glGenVertexArrays(1, &_vertex_array);
  glGenBuffers(1, &_vertex_buffer);
  glGenBuffers(1, &_index_buffer);

  glBindVertexArray(_vertex_array);

  glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _index_buffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);

  glBindVertexArray(0);

  _exists = true;
}

Quad::~Quad() {
  glDeleteBuffers(1, &_index_buffer);
  glDeleteBuffers(1, &_vertex_buffer);
  glDeleteVertexArrays(1, &_vertex_array);
  _exists = false;
}

void Quad::draw(glm::vec2 offset, glm::vec2 scale, glm::vec4 color,
                const glm::mat4& view_projection) const {
  _program->use();
  _program->set_vec2("offset", offset);
  _program->set_vec2("scale", scale);
  _program->set_vec4("color", color);
  _program->set_mat4("view_projection", view_projection);
  glBindVertexArray(_vertex_array);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
  glBindVertexArray(0);
}
