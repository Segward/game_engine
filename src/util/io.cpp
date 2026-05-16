#include "util/io.hpp"

std::string Io::read_file(const std::string& path) {
  std::ifstream file(path);
  if (!file) {
    throw std::runtime_error("failed to open " + path);
  }

  std::ostringstream stream;
  stream << file.rdbuf();
  return stream.str();
}

void Io::write_file(const std::string& path, const std::string& content) {
  std::ofstream file(path);
  if (!file) {
    throw std::runtime_error("failed to open " + path);
  }

  file << content;
  if (!file) {
    throw std::runtime_error("failed to write " + path);
  }
}
