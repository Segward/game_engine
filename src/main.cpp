#include "engine/engine.hpp"
#include "engine/objects/block.hpp"
#include "engine/objects/player.hpp"

namespace {
  std::unique_ptr<Block> make_block(glm::vec2 position, glm::vec2 size, glm::vec4 color) {
    auto block = std::make_unique<Block>();
    block->position = position;
    block->size = size;
    block->color = color;
    return block;
  }
}

int main() {
  try {
    Engine engine;
    World& world = engine.world();
    world.add(make_block({-0.5f,  0.5f}, {0.3f, 0.3f}, {1.0f, 0.3f, 0.3f, 1.0f}));
    world.add(make_block({ 0.5f,  0.5f}, {0.3f, 0.3f}, {0.3f, 1.0f, 0.3f, 1.0f}));
    world.add(make_block({-0.5f, -0.5f}, {0.3f, 0.3f}, {0.3f, 0.3f, 1.0f, 1.0f}));
    world.add(make_block({ 0.5f, -0.5f}, {0.3f, 0.3f}, {1.0f, 1.0f, 0.3f, 1.0f}));

    auto player_owned = std::make_unique<Player>();
    player_owned->position = {0.0f, 0.0f};
    player_owned->size = {0.2f, 0.2f};
    player_owned->color = {0.9f, 0.9f, 0.9f, 1.0f};
    Object& player = world.add(std::move(player_owned));
    engine.camera().set_target(&player);

    engine.run();
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
