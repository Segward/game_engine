#ifndef MESH_HPP
#define MESH_HPP

struct Vertex {
  glm::vec3 position;
  glm::vec3 normal;
  glm::vec2 uv;
};

struct Instance {
  glm::vec2 position;
  glm::vec2 size;
  glm::vec2 uv_offset;
  glm::vec2 uv_scale;
};

class Mesh {
  public:
    Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices);
    ~Mesh();
  
    Mesh(const Mesh&) = delete;
    Mesh(Mesh&&) = delete;
    Mesh& operator=(const Mesh&) = delete;
    Mesh& operator=(Mesh&&) = delete;

    void set_instances(const std::vector<Instance>& instances);
    void draw() const;

  private:
    GLuint _vao{0};
    GLuint _vbo{0};
    GLuint _ebo{0};
    GLuint _ibo{0};
    GLsizei _index_count{0};
    GLsizei _instances_count{0};
    GLsizeiptr _instances_capacity{0};
};

#endif
