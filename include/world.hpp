#ifndef WORLD_HPP
#define WORLD_HPP

#include <store.hpp>
#include <object.hpp>
#include <texture.hpp>
#include <quad.hpp>
#include <window.hpp>

class World {
  public:
    static World& instance();

    World(const World&) = delete;
    World& operator=(const World&) = delete;
    World(World&&) = delete;
    World& operator=(World&&) = delete;

    void draw_background();
    void draw_objects();

  private:
    Store<Object>& object_store{Store<Object>::instance()};
    Store<Texture>& texture_store{Store<Texture>::instance()};
    Quad& quad{Quad::instance()};
    Window& window{Window::instance()};

    World() = default;
};

#endif
