#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <camera.hpp>
#include <store.hpp>
#include <texture.hpp>
#include <sprite.hpp>
#include <object.hpp>
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
    Store<Sprite>& _sprite_store{Store<Sprite>::instance()};
    Store<Texture>& _texture_store{Store<Texture>::instance()};
    Store<Object>& _object_store{Store<Object>::instance()};
    Camera& _camera{Camera::instance()};
    Quad& _quad{Quad::instance()};

    Renderer() = default;
};

#endif
