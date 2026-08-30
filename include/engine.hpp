#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <window.hpp>
#include <renderer.hpp>

class Engine {
  public:
    static Engine& instance();

    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator=(Engine&&) = delete;

    void init();
    void start();

  private:
    Window& _window{Window::instance()};
    Renderer& _renderer{Renderer::instance()};

    Engine() = default;
};

#endif
