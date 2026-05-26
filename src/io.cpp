#include <io.hpp>

std::string io::read(const std::string& path) {
  if (!std::filesystem::is_regular_file(path)) {
    throw std::runtime_error(path + " is not regular");
  }

  std::ifstream file;
  file.exceptions(std::ios::failbit | std::ios::badbit);
  file.open(path, std::ios::binary);

  std::uintmax_t size = std::filesystem::file_size(path);
  if (size > (1ull << 30)) {
    throw std::runtime_error(path + " is too big");
  }

  std::string buffer(static_cast<size_t>(size), '\0');
  file.read(buffer.data(), size);

  return buffer;
}
