#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "engine/camera.hpp"
#include "engine/physics/physics.hpp"
#include "engine/graphics/quad.hpp"
#include "engine/graphics/window.hpp"
#include "engine/world/world.hpp"

class Engine {
  public:
    Engine();

    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator=(Engine&&) = delete;

    void run();

    Window& window() { return _window; }
    Camera& camera() { return _camera; }
    World&  world()  { return _world;  }

  private:
    // Declaration order matters: _window must be constructed first (provides
    // GL context for _quad) and destroyed last.
    Window  _window;
    Quad    _quad;
    Camera  _camera;
    Physics _physics;
    World   _world;
};

#endif
