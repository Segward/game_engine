#ifndef WINDOW_HPP
#define WINDOW_HPP

class Window {
public:
  static Window& instance();
  ~Window();

  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;
  Window(Window&&) = delete;
  Window& operator=(Window&&) = delete;

  void set_should_close(bool value);
  bool should_close() const;
  void swap_buffers();
  static void poll_events();
  bool key_pressed(int key) const;

  int width() const { return _width; }
  int height() const { return _height; }

private:
  Window();

  GLFWwindow* _handle{nullptr};
  int _width{0};
  int _height{0};

  static void framebuffer_size_callback(GLFWwindow* handle, int width, int height);
};

#endif
