#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <assets_manager.hpp>
#include <quad.hpp>
#include <window.hpp>
#include <camera.hpp>

class Background {
  public:
    static Background& instance();

    Background(const Background&) = delete;
    Background& operator=(const Background&) = delete;
    Background(Background&&) = delete;
    Background& operator=(Background&&) = delete;

    void draw();

  private:
    AssetsManager& _assets_manager{AssetsManager::instance()};
    Quad& _quad{Quad::instance()};
    Window& _window{Window::instance()};
    Camera& _camera{Camera::instance()};

    Background() = default;
};

#endif
