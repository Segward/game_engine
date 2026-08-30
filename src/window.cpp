#include <window.hpp>
#include <init.hpp>
#include <renderer.hpp>

Window& Window::instance() {
  static Window window;
  return window;
}

Window::Window() {
  init::glfw();

  _handle = glfwCreateWindow(1280, 720, "test", nullptr, nullptr);
  if (!_handle) {
    glfwTerminate();
    throw std::runtime_error("window failed to create");
  }

  glfwMakeContextCurrent(_handle);

  int width = 0, height = 0;
  glfwGetFramebufferSize(_handle, &width, &height);
  _size = {width, height};

  glfwSetWindowUserPointer(_handle, this);
  glfwSetFramebufferSizeCallback(_handle, resize_callback);

  init::glad();
}

Window::~Window() {
  if (!_handle) return;

  glfwDestroyWindow(_handle);
  glfwTerminate();
}

void Window::resize_callback(GLFWwindow* handle, int width, int height) {
  Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(handle));
  if (!window) return;

  window->_size = {width, height};
  glViewport(0, 0, width, height);

  renderer::render();
}
