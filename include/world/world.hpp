#ifndef WORLD_HPP
#define WORLD_HPP

class Object;

class World {
  public:
    static constexpr b2Vec2 GRAVITY = {0.0f, -0.7f};
    static constexpr float PIXELS_PER_METER = 50.0f;
    static constexpr float TIMESTEP = 1.0f / 60.0f;
    static constexpr int SUB_STEPS = 4;

    static World& instance();
    ~World();

    World(const World&) = delete;
    World(World&&) = delete;
    World& operator=(const World&) = delete;
    World& operator=(World&&) = delete;

    b2WorldId id() const { return _id; }

    Object& create_object(b2BodyType type);
    void render() const;
    void step();

  private:
    World();

    b2WorldId _id;
    std::vector<std::unique_ptr<Object>> _objects;
};

#endif
