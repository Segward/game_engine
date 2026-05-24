#include <window.hpp>

Window& Window::instance() {
  static Window window;
  return window;
}

Window::Window() {
  _handle = glfwCreateWindow(1280, 720, "game engine", nullptr, nullptr);
  if (!_handle) {
    throw std::runtime_error("glfwCreateWindow failed");
  }

  glfwMakeContextCurrent(_handle);
  glfwSwapInterval(1);

  glfwGetFramebufferSize(_handle, &_width, &_height);

  glfwSetWindowUserPointer(_handle, this);
  glfwSetFramebufferSizeCallback(_handle, framebuffer_size_callback);
}

Window::~Window() {
  if (!_handle) {
    return;
  }

  glfwDestroyWindow(_handle);
  glfwTerminate();
}

void Window::set_should_close(bool value) {
  glfwSetWindowShouldClose(_handle, value ? GLFW_TRUE : GLFW_FALSE);
}

bool Window::should_close() const {
  return glfwWindowShouldClose(_handle);
}

void Window::swap_buffers() {
  glfwSwapBuffers(_handle);
}

void Window::poll_events() {
  glfwPollEvents();
}

bool Window::key_pressed(int key) const {
  return glfwGetKey(_handle, key) == GLFW_PRESS;
}

void Window::framebuffer_size_callback(GLFWwindow* handle, int width, int height) {
  Window* self = static_cast<Window*>(glfwGetWindowUserPointer(handle));
  if (!self) {
    return;
  }

  self->_width = width;
  self->_height = height;

  glViewport(0, 0, width, height);
}
