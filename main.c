#include <stdio.h>
int get_sum(int a , int b) {
    if(a == b){
        return a;
    }
    int start,end;
    int result = 0;
    if(a < b){
        start = a;
        end = b;
    }
    else{
        start = b;
        end = a;
    }
    int range = end - start;
    for(int i = start; i <= end; i++){
        result += i;
    }
    return result;
    // Good luck
}
int main(){
    int x = get_sum(505,4);
    printf("%d",x);
}