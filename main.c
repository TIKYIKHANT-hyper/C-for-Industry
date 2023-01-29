#include "tkklib.h"
#include <stdio.h>
int main(int argc,char *argv[]){
    char first[] = "   Hello from GCC     ";
    char second[50] = {"\0"};
    strip_t(first,second, strlen_t(first));
    printf("%sThis is after space",second);
    return 0;
}

