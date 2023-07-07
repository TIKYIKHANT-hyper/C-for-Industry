#include <stdio.h>
void displaybits(const int num);
int main(){
    int num = 12;
    displaybits(num);
    printf("\n");
    return 0;
}

void displaybits(const int num){
    int cpy = num;
    int mask = 1<<30;
    for(int i = 1; i <= 31; i++){
        if(cpy & mask){
            printf("%c",'1');
        }
        else{
            printf("%c",'0');
        }
        mask>>=1;
    }
}

