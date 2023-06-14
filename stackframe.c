//
// Created by user on 6/14/23.
//
#include <stdio.h>
int square(int x);

int main(){
    int num = 10;
    int newnum = square(num);
    printf("%d",newnum);
}

int square(int x){
    return x * x;
}