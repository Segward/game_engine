#include <global.hpp>

Global& Global::instance() {
  static Global global;
  return global;
}

Global::Global() : window(1280, 720, "game engine") {}
