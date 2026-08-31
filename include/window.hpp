#ifndef WINDOW_HPP
#define WINDOW_HPP

class Window {
  public: 
    static Window& instance();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
    Window(Window&&) = delete;
    Window& operator=(Window&&) = delete;

    bool should_close() const { return glfwWindowShouldClose(_handle); }
    void set_should_close(bool value) { glfwSetWindowShouldClose(_handle, value); }
    void poll_events() { glfwPollEvents(); }
    void swap_buffers() { glfwSwapBuffers(_handle); }
    bool key_pressed(int key) const { return glfwGetKey(_handle, key) == GLFW_PRESS; }
    const glm::vec2& get_size() const { return _size; }
    float get_width() const { return _size.x; }
    float get_height() const { return _size.y; }

  private:
    GLFWwindow* _handle{nullptr};
    glm::vec2 _size{0.0f};

    Window();
    ~Window();

    static void resize_callback(GLFWwindow* handle, int width, int height);
};

#endif
