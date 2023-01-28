#include "tkklib.h"
#include <stdio.h>
int main(int argc,char *argv[]){
    INDEXES result;
    char test[100] = "Hello*Ti*Kyi*Khant";
    result = find_allch(test,'*', strlen_t(test));
    if(result.status){
    for(int i = 0; i < result.indexes_size; i++){
        printf(" %d ",result.indexes[i]);
    }
    }
    return 0;
}

