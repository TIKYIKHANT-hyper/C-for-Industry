#include <stdio.h>
<<<<<<< HEAD
#include "master_tlib.h"


int main(){
   int x = 12;
   
   decToBinConverter(x);
   
    return 0;
}

=======
#include "tkklib.h"
int main(int argc,char *argv[]){
    char test[] = "321";
    /*char *ptr = test;
    int z = 0;
    int count = 3;
    for(; *ptr != '\0'; ptr++,count--){
        printf("%d", c2i(*ptr));
        z += pow_t(10, count -1) * c2i(*ptr);
    }
    printf("%d",z);
     */
    int x = s2i(test,3);
    printf("%d",x);
    return 0;
}
>>>>>>> 4773003 (Library Update)
