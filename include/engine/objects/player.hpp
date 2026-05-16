#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "engine/objects/object.hpp"

class Window;

class Player : public Object {
  public:
    void update(float delta, const Window& window) override;

    float speed{1.0f};
};

#endif
