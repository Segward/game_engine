#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <quad.hpp>
#include <window.hpp>

class Global {
  public:
    static Global& instance();

    Global(const Global&) = delete;
    Global& operator=(const Global&) = delete;
    Global(Global&&) = delete;
    Global& operator=(Global&&) = delete;

    Window& window() const { return Window::instance(); }
    Quad& quad() const { return Quad::instance(); }

  private:
    Global();
};

#endif
