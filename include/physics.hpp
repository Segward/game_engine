#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include <window.hpp>
#include <camera.hpp>
#include <block.hpp>

class Physics {
  public:
    static Physics& instance();

    Physics(const Physics&) = delete;
    Physics& operator=(const Physics&) = delete;
    Physics(Physics&&) = delete;
    Physics& operator=(Physics&&) = delete;

    void step();

    b2WorldId get_world_id() const { return _world_id; }
    const std::vector<Block*>& get_render_blocks() const { return _render_blocks; }

  private:
    Window& _window{Window::instance()};
    Camera& _camera{Camera::instance()};

    b2WorldId _world_id{b2_nullWorldId};
    std::vector<Block*> _render_blocks;

    Physics();
    ~Physics();
};

#endif
