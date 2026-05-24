#ifndef WORLD_HPP
#define WORLD_HPP

class World {
public:
  static constexpr float PIXELS_PER_METER = 50.0f;
  static constexpr b2Vec2 GRAVITY = {0.0f, -0.1f};

  static World& instance();
  ~World();

  World(const World&) = delete;
  World& operator=(const World&) = delete;
  World(World&&) = delete;
  World& operator=(World&&) = delete;

  void step();

  b2WorldId id() const { return _id; }

private:
  World();

  b2WorldId _id;
};

#endif
