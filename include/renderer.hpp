#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <window.hpp>
#include <camera.hpp>
#include <face.hpp>
#include <terrain.hpp>

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
    Camera& _camera{Camera::instance()};
    Face& _face{Face::instance()};
    Terrain& _terrain{Terrain::instance()};

    Renderer() = default;
};

#endif
