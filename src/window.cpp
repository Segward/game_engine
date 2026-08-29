#include <GLFW/glfw3.h>
#include <window.hpp>

Window& Window::instance() {
  static Window window;
  return window;
}

bool Window::should_close() const {
  return glfwWindowShouldClose(_handle);
}

void Window::set_should_close(bool value) {
  glfwSetWindowShouldClose(_handle, value);
}

void Window::poll_events() {
  glfwPollEvents();
}

void Window::swap_buffers() {
  glfwSwapBuffers(_handle);
}

bool Window::key_pressed(int key) const {
  return glfwGetKey(_handle, key) == GLFW_PRESS;
}

Window::Window() {
  _handle = glfwCreateWindow(1280, 720, "test", nullptr, nullptr);
  if (!_handle) {
    glfwTerminate();
    throw std::runtime_error("window failed to create");
  }

  glfwMakeContextCurrent(_handle);
  glfwGetFramebufferSize(_handle, &_width, &_height);
  glfwSetWindowUserPointer(_handle, this);
  glfwSetFramebufferSizeCallback(_handle, resize_callback);
}

Window::~Window() {
  if (!_handle) return;

  glfwDestroyWindow(_handle);
  glfwTerminate();
}

void Window::resize_callback(GLFWwindow* handle, int width, int height) {
  Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(handle));
  if (!window) return;

  window->_width = width;
  window->_height = height;
  glViewport(0, 0, width, height);
}
