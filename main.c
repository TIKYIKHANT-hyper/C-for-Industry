#include <stdio.h>
#include "master_tlib.h"


int main(){
   char first[] = "Hello";
   char second[] = " World";
   char final[12];
   strcpy_t(first,final);
   printf("%s", final);
    return 0;
}

