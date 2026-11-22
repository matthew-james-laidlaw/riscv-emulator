#include <print>

auto PrintUsage(char* arg0) -> void
{
  std::println("usage: {} <input.bin>", arg0);
}

auto main(int argc, char** argv) -> int
{
  if (argc != 2) {
    PrintUsage(argv[0]);
    return 1;
  }

  return 0;
}

