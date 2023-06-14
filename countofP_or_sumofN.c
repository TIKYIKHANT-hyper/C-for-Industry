//
// Created by user on 6/14/23.
//
//[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15], you should return [10, -65].
#include <stdio.h>
int *counterandsummer(const int *arr,int *result,const int size);
int main(){
    int test[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15};
    int testsize = sizeof(test)/sizeof(test[0]);
    int res[2] = {0,0};
    counterandsummer(test,res,testsize);
    for(int i = 0; i < 2; i++){
        printf("%d ",res[i]);
    }
    return 0;
}

int *counterandsummer(const int *arr,int *result,const int size){
    int *arrptr = arr;
    int counter = 0;
    while(counter < size){
        if(*arrptr > 0){
            result[0] += 1;
        }
        if(*arrptr < 0){
            result[1] += *arrptr;
        }
        arrptr++;
        counter++;
    }
}