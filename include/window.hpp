#ifndef WINDOW_HPP
#define WINDOW_HPP

class Window {
  public: 
    static Window& instance();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
    Window(Window&&) = delete;
    Window& operator=(Window&&) = delete;

    bool should_close() const;
    void set_should_close(bool value);
    void poll_events();
    void swap_buffers();
    bool key_pressed(int key) const;

    int get_width() const { return _width; }
    int get_height() const { return _height; }

  private:
    GLFWwindow* _handle{nullptr};
    int _width{0};
    int _height{0};

    Window();
    ~Window();

    static void resize_callback(GLFWwindow* handle, int width, int height);
};

#endif
