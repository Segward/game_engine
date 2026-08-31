#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <window.hpp>
#include <world.hpp>
#include <background.hpp>
#include <camera.hpp>
#include <quad.hpp>
#include <time.hpp>

class Renderer {
  public:
    static Renderer& instance();

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;
    Renderer(Renderer&&) = delete;
    Renderer& operator=(Renderer&&) = delete;

    void render();

  private:
    Window& _window{Window::instance()};
    World& _world{World::instance()};
    Background& _background{Background::instance()};
    Camera& _camera{Camera::instance()};
    Quad& _quad{Quad::instance()};
    Time& _time{Time::instance()};

    Renderer() = default;
};

#endif
