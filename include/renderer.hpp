#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <camera.hpp>
#include <sprite_store.hpp>
#include <texture_store.hpp>
#include <object_store.hpp>
#include <camera.hpp>
#include <quad.hpp>

class Renderer {
  public:
    static Renderer& instance();

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;
    Renderer(Renderer&&) = delete;
    Renderer& operator=(Renderer&&) = delete;

    void draw();

  private:
    SpriteStore& _sprite_store{SpriteStore::instance()};
    TextureStore& _texture_store{TextureStore::instance()};
    ObjectStore& _object_store{ObjectStore::instance()};
    Camera& _camera{Camera::instance()};
    Quad& _quad{Quad::instance()};

    Renderer() = default;
};

#endif
