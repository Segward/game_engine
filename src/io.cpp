#include <io.hpp>

std::string IO::read(const char* path) {
  constexpr std::uintmax_t MAX_SIZE = 1ull << 30;

  std::error_code ec;
  std::uintmax_t size = std::filesystem::file_size(path, ec);
  if (ec) {
    throw std::runtime_error(std::string("IO::read failed to stat ") + path + ": " + ec.message());
  }

  if (size > MAX_SIZE) {
    throw std::runtime_error(std::string("IO::read file exceeds size limit: ") + path);
  }

  std::ifstream stream(path, std::ios::binary);
  if (!stream) {
    throw std::runtime_error(std::string("IO::read failed to open ") + path);
  }

  std::string result(static_cast<size_t>(size), '\0');
  stream.read(result.data(), static_cast<std::streamsize>(size));
  if (static_cast<std::uintmax_t>(stream.gcount()) != size) {
    throw std::runtime_error(std::string("IO::read short read on ") + path);
  }

  return result;
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
