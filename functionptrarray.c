#include "tkklib.h"
#include <stdio.h>
int fun1(int x){
    return x + 2;
}
int fun2(int x){
    return x + 3;
}
int fun3(int x){
    return x + 4;
}
int main(int argc,char *argv[]){

    int (*funptrarr[])(int) = {fun1, fun2,fun3};
    printf("Enter:");
    int select,res;
    scanf("%d",&select);
    res = (*funptrarr[select])(select);
    printf("%d",res);
    return 0;
}

//
// Created by Ti Kyi Khant on 2/1/2023.
//
