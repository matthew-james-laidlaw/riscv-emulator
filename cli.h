#pragma once

#include <print>

inline auto PrintUsageAndExit(const char* arg0) -> void
{
  std::println("usage: {} <input.bin>", arg0);
  std::exit(1);
}

inline auto PrintFileNotFoundAndExit(const char* filename) -> void
{
  std::println("error: file not found '{}'", filename);
  std::exit(1);
}

inline auto PrintFileFailedToOpenAndExit(const char* filename) -> void
{
  std::println("error: file failed to open '{}'", filename);
  std::exit(1);
}

inline auto PrintBinaryEmptyAndExit(const char* filename) -> void
{
  std::println("error: binary file is empty '{}'", filename);
  std::exit(1);
}

