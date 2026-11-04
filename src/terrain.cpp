#include <terrain.hpp>

namespace {
  constexpr int terrain_size = 256;
  constexpr float snow_height = 12.0f;
  constexpr float stone_height = 2.0f;

  glm::vec3 get_face_corner(int x, int z) {
    float distance = glm::length(glm::vec2{x, z} - terrain_size * 0.5f);
    float height = 20.0f * std::exp(-distance * distance / 400.0f);
    return {(x - terrain_size * 0.5f), height, (z - terrain_size * 0.5f)};
  }
}

Terrain& Terrain::instance() {
  static Terrain terrain;
  return terrain;
}

void Terrain::generate() {
  for (int z = 0; z < terrain_size; z++) {
    for (int x = 0; x < terrain_size; x++) {
      glm::vec3 a = get_face_corner(x, z);
      glm::vec3 b = get_face_corner(x, z + 1);
      glm::vec3 c = get_face_corner(x + 1, z + 1);
      glm::vec3 d = get_face_corner(x + 1, z);

      FaceInstance face{{a, b, c, d}, glm::vec3{1.0f}};
      if (a.y > snow_height) _snow_faces.push_back(face);
      else if (a.y > stone_height) _stone_faces.push_back(face);
      else _grass_faces.push_back(face);
    }
  }
}

void Terrain::draw() {
  _face.draw(_grass_faces, _grass_texture);
  _face.draw(_stone_faces, _stone_texture);
  _face.draw(_snow_faces, _snow_texture);
}
