#pragma once

#include "cli.h"

#include <cstdint>
#include <vector>

class Memory
{
private:

  std::vector<uint8_t> m_bytes;

public:

  Memory(uint32_t size)
    : m_bytes(size, 0)
  {}

  template <typename T>
    requires(std::is_unsigned_v<T>)
  auto Read(uint32_t addr) const -> uint8_t
  {
    (void)addr;
    PrintNotImplementedAndExit("Memory::Read");
    return 0;
  }

  template <typename T>
    requires(std::is_unsigned_v<T>)
  auto Write(uint32_t addr, uint8_t value) -> void
  {
    (void)addr;
    (void)value;
    PrintNotImplementedAndExit("Memory::Write");
  }

};

