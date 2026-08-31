#ifndef WORLD_HPP
#define WORLD_HPP

#include <store.hpp>
#include <object.hpp>
#include <quad.hpp>
#include <window.hpp>

class World {
  public:
    static World& instance();

    World(const World&) = delete;
    World& operator=(const World&) = delete;
    World(World&&) = delete;
    World& operator=(World&&) = delete;

    void draw();

  private:
    Store<Object>& _object_store{Store<Object>::instance()};
    Quad& _quad{Quad::instance()};
    Window& _window{Window::instance()};

    World() = default;
};

#endif
