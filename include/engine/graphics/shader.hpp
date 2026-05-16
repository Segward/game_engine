#ifndef SHADER_HPP
#define SHADER_HPP

class Shader {
  public:
    Shader(const std::string& vertex_source, const std::string& fragment_source);
    ~Shader();

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;
    Shader(Shader&&) = delete;
    Shader& operator=(Shader&&) = delete;

    void use() const;
    int uniform_location(const char* name) const;
    void set_vec2(const char* name, const glm::vec2& value) const;
    void set_vec4(const char* name, const glm::vec4& value) const;
    void set_mat4(const char* name, const glm::mat4& value) const;

  private:
    unsigned int _program{0};
    mutable std::unordered_map<std::string, int> _uniform_cache;
};

#endif
