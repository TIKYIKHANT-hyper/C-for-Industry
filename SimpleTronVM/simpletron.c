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
    OP_STR,//STORE REGISTER
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

int main(int argc,const char *argv[]){
    reg[R_COND] = FL_ZRO;
    enum {PC_START = 0x3000 };
    reg[R_PC] = PC_START;
    int running = 1;
    while(running){
        /*Fetch*/
        if(argc < 2){//show usage string
            printf("lc3 [image-file1] ...\n");
            exit(2);
        }
        for(int j = 1; j < argc; ++j){
            if(!read_image(argv[j])){
                printf("fail to load image %s \n",argv[j]);
                exit(1);
            }
        }
        unsigned short instr = mem_read(reg[R_PC]++);
        unsigned short op = instr >> 12;

        switch (op) {
            case OP_ADD:
                break;
            case OP_AND:
                break;
            case OP_NOT:
                break;
            case OP_BR:
                break;
            case OP_JMP:
                break;
            case OP_JSR:
                break;
            case OP_LD:
                break;
            case OP_LDI:
                break;
            case OP_LDR:
                break;
            case OP_LEA:
                break;
            case OP_ST:
                break;
            case OP_STI:
                break;
            case OP_STR:
                break;
            case OP_TRAP:
                break;
            case OP_RES:
            case OP_RTI:
            default:
                break;
        }
    }
    //shutdown
}
