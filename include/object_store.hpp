#ifndef OBJECT_STORE_HPP
#define OBJECT_STORE_HPP

#include <object.hpp>

class ObjectStore {
  public:
    static ObjectStore& instance();

    ObjectStore(const ObjectStore&) = delete;
    ObjectStore& operator=(const ObjectStore&) = delete;
    ObjectStore(ObjectStore&&) = delete;
    ObjectStore& operator=(ObjectStore&&) = delete;

    int store(const int sprite_id, const glm::vec2& position, const glm::vec2& size);
    const std::vector<Object>& get_objects() const { return _objects; }

  private:
    std::vector<Object> _objects;

    ObjectStore() = default;
};

#endif
