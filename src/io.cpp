#include <io.hpp>

std::string io::read(const char* path, std::uintmax_t max_size) {
  if (!std::filesystem::is_regular_file(path)) {
    throw std::runtime_error(std::string("io::read not a regular file: ") + path);
  }

  std::uintmax_t size = std::filesystem::file_size(path);
  if (size > max_size) {
    throw std::runtime_error(std::string("io::read file exceeds size limit: ") + path);
  }

  std::ifstream stream;
  stream.exceptions(std::ios::failbit | std::ios::badbit);
  stream.open(path, std::ios::binary);

  std::string result(static_cast<size_t>(size), '\0');
  stream.read(result.data(), static_cast<std::streamsize>(size));
  return result;
}

void io::write(const char* path, std::string_view content) {
  std::ofstream stream;
  stream.exceptions(std::ios::failbit | std::ios::badbit);
  stream.open(path, std::ios::binary | std::ios::trunc);

  stream.write(content.data(), static_cast<std::streamsize>(content.size()));
  stream.close();
}
