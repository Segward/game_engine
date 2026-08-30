#include <engine.hpp>

int main() {
  try {
    Engine& engine = Engine::instance();
    engine.init();
    engine.start();
  } catch (const std::exception& exception) {
    std::cout << exception.what() << "\n";
  }

  return 0;
}
