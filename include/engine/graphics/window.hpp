#ifndef WINDOW_HPP
#define WINDOW_HPP

struct GLFWwindow;

class Window {
  public:
    Window(int width, int height, const char *title);
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
    Window(Window&&) noexcept;
    Window& operator=(Window&&) noexcept;

    void set_should_close(bool value);
    bool should_close() const;
    void swap_buffers();
    void poll_events();
    bool key_pressed(int key) const;

    int width() const { return _width; }
    int height() const { return _height; }
    GLFWwindow *handle() const { return _handle; }

  private:
    GLFWwindow* _handle{nullptr};
    int _width{0};
    int _height{0};

    static bool _exists;

    static void framebuffer_size_callback(GLFWwindow* handle, int width, int height);
};

#endif
