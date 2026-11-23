#pragma once

#include "instr.h"
#include "memory.h"

#include <cstdint>

class ProcessorRV32I
{
private:

  uint32_t pc;
  uint32_t x[32];
  
  Memory m_memory;

public:

  ProcessorRV32I()
    : m_memory(65536)
  {}

  auto Step() -> void
  {
    const auto word = FetchAndIncrementPC();    
    const auto instruction = Decode(word);
    Execute(instruction);
  }

private:

  auto FetchAndIncrementPC() -> uint8_t
  {
    return m_memory.Read<uint8_t>(pc++);
  }

  auto DecodeField(uint32_t word, uint8_t start, uint8_t stop) const -> uint32_t
  {
    (void)word;
    (void)start;
    (void)stop;
    return 0;
  }

  auto GetOp(uint8_t opcode, uint8_t funct3, uint8_t funct7) const -> Op
  {
    (void)opcode;
    (void)funct3;
    (void)funct7;
    return Op::ADD;
  }

  auto GetImm(uint32_t word, Op op) const -> uint16_t
  {
    (void)word;
    (void)op;
    return 0;
  }

  auto Decode(uint32_t word) const -> Instruction
  {
    const auto opcode = static_cast<uint8_t>(DecodeField(word, 0, 7));
    const auto rd = static_cast<uint8_t>(DecodeField(word, 7, 12));
    const auto funct3 = static_cast<uint8_t>(DecodeField(word, 12, 15));
    const auto rs1 = static_cast<uint8_t>(DecodeField(word, 15, 20));
    const auto rs2 = static_cast<uint8_t>(DecodeField(word, 20, 25));
    const auto funct7 = static_cast<uint8_t>(DecodeField(word, 25, 32));
    const auto op = GetOp(opcode, funct3, funct7);
    const auto imm = GetImm(word, op);

    return Instruction {
      .op = op,
      .opcode = opcode,
      .rd = rd,
      .funct3 = funct3,
      .rs1 = rs1,
      .rs2 = rs2,
      .funct7 = funct7,
      .imm = imm
    };
  }

  auto Execute(Instruction instr) -> void
  {
    (void)instr;
  }

};

