#ifndef STORE_HPP
#define STORE_HPP

template <typename T>
class Store {
  public:
    static Store& instance() {
      static Store store;
      return store;
    }

    Store(const Store&) = delete;
    Store& operator=(const Store&) = delete;
    Store(Store&&) = delete;
    Store& operator=(Store&&) = delete;

    template <typename... Args>
    int emplace_back(Args&&... args) {
      _items.emplace_back(std::forward<Args>(args)...);
      return static_cast<int>(_items.size()) - 1;
    }

    T& get(const int id) { return _items[id]; }
    std::vector<T>& get_all() { return _items; }
    void reserve(const int count) { _items.reserve(count); }

  private:
    std::vector<T> _items;

    Store() = default;
};

#endif
