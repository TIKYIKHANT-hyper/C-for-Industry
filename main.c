#include <stdio.h>
void staticArrayInit(void);
void automaticArrayInit(void);
int main(){
    puts("first call to each function");
    staticArrayInit();
    automaticArrayInit();
    puts("\n\nSecond call to each function");
    staticArrayInit();
    automaticArrayInit();
    puts("");
}

void staticArrayInit(void){
    static int array1[3];
    puts("\nValues on entering to staticArrayInit:");
    for(size_t i = 0; i <= 2; ++i){
        printf("array1[%zu] = %d", i , array1[i]);
    }
    puts("\nValues on exiting staticArrayInit:");
    for(size_t i = 0; i <= 2; ++i){
        printf("array1[%zu] = %d ",i , array1[i] += 5);
    }
}

void automaticArrayInit(void){
    int array2[3] = {1,2,3};
    puts("\n\nValues on entering automaticArrayInit:");
    for(size_t i = 0; i <= 2; ++i){
        printf("array2[%zu] = %d ",i,array2[i]);
    }
    puts("\nValues on exiting automaticArrayInit:");
    for(size_t i = 0; i <= 2; ++i){
        printf("array2[%zu] = %d ",i,array2[i] += 5);
    }
}