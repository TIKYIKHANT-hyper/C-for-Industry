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

unsigned short sign_extend(unsigned short x, int bit_count);
void update_flags(unsigned short r);

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
            case OP_ADD: {
                /*destination register (DR)*/
                unsigned short r0 = (instr >> 9) & 0x7;
                /*first operand SR1*/
                unsigned short r1 = (instr >> 6) & 0x7;
                /*whether in immediate mode*/
                unsigned short imm_flag = (instr >> 5) & 0x1;
                if(imm_flag){
                    unsigned short imm5 = sign_extend(instr & 0x1F, 5);
                    reg[r0] = reg[r1] + imm5;
                }
                else {
                    unsigned short r2 = instr & 0x7;
                    reg[r0] = reg[r1] + reg[r2];
                }
                update_flags(r0);
            }
                break;
            case OP_AND:
            {
                unsigned short r0 = (instr >> 9) & 0x7;
                unsigned short r1 = (instr >> 6) & 0x7;
                unsigned short imm_flag = (instr >> 5) & 0x1;
                if(imm_flag){
                    unsigned short imm5 = sign_extend(instr & 0x1F,5);
                    reg[r0] = reg[r1] + imm5;
                }
                else{
                    unsigned short r2 = instr & 0x7;
                    reg[r0] = reg[r1] + reg[r2];
                }
                update_flags(r0);
            }
                break;
            case OP_NOT:
            {
                unsigned short r0 = (instr >> 9) & 0x7;
                unsigned short r1 = (instr >> 6) & 0x7;
                reg[r0] = ~reg[r1];
                update_flags(r0);
            }
                break;
            case OP_BR:
            {
                unsigned short pc_offset = sign_extend(instr & 0x1FF,9);
                unsigned short cond_flag = (instr >> 9) & 0x7;
                if(cond_flag & reg[R_COND]){
                    reg[R_PC] += pc_offset;
                }
            }
                break;
            case OP_JMP:
            {
                unsigned short r1 = (instr >> 6) & 0x7;
                reg[R_PC] = reg[r1];
            }
                break;
            case OP_JSR:
            {
                unsigned short long_flag = (instr >> 11) & 0x1;
                reg[R_R7] = reg[R_PC];
                if(long_flag){
                    unsigned short long_pc_offset = sign_extend(instr & 0x7FF, 11);
                    reg[R_PC] += long_pc_offset;//JSR
                }
                else{
                    unsigned short r1 = (instr >> 6) & 0x7;
                    reg[R_PC] = reg[r1];//JSSR
                }
            }
                break;
            case OP_LD:
            {
                unsigned short r0 = (instr >> 9) & 0x7;
                unsigned short pc_offset = sign_extend(instr & 0x1FF,9);
                reg[r0] = mem_read(reg[R_PC] + pc_offset);
                update_flags(r0);
            }
                break;
            case OP_LDI:
            {
                unsigned short r0 = (instr >> 9) & 0x7;
                unsigned short pc_offset = sign_extend(instr & 0x1FF,9);
                reg[r0] = mem_read(reg[R_PC] + pc_offset);
                update_flags(r0);
            }
                break;
            case OP_LDR:
            {
                unsigned short r0 = (instr >> 9) & 0x7;
                unsigned short r1 = (instr >> 6) & 0x7;
                unsigned short pc_offset = sign_extend(instr & 0x3F,6);
                reg[r0] = mem_read(reg[r1] + pc_offset);
                update_flags(r0);
            }
                break;
            case OP_LEA:
            {
                unsigned short r0 = (instr >> 9) & 0x7;
                unsigned short pc_offset = sign_extend(instr & 0x1FF,9);
                reg[r0] = reg[R_PC] + pc_offset;
                update_flags(r0);
            }
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
            default:{
                abort();//bad operation code
            }
                break;
        }
    }
    //shutdown
}

unsigned short sign_extend(unsigned short x, int bit_count){
    if((x >> (bit_count - 1))&1){
        x |= (0xFFFF << bit_count);
    }
    return x;
}

void update_flags(unsigned short r){
    if(reg[r] == 0){
        reg[R_COND] = FL_ZRO;
    }
    else if(reg[r] > 15){
        reg[R_COND] = FL_NEG;
    }
    else{
        reg[R_COND] = FL_POS;
    }
}
