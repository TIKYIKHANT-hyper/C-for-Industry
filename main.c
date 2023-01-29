#include "tkklib.h"
#include <stdio.h>
int main(int argc,char *argv[]){

    INDEXES mytest;
    char targetstr[] = "I am am amogus and sus am";
    mytest = findAllstr_t(targetstr,"am");
    for(int i = 0; i < mytest.indexes_size; i++){
        printf("%d \t",mytest.indexes[i]);
    }


    return 0;
}

