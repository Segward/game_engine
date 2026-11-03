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
    void poll_events() { glfwPollEvents(); }
    void swap_buffers() { glfwSwapBuffers(_handle); }
    bool key_pressed(int key) const { return glfwGetKey(_handle, key) == GLFW_PRESS; }
    bool mouse_pressed(int button) const { return glfwGetMouseButton(_handle, button) == GLFW_PRESS; }
    glm::vec2 get_cursor_position() const { double x = 0.0, y = 0.0; glfwGetCursorPos(_handle, &x, &y); return {x, y}; }
    bool cursor_captured() const { return glfwGetInputMode(_handle, GLFW_CURSOR) == GLFW_CURSOR_DISABLED; }
    void set_cursor_captured(bool captured) { glfwSetInputMode(_handle, GLFW_CURSOR, captured ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL); }

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
