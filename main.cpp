#include <print>
#include <filesystem>

namespace fs = std::filesystem;

auto PrintUsage(char* arg0) -> void
{
  std::println("usage: {} <input.bin>", arg0);
}

auto PrintFileNotFound(char* filename) -> void
{
  std::println("file not found error: {}", filename);
}

auto main(int argc, char** argv) -> int
{
  if (argc != 2) {
    PrintUsage(argv[0]);
    return 1;
  }

  if (!fs::exists(argv[1])) {
    PrintFileNotFound(argv[1]);
    return 1;
  }

  return 0;
}

