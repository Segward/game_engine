#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <window.hpp>

class Global {
  public:
    Window window;

    static Global& instance();

    Global(const Global&) = delete;
    Global& operator=(const Global&) = delete;
    Global(Global&&) = delete;
    Global& operator=(Global&&) = delete;

  private:
    Global();
};

#endif
