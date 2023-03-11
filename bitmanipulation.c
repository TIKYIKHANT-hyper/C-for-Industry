//
// Created by Ti Kyi Khant on 3/11/2023.
//
#include <stdio.h>
void displayBits(int num);
int main(){
    int mask =1;
    printf("Bit Manipulation!");
    int portb =2290665608;
    printf("\n");
    printf("portb register\n");
    displayBits(portb);
    for(int k=1;k<32;k++)
    {
        printf("\n");
        mask<<=1;
        mask |= 1;
        printf("mask\n");
        displayBits(mask);
    }



    portb ^= mask;
    printf("portb xor mask \n");
    displayBits(portb);
    return 0;
}


void displayBits(int num)
{
    int mask = 1<<31;
    for(int i=1;i<=32;i++)
    {
        putchar(num & mask ? '1':'0');
        num<<=1;
        if(i%4==0)
        {
            printf(" ");
        }
    }
    printf("\n\n");
}