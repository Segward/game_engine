#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <triangle.hpp>
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
    Triangle& _triangle{Triangle::instance()};

    Texture _grass_texture{"assets/grass.jpeg"};
    Texture _snow_texture{"assets/snow.jpg"};

    std::vector<TriangleInstance> _grass_triangles;
    std::vector<TriangleInstance> _snow_triangles;

    Terrain() = default;
};

#endif
