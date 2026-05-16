#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "engine/objects/object.hpp"

class Window;

class Physics {
  public:
    void step(std::vector<std::unique_ptr<Object>>& objects,
              float delta, const Window& window) const;
};

#endif
