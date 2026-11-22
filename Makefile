CXX = g++
CXXFLAGS = --std=c++23 -Wall -Wextra -Werror -g -O0

BINARY_DIR = build
TARGET = riscv-emulator

SOURCES = main.cpp

build:
	mkdir -p $(BINARY_DIR)
	$(CXX) -o $(BINARY_DIR)/$(TARGET) $(CXXFLAGS) $(SOURCES)

run: build
	./build/riscv-emulator test.bin

clean:
	rm -rf build

.PHONY: build run clean

