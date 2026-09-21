#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <object.hpp>

class Chunk {
  public:
    Chunk(std::vector<Object>&& objects);

    Chunk(const Chunk&) = delete;
    Chunk& operator=(const Chunk&) = delete;
    Chunk(Chunk&&) = delete;
    Chunk& operator=(Chunk&&) = delete;

    int emplace_back(const int sprite_id, const glm::vec2& position, const glm::vec2& size);

    const Object& get(const int id) const { return _objects[id]; }
    const std::vector<Object>& get_all() const { return _objects; }

  private:
    std::vector<Object> _objects;
};

#endif
