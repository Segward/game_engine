#include <init.hpp>
#include <texture_store.hpp>
#include <sprite_store.hpp>

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
  TextureStore& store = TextureStore::instance();
  store.store("assets/sprite_sheet.png");
}

void init::sprites() {
  SpriteStore& store = SpriteStore::instance();
  store.store(0, {0.0f / 64.0f, 0.0f / 64.0f}, {16.0f / 64.0f, 16.0f / 64.0f});
  store.store(0, {16.0f / 64.0f, 0.0f / 64.0f}, {16.0f / 64.0f, 16.0f / 64.0f});
  store.store(0, {32.0f / 64.0f, 0.0f / 64.0f}, {16.0f / 64.0f, 16.0f / 64.0f});
  store.store(0, {0.0f / 64.0f, 16.0f / 64.0f}, {16.0f / 64.0f, 16.0f / 64.0f});
  store.store(0, {16.0f / 64.0f, 16.0f / 64.0f}, {16.0f / 64.0f, 16.0f / 64.0f});
  store.store(0, {32.0f / 64.0f, 16.0f / 64.0f}, {16.0f / 64.0f, 16.0f / 64.0f});
  store.store(0, {0.0f / 64.0f, 32.0f / 64.0f}, {16.0f / 64.0f, 16.0f / 64.0f});
  store.store(0, {16.0f / 64.0f, 32.0f / 64.0f}, {16.0f / 64.0f, 16.0f / 64.0f});
  store.store(0, {32.0f / 64.0f, 32.0f / 64.0f}, {16.0f / 64.0f, 16.0f / 64.0f});
}
