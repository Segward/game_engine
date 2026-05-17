#include <io.hpp>

std::string IO::read(const char* path) {
  std::ifstream stream(path, std::ios::binary);
  if (!stream) {
    throw std::runtime_error(std::string("IO::read failed to open ") + path);
  }

  std::ostringstream buffer;
  buffer << stream.rdbuf();
  return buffer.str();
}

void IO::write(const char* path, std::string_view content) {
  std::ofstream stream(path, std::ios::binary | std::ios::trunc);
  if (!stream) {
    throw std::runtime_error(std::string("IO::write failed to open ") + path);
  }

  stream.write(content.data(), static_cast<std::streamsize>(content.size()));
  if (!stream) {
    throw std::runtime_error(std::string("IO::write failed to write ") + path);
  }
}
