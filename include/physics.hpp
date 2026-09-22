#ifndef PHYSICS_HPP
#define PHYSICS_HPP

class Physics {
  public:
    static Physics& instance();

    Physics(const Physics&) = delete;
    Physics& operator=(const Physics&) = delete;
    Physics(Physics&&) = delete;
    Physics& operator=(Physics&&) = delete;

    void step();

    b2WorldId get_world_id() const { return _world_id; }

  private:
    b2WorldId _world_id{b2_nullWorldId};

    Physics();
    ~Physics();
};

#endif
