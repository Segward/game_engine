#ifndef WORLD_HPP
#define WORLD_HPP

#include <store.hpp>
#include <texture.hpp>
#include <quad.hpp>
#include <physics.hpp>

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
    Store<Block>& _block_store{Store<Block>::instance()};

    Quad& _quad{Quad::instance()};
    Physics& _physics{Physics::instance()};

    std::vector<std::vector<Instance>> _batches;

    World() = default;
};

#endif
