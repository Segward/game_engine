#include <load.hpp>
#include <store.hpp>
#include <texture.hpp>
#include <sprite.hpp>
#include <object.hpp>

void load::textures() {
  Store<Texture>& store = Store<Texture>::instance();
  store.emplace_back("assets/sprite_sheet.png");
  store.emplace_back("assets/background.png");
}

void load::sprites() {
  Store<Sprite>& store = Store<Sprite>::instance();

  store.emplace_back(0, glm::vec2{0.0f / 64.0f, 0.0f / 64.0f}, glm::vec2{16.0f / 64.0f, 16.0f / 64.0f});
  store.emplace_back(0, glm::vec2{16.0f / 64.0f, 0.0f / 64.0f}, glm::vec2{16.0f / 64.0f, 16.0f / 64.0f});
  store.emplace_back(0, glm::vec2{32.0f / 64.0f, 0.0f / 64.0f}, glm::vec2{16.0f / 64.0f, 16.0f / 64.0f});

  store.emplace_back(0, glm::vec2{0.0f / 64.0f, 16.0f / 64.0f}, glm::vec2{16.0f / 64.0f, 16.0f / 64.0f});
  store.emplace_back(0, glm::vec2{16.0f / 64.0f, 16.0f / 64.0f}, glm::vec2{16.0f / 64.0f, 16.0f / 64.0f});
  store.emplace_back(0, glm::vec2{32.0f / 64.0f, 16.0f / 64.0f}, glm::vec2{16.0f / 64.0f, 16.0f / 64.0f});

  store.emplace_back(0, glm::vec2{0.0f / 64.0f, 32.0f / 64.0f}, glm::vec2{16.0f / 64.0f, 16.0f / 64.0f});
  store.emplace_back(0, glm::vec2{16.0f / 64.0f, 32.0f / 64.0f}, glm::vec2{16.0f / 64.0f, 16.0f / 64.0f});
  store.emplace_back(0, glm::vec2{32.0f / 64.0f, 32.0f / 64.0f}, glm::vec2{16.0f / 64.0f, 16.0f / 64.0f});
}

void load::objects() {
  Store<Object>& store = Store<Object>::instance();

  store.emplace_back(4, glm::vec2{-50.0f, 0.0f}, glm::vec2{50.0f, 50.0f});
  store.emplace_back(4, glm::vec2{0.0f, 0.0f}, glm::vec2{50.0f, 50.0f});
  store.emplace_back(4, glm::vec2{50.0f, 0.0f}, glm::vec2{50.0f, 50.0f});

  store.emplace_back(0, glm::vec2{100.0f, 200.0f}, glm::vec2{50.0f, 50.0f});
}

