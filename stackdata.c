//
// Created by Ti Kyi Khant on 3/14/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "stacklib.h"
int main(){
    stackptr newptr = createstack(1);
    insert(&newptr,2);
    insert(&newptr,3);
    printstack(newptr);
    pop(&newptr);
    printstack(newptr);
}