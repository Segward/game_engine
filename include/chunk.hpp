#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <block.hpp>

class Chunk {
  public:
    Chunk(std::vector<Block>&& blocks);

    Chunk(const Chunk&) = delete;
    Chunk& operator=(const Chunk&) = delete;
    Chunk(Chunk&&) = delete;
    Chunk& operator=(Chunk&&) = delete;

    int emplace_back(const int sprite_id, const glm::vec2& position, const glm::vec2& size, const b2BodyType type);

    Block& get(const int id) { return _blocks[id]; }
    std::vector<Block>& get_all() { return _blocks; }

  private:
    std::vector<Block> _blocks;
};

#endif
