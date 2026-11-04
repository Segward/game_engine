#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <face.hpp>
#include <texture.hpp>

class Terrain {
  public:
    static Terrain& instance();

    Terrain(const Terrain&) = delete;
    Terrain& operator=(const Terrain&) = delete;
    Terrain(Terrain&&) = delete;
    Terrain& operator=(Terrain&&) = delete;

    void generate();
    void draw();

  private:
    Face& _face{Face::instance()};

    Texture _grass_texture{"assets/grass.jpeg"};
    Texture _snow_texture{"assets/snow.jpg"};
    Texture _stone_texture{"assets/stone.png"};

    std::vector<FaceInstance> _grass_faces;
    std::vector<FaceInstance> _snow_faces;
    std::vector<FaceInstance> _stone_faces;

    Terrain() = default;
};

#endif
