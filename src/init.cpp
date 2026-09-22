#include <init.hpp>
#include <window.hpp>
#include <store.hpp>
#include <texture.hpp>
#include <sprite.hpp>

void init::glfw() {
  if (!glfwInit()) {
    throw std::runtime_error("glfw failed to initialize");
  }

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void init::glad() {
  if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
    throw std::runtime_error("glad failed to initialize");
  }

  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);
}

void init::textures() {
  Store<Texture>& store = Store<Texture>::instance();
  store.emplace_back("assets/sprite_sheet.png");
  store.emplace_back("assets/background.png");
}

void init::sprites() {
  Store<Sprite>& store = Store<Sprite>::instance();
  store.emplace_back(0, glm::vec2{16.0f / 64.0f, 0.0f / 64.0f}, glm::vec2{16.0f / 64.0f, 16.0f / 64.0f});
  store.emplace_back(0, glm::vec2{16.0f / 64.0f, 16.0f / 64.0f}, glm::vec2{16.0f / 64.0f, 16.0f / 64.0f});
}
