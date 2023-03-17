//
// Created by Ti Kyi Khant on 3/17/2023.
//

#include <stdio.h>
#include <stdint.h>
#include <signal.h>
/* windows only */
#include <Windows.h>
#include <conio.h>

//Memory Storage
#define MEMORY_MAX (1 << 16)
unsigned short memory[MEMORY_MAX];

//Registers
enum
{
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC,//next instruction address in memory
    R_COND,//flag register, indicating previous instruction
    R_COUNT
};

unsigned short reg[R_COUNT];
//instruction set
//operation codes
//16-bit instruction set with left 4 bit serving as operation code

//here are operation codes

enum
{
    OP_BR = 0,//BRANCH
    OP_ADD,//ADD
    OP_LD,//LOAD
    OP_ST,//STORE
    OP_JSR,//JUMP REGISTER
    OP_AND,//BITWISE AND
    OP_LDR,//LOAD REGISTER
    OP_SDR,//STORE REGISTER
    OP_RTI,//UNUSED
    OP_NOT,//BITWISE NOT
    OP_LDI,//LOAD INDIRECT
    OP_STI,//STORE INDIRECT
    OP_JMP,//JUMP
    OP_RES,//RESERVED(UNUSED)
    OP_LEA,//LOAD EFFECTIVE ADDRESS
    OP_TRAP//EXECUTE TRAP
};

//condition flags

enum
{
    FL_POS = 1 << 0,//P
    FL_ZRO = 1 << 1,//Z
    FL_NEG = 1 << 2,//N
};

