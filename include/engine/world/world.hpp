#ifndef WORLD_HPP
#define WORLD_HPP

#include "engine/objects/object.hpp"

class Quad;

class World {
  public:
    World() = default;

    World(const World&) = delete;
    World& operator=(const World&) = delete;
    World(World&&) = delete;
    World& operator=(World&&) = delete;

    Object& add(std::unique_ptr<Object> object);

    std::vector<std::unique_ptr<Object>>& objects() { return _objects; }
    const std::vector<std::unique_ptr<Object>>& objects() const { return _objects; }

    void draw(const glm::mat4& view_projection, const Quad& quad) const;

  private:
    std::vector<std::unique_ptr<Object>> _objects;
};

#endif
