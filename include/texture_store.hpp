#ifndef TEXTURE_STORE
#define TEXTURE_STORE

#include <texture.hpp>

class TextureStore {
  public:
    static TextureStore& instance();

    TextureStore(const TextureStore&) = delete;
    TextureStore& operator=(const TextureStore&) = delete;
    TextureStore(TextureStore&&) = delete;
    TextureStore& operator=(TextureStore&&) = delete;

    int store(const std::string& texture_path);
    void load(const int texture_id) { _textures[texture_id].bind(); }

  private:
    std::vector<Texture> _textures;

    TextureStore() = default;
};

#endif
