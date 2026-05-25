#ifndef MESH_HPP
#define MESH_HPP

struct Vertex {
  glm::vec3 position;
  glm::vec3 normal;
  glm::vec2 uv;
};

class Mesh {
  public:
    Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices);
    ~Mesh();
  
    Mesh(const Mesh&) = delete;
    Mesh(Mesh&&) = delete;
    Mesh& operator=(const Mesh&) = delete;
    Mesh& operator=(Mesh&&) = delete;

    void draw() const;

  private:
    GLuint _vao{0};
    GLuint _vbo{0};
    GLuint _ebo{0};
    GLsizei _index_count{0};
};

#endif
