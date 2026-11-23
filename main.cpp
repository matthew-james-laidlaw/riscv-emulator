#include "binary.h"
#include "cli.h"
#include "memory.h"
#include "proc.h"

auto main(int argc, char** argv) -> int
{
  if (argc != 2) {
    PrintUsageAndExit(argv[0]);
  }

  if (!fs::exists(argv[1])) {
    PrintFileNotFoundAndExit(argv[1]);
  }

  const auto filepath = fs::path(argv[1]);
  const auto binary = LoadBinary(filepath);

  PrintBinary(binary);

  auto proc = ProcessorRV32I(); 

  return 0;
}

