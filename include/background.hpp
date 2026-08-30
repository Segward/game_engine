#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

class Background {
  public:
    static Background& instance();

    Background(const Background&) = delete;
    Background& operator=(const Background&) = delete;
    Background(Background&&) = delete;
    Background& operator=(Background&&) = delete;

    void draw();

  private:
    Background() = default;
};

#endif
