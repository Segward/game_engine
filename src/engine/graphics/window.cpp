#include "engine/graphics/window.hpp"

bool Window::_exists = false;

Window::Window(int width, int height, const char *title) {
  if (_exists) {
    throw std::runtime_error("only one window allowed");
  }

  if (!glfwInit()) {
    throw std::runtime_error("glfwInit failed");
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

  _handle = glfwCreateWindow(width, height, title, nullptr, nullptr);
  if (!_handle) {
    glfwTerminate();
    throw std::runtime_error("glfwCreateWindow failed");
  }

  glfwMakeContextCurrent(_handle);
  glfwSwapInterval(0);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    glfwTerminate();
    throw std::runtime_error("gladLoadGLLoader failed");
  }

  _width = width;
  _height = height;

  glfwSetWindowUserPointer(_handle, this);
  glfwSetFramebufferSizeCallback(_handle, framebuffer_size_callback);

  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);

  _exists = true;
}

Window::~Window() {
  if (!_handle) {
    return;
  }

  glfwDestroyWindow(_handle);
  glfwTerminate();
  _exists = false;
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

  self->_width = width;
  self->_height = height;

  glViewport(0, 0, width, height);
}
