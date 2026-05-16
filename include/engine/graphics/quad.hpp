#ifndef QUAD_HPP
#define QUAD_HPP

class Shader;

class Quad {
  public:
    Quad();
    ~Quad();

    Quad(const Quad&) = delete;
    Quad& operator=(const Quad&) = delete;
    Quad(Quad&&) = delete;
    Quad& operator=(Quad&&) = delete;

    void draw(glm::vec2 offset, glm::vec2 scale, glm::vec4 color,
              const glm::mat4& view_projection) const;

  private:
    std::unique_ptr<Shader> _program;
    unsigned int _vertex_array{0};
    unsigned int _vertex_buffer{0};
    unsigned int _index_buffer{0};

    static bool _exists;
};

#endif
