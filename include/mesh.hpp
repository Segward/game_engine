#ifndef MESH_HPP
#define MESH_HPP

struct Vertex {
  glm::vec3 position;
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

    void add_instance_attribute(GLuint index, GLint size, GLsizei stride, std::size_t offset);

    template<typename T>
    void draw(const std::vector<T>& instances) const { draw(instances.data(), static_cast<GLsizeiptr>(instances.size() * sizeof(T)), static_cast<GLsizei>(instances.size())); }

  private:
    GLuint _vao{0};
    GLuint _vbo{0};
    GLuint _ebo{0};
    GLuint _ibo{0};
    GLsizei _index_count{0};

    void draw(const void* instances, GLsizeiptr size, GLsizei count) const;
};

#endif
