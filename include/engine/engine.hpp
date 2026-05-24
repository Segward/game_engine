#ifndef ENGINE_HPP
#define ENGINE_HPP

class Engine {
  public:
    static Engine& instance();

    Engine(const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator=(const Engine&) = delete;
    Engine& operator=(Engine&&) = delete;

    void run();

  private:
    Engine();
};

#endif
