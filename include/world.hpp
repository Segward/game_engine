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

    void draw();
    void generate();

  private:
    Store<Texture>& _texture_store{Store<Texture>::instance()};
    Quad& _quad{Quad::instance()};
    Window& _window{Window::instance()};
    Camera& _camera{Camera::instance()};

    std::vector<std::vector<Instance>> _batches;
    std::unordered_map<glm::ivec2, Chunk> _chunks;

    World() = default;
};

#endif
