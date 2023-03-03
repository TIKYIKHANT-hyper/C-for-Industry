#include <stdio.h>
#include "tkklib.h"
#include <stdlib.h>
struct datanode{
    int id;
    char keygen[20];
    struct datanode * nextptr;
};
typedef struct datanode DataNode;
typedef DataNode * nodeptr;
int main(){
    
    return 0;
}

void instructions(){
    system("cls");
    printf("1-insert data\n");
    printf("0-exit\n");
}

void insert(nodeptr * startptr, char value){
    nodeptr newptr = malloc(sizeof(DataNode));
    if(newptr != NULL){
        newptr->id = value;
        newptr->nextptr = NULL;

        nodeptr previousptr = NULL;
        nodeptr currentptr = *startptr;
        while(currentptr != NULL && value > currentptr->id){
            previousptr = currentptr;
            currentptr = currentptr->nextptr;
        }
    }

}