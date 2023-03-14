//
// Created by Ti Kyi Khant on 3/14/2023.
//

#ifndef CODEWITHCLION_STACKLIB_H
#define CODEWITHCLION_STACKLIB_H
#include "stacklib.c"
stackptr createstack(int data);
int insert(stackptr *header, int data);
void printstack(stackptr header);
int pop(stackptr *header);
#endif //CODEWITHCLION_STACKLIB_H
