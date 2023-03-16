//
// Created by Ti Kyi Khant on 3/16/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct treenode{
    struct treenode * leftptr;
    int data;
    struct treenode * rightptr;
};

typedef struct treenode treeNode;
typedef treeNode * treeptr;
int insertNode(treeptr * base, int value);
void inOrder(treeptr baseptr);
int main() {
    treeptr root = NULL;
    srand(time(NULL));
    puts("The numbers generated:\n");
    for(int i = 0; i < 10; i++){
        int item = rand() % 15;
        insertNode(&root,item);
        printf(" %d ",item);
    }
    printf("InOrder going:\n");
    inOrder(root);
    return 0;
}

int insertNode(treeptr * base, int value){
    if(*base == NULL){
        *base = malloc(sizeof(treeNode));
        if(*base != NULL){
        (*base)->data = value;
        (*base)->leftptr = NULL;
        (*base)->rightptr = NULL;
        }else{
        printf("No value are inserted , insufficient memory\n");
        }
    }
    else{
        if(value < (*base)->data){
            insertNode(&((*base)->leftptr), value);
        }
        else if(value > (*base)->data){
            insertNode(&((*base)->rightptr),value);
        }
        else{
            printf("No duplicate values allowed;\n");
        }
    }
}

void inOrder(treeptr baseptr){
    if(baseptr != NULL){
        inOrder(baseptr->leftptr);
        printf(" %d " ,baseptr->data);
        inOrder(baseptr->rightptr);
    }
}