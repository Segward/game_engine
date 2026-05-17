#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <window.hpp>

class Global {
  public:
    static Global& instance();

    ~Global();

    Global(const Global&) = delete;
    Global& operator=(const Global&) = delete;
    Global(Global&&) = delete;
    Global& operator=(Global&&) = delete;

    Window& window() const { return *_window; }

  private:
    std::unique_ptr<Window> _window;

    Global();
};

#endif
