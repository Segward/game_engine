#ifndef IO_HPP
#define IO_HPP

namespace io {
inline constexpr std::uintmax_t DEFAULT_READ_LIMIT = 1ull << 30;

std::string read(const char* path, std::uintmax_t max_size = DEFAULT_READ_LIMIT);
void write(const char* path, std::string_view content);
}  // namespace io

#endif
