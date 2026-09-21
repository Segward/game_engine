#ifndef WORLD_HPP
#define WORLD_HPP

#include <store.hpp>
#include <texture.hpp>
#include <quad.hpp>
#include <unordered_map>
#include <window.hpp>
#include <camera.hpp>
#include <chunk.hpp>

class World {
  public:
    static World& instance();

    World(const World&) = delete;
    World& operator=(const World&) = delete;
    World(World&&) = delete;
    World& operator=(World&&) = delete;

    void update();
    void draw();
    void generate();

  private:
    Store<Texture>& _texture_store{Store<Texture>::instance()};
    Quad& _quad{Quad::instance()};
    Window& _window{Window::instance()};
    Camera& _camera{Camera::instance()};

    std::vector<std::vector<Instance>> _batches;
    std::unordered_map<glm::ivec2, Chunk> _chunks;
    std::unordered_set<glm::ivec2> _active_chunks;

    glm::ivec2 _min_chunk_position;
    glm::ivec2 _max_chunk_position;

    World() = default;

    bool is_chunk_visible(const glm::ivec2& chunk_position) const;
};

#endif
