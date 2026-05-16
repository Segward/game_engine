#ifndef IO_HPP
#define IO_HPP

class Io {
  public:
    static std::string read_file(const std::string& path);
    static void write_file(const std::string& path, const std::string& content);
};

#endif
