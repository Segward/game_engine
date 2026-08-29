#include <init.hpp>
#include <window.hpp>
#include <quad.hpp>
#include <camera.hpp>
#include <sprite_store.hpp>
#include <texture_store.hpp>

int main() {
  try {
    init::glfw();
    Window& window = Window::instance();
    init::glad();
    init::textures();
    init::sprites();

    SpriteStore& sprite_store = SpriteStore::instance();
    TextureStore& texture_store = TextureStore::instance();
    Quad& quad = Quad::instance();
    Camera& camera = Camera::instance();

    while (!window.should_close()) {
      camera.update();
      window.poll_events();

      if (window.key_pressed(GLFW_KEY_ESCAPE)) {
        window.set_should_close(true);
      }

      glClear(GL_COLOR_BUFFER_BIT);

      const Sprite& dirt = sprite_store.get_sprite(4);
      texture_store.load(dirt.get_texture_id());

      quad.set_uv_offset(dirt.get_uv_offset());
      quad.set_uv_scale(dirt.get_uv_scale());
      quad.set_projection(camera.get_projection());

      quad.draw({100.0f, 100.0f}, {64.0f, 64.0f});
      quad.draw({200.0f, 100.0f}, {64.0f, 64.0f});

      window.swap_buffers();
    }
  } catch (const std::exception& exception) {
    std::cout << exception.what() << "\n";
  }

  return 0;
}
