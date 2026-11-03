#include <terrain.hpp>

namespace {
  int terrain_size = 128;
  float tile_size = 1.0f;
  float snow_height = 12.0f;
  glm::vec3 light_direction = glm::normalize(glm::vec3{0.4f, 1.0f, 0.3f});

  float get_height(int x, int z) {
    float distance = glm::length(glm::vec2{x, z} - terrain_size * 0.5f);
    return 20.0f * std::exp(-distance * distance / 400.0f);
  }

  glm::vec3 get_corner(int x, int z) {
    return {(x - terrain_size * 0.5f) * tile_size, get_height(x, z), (z - terrain_size * 0.5f) * tile_size};
  }

  TriangleInstance make_triangle(const glm::vec3& a, const glm::vec3& b, const glm::vec3& c, const glm::vec2& uv_a, const glm::vec2& uv_b, const glm::vec2& uv_c) {
    glm::vec3 normal = glm::normalize(glm::cross(b - a, c - a));
    float light = 0.4f + 0.6f * std::max(glm::dot(normal, light_direction), 0.0f);
    return {{a, b, c}, {uv_a, uv_b, uv_c}, glm::vec3{light}};
  }
}

Terrain& Terrain::instance() {
  static Terrain terrain;
  return terrain;
}

void Terrain::generate() {
  for (int z = 0; z < terrain_size; z++) {
    for (int x = 0; x < terrain_size; x++) {
      glm::vec3 a = get_corner(x, z);
      glm::vec3 b = get_corner(x, z + 1);
      glm::vec3 c = get_corner(x + 1, z + 1);
      glm::vec3 d = get_corner(x + 1, z);

      std::vector<TriangleInstance>& triangles = a.y > snow_height ? _snow_triangles : _grass_triangles;
      triangles.push_back(make_triangle(a, b, c, {0.0f, 0.0f}, {0.0f, 1.0f}, {1.0f, 1.0f}));
      triangles.push_back(make_triangle(c, d, a, {1.0f, 1.0f}, {1.0f, 0.0f}, {0.0f, 0.0f}));
    }
  }
}

void Terrain::draw() {
  _triangle.draw(_grass_triangles, _grass_texture);
  _triangle.draw(_snow_triangles, _snow_texture);
}
