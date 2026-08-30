#include <init.hpp>
#include <window.hpp>
#include <quad.hpp>
#include <camera.hpp>
#include <sprite_store.hpp>
#include <texture_store.hpp>
#include <object_store.hpp>

int main() {
  try {
    init::glfw();
    Window& window = Window::instance();
    init::glad();
    init::textures();
    init::sprites();
    init::objects();

    SpriteStore& sprite_store = SpriteStore::instance();
    TextureStore& texture_store = TextureStore::instance();
    ObjectStore& object_store = ObjectStore::instance();
    Camera& camera = Camera::instance();
    Quad& quad = Quad::instance();

    while (!window.should_close()) {
      camera.update();
      window.poll_events();

      if (window.key_pressed(GLFW_KEY_ESCAPE)) {
        window.set_should_close(true);
      }

      glClear(GL_COLOR_BUFFER_BIT);

      quad.set_projection(camera.get_projection());

      for (const Object& object : object_store.get_objects()) {
        texture_store.load(object.get_texture_id());

        const Sprite& sprite = sprite_store.get_sprite(object.get_sprite_id());
        quad.set_uv_offset(sprite.get_uv_offset());
        quad.set_uv_scale(sprite.get_uv_scale());

        quad.draw(object.get_position(), object.get_size());
      }

      window.swap_buffers();
    }
  } catch (const std::exception& exception) {
    std::cout << exception.what() << "\n";
  }

  return 0;
}
