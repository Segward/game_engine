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

    const T& get(const int id) const { return _items[id]; }
    const std::vector<T>& get_all() const { return _items; }

  private:
    std::vector<T> _items;

    Store() = default;
};

#endif
