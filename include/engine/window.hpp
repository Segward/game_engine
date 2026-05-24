#ifndef WINDOW_HPP
#define WINDOW_HPP

class Window {
  public:
    static Window& instance();
    ~Window();

    Window(const Window&) = delete;
    Window(Window&&) = delete;
    Window& operator=(const Window&) = delete;
    Window& operator=(Window&&) = delete;

    int height() const { return _height; }
    int width() const { return _width; }

    bool key_pressed(int key) const;
    static void poll_events();
    void set_should_close(bool value);
    bool should_close() const;
    void swap_buffers();

  private:
    Window();

    static void framebuffer_size_callback(GLFWwindow* handle, int width, int height);

    GLFWwindow* _handle{nullptr};
    int _height{0};
    int _width{0};
};

#endif
