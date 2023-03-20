#include <stdio.h>
#include "tkklib.h"
#include <stdlib.h>
struct mydata{
    int idone;
    int idtwo;
    struct {
        int innerone;
        int innertwo;
    };
};

int main(int argc,char *argv[]){
    struct mydata ourdata;
    ourdata.idone = 1;
    ourdata.idtwo = 2;
    ourdata.innerone = 3;
    ourdata.innertwo = 4;
    printf("%d",ourdata.idone);
    printf("%d",ourdata.idtwo);
    printf("%d",ourdata.innerone);
    printf("%d",ourdata.innertwo);
    return 0;
}