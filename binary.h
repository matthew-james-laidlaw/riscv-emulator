#pragma once

#include "cli.h"

#include <cstdint>
#include <filesystem>
#include <fstream>
#include <print>
#include <vector>

namespace fs = std::filesystem;

inline auto LoadBinary(fs::path const& filepath) -> std::vector<uint8_t>
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

inline auto PrintBinary(std::vector<uint8_t> const& binary) -> void
{
  std::println("Loaded bytes:");
  for (auto byte : binary) {
    std::print("0x{:02X}, ", byte);
  }
  std::println();
}

