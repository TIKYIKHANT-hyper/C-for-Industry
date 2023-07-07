#include <stdio.h>
void draw(int height);
int main(){
    draw(12);
    return 0;
}

void draw(int height){
    int k = 0;
    for(int i = 0;i < height;i++){
        printf("|");
        if(i != height - 1){
        for(int j = 0;j < k; j++){
            printf(" ");
        }
        }
        if(i == height - 1){
            for(int z = 0; z < k;z++){
                printf("_");
            }
            printf("\\\n");
        }
        else{
        printf("\\\n");
        }
        k+=1;
    }
}
