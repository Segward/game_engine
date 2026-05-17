#ifndef IO_HPP
#define IO_HPP

class IO {
  public:
    static std::string read(const char* path);
    static void write(const char* path, std::string_view content);
};

#endif
