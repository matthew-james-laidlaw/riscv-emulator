#include "binary.h"
#include "cli.h"

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

