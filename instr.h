#pragma once

#include <cstdint>

enum class Op
{
  ADD, ADDI, AND, ANDI, AUIPC,
  BEQ, BGE, BGEU, BLT, BLTU, BNE,
  EBREAK, ECALL,
  FENCE,
  JAL, JALR,
  LB, LBU, LH, LHU, LUI, LW,
  OR, ORI,
  SB, SH, SLL, SLLI, SLT, SLTI, SLTIU, SLTU, SRA, SRAI, SRL, SRLI, SUB, SW,
  XOR, XORI,
};

struct Instruction
{
  Op op;
  uint8_t opcode;
  uint8_t rd;
  uint8_t funct3;
  uint8_t rs1;
  uint8_t rs2;
  uint8_t funct7;
  uint16_t imm;
};

