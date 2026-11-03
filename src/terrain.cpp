#include <terrain.hpp>

namespace {
  constexpr int terrain_size = 256;
  constexpr float snow_height = 12.0f;
  const glm::vec3 light_direction = glm::normalize(glm::vec3{0.4f, 1.0f, 0.3f});

  glm::vec3 get_triangle_corner(int x, int z) {
    float distance = glm::length(glm::vec2{x, z} - terrain_size * 0.5f);
    float height = 20.0f * std::exp(-distance * distance / 400.0f);
    return {(x - terrain_size * 0.5f), height, (z - terrain_size * 0.5f)};
  }

  TriangleInstance get_triangle_instance(const glm::vec3& a, const glm::vec3& b, const glm::vec3& c) {
    glm::vec3 normal = glm::normalize(glm::cross(b - a, c - a));
    float light = 0.4f + 0.6f * std::max(glm::dot(normal, light_direction), 0.0f);
    return {{a, b, c}, glm::vec3{light}};
  }
}

Terrain& Terrain::instance() {
  static Terrain terrain;
  return terrain;
}

void Terrain::generate() {
  for (int z = 0; z < terrain_size; z++) {
    for (int x = 0; x < terrain_size; x++) {
      glm::vec3 a = get_triangle_corner(x, z);
      glm::vec3 b = get_triangle_corner(x, z + 1);
      glm::vec3 c = get_triangle_corner(x + 1, z + 1);
      glm::vec3 d = get_triangle_corner(x + 1, z);

      std::vector<TriangleInstance>& triangles = a.y > snow_height ? _snow_triangles : _grass_triangles;
      triangles.push_back(get_triangle_instance(a, b, c));
      triangles.push_back(get_triangle_instance(c, d, a));
    }
  }
}

void Terrain::draw() {
  _triangle.draw(_grass_triangles, _grass_texture);
  _triangle.draw(_snow_triangles, _snow_texture);
}
