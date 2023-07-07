#include <stdio.h>

void draw(int length);

int main(){
    draw(12);
    return 0;
}

void draw(int length){
    for(int i = 0; i < length/2; i++){
       if(i==0){
           for(int j = 0; j < length; j++){
               if(j == 0){
                   printf(" ");
               }
           printf("_");
           }
           printf("\n");
       }
       else if (i == (length/2) -1){
           printf("|");
           for(int k = 0; k < length; k++){
              printf("_");
           }
           printf("|");
       }
       else{
           printf("|");
           for(int l = 0; l < length; l++){
               printf(" ");
           }
           printf("|\n");
       } 
    }
}
