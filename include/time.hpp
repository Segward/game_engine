#ifndef TIME_HPP
#define TIME_HPP

class Time {
  public:
    static Time& instance();

    Time(const Time&) = delete;
    Time& operator=(const Time&) = delete;
    Time(Time&&) = delete;
    Time& operator=(Time&&) = delete;

    void update();

    float get_delta() const { return _delta; }

  private:
    std::chrono::steady_clock::time_point _previous_time{std::chrono::steady_clock::now()};
    float _delta{0.0f};

    Time() = default;
};

#endif
