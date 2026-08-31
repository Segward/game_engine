#include <time.hpp>

Time& Time::instance() {
  static Time time;
  return time;
}

void Time::update() {
  std::chrono::steady_clock::time_point current_time = std::chrono::steady_clock::now();
  _delta = std::chrono::duration<float>(current_time - _previous_time).count();
  _previous_time = current_time;
}
