#ifndef TEXTURE_STORE
#define TEXTURE_STORE

#include <texture_handle.hpp>

class TextureStore {
  public:
    static TextureStore& instance();

    TextureStore(const TextureStore&) = delete;
    TextureStore& operator=(const TextureStore&) = delete;
    TextureStore(TextureStore&&) = delete;
    TextureStore& operator=(TextureStore&&) = delete;

    int store(const std::string& texture_path);
    const TextureHandle& get(int id) const { return _textures[id]; };
    void load(int id) { _textures[id].bind(0); }

  private:
    std::vector<TextureHandle> _textures;

    TextureStore() = default;
};

#endif
