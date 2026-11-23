#include <cstdint>
#include <filesystem>
#include <fstream>
#include <print>
#include <vector>

namespace fs = std::filesystem;

auto PrintUsageAndExit(const char* arg0) -> void
{
  std::println("usage: {} <input.bin>", arg0);
  std::exit(1);
}

auto PrintFileNotFoundAndExit(const char* filename) -> void
{
  std::println("error: file not found '{}'", filename);
  std::exit(1);
}

auto PrintFileFailedToOpenAndExit(const char* filename) -> void
{
  std::println("error: file failed to open '{}'", filename);
  std::exit(1);
}

auto PrintBinaryEmptyAndExit(const char* filename) -> void
{
  std::println("error: binary file is empty '{}'", filename);
  std::exit(1);
}

auto LoadBinary(fs::path const& filepath) -> std::vector<uint8_t>
{
  auto infile = std::ifstream(filepath, std::ios::binary);
  if (!infile) {
    PrintFileFailedToOpenAndExit(filepath.c_str());
  }

  auto buffer = std::vector<uint8_t>(
    std::istreambuf_iterator<char>(infile),
    std::istreambuf_iterator<char>()
  );

  if (buffer.empty()) {
    PrintBinaryEmptyAndExit(filepath.c_str());
  }

  return buffer;
}

auto PrintBinary(std::vector<uint8_t> const& binary) -> void
{
  std::println("Loaded bytes:");
  for (auto byte : binary) {
    std::print("0x{:02X}, ", byte);
  }
  std::println();
}

auto main(int argc, char** argv) -> int
{
  if (argc != 2) {
    PrintUsageAndExit(argv[0]);
  }

  if (!fs::exists(argv[1])) {
    PrintFileNotFoundAndExit(argv[1]);
  }

  auto filepath = fs::path(argv[1]);
  auto binary = LoadBinary(filepath);

  PrintBinary(binary);

  return 0;
}

