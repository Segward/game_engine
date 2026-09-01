#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <window.hpp>
#include <camera.hpp>

class Controller {
  public:
    static Controller& instance();

    Controller(const Controller&) = delete;
    Controller& operator=(const Controller&) = delete;
    Controller(Controller&&) = delete;
    Controller& operator=(Controller&&) = delete;

    void handle_events();

  private:
    Window& _window{Window::instance()};
    Camera& _camera{Camera::instance()};

    Controller() = default;
};

#endif
