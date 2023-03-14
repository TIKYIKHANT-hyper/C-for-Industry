//
// Created by Ti Kyi Khant on 3/14/2023.
//
#include <stdio.h>
#include <stdlib.h>

struct stacklist{
    int id;
    struct stacklist *next_stack;
};
typedef struct stacklist *stackptr;

stackptr createstack(int data){
    stackptr newptr = (stackptr) malloc(sizeof(struct stacklist));
    if(newptr == NULL){
        printf("Failed to create new node or out of memory\n");
        return NULL;
    }
    newptr->id = data;
    newptr->next_stack = NULL;
    return newptr;
}
int insert(stackptr *header, int data){
    if(*header == NULL){
        printf("Inserting into empty pointer\n");
        return -1;
    }
    stackptr newstack = createstack(data);
    newstack->next_stack = *header;
    *header = newstack;
    return 1;
}

int pop(stackptr *header){
    if(*header == NULL){
        printf("Poping empty pointer\n");
        return -1;
    }
    int tempdata = (*header)->id;
    stackptr popstack = *header;
    *header = (*header)->next_stack;
    free(popstack);
    return tempdata;
}

void printstack(stackptr header){
    if(header == NULL){
        printf("Empty Stack\n");
    }
    while(header != NULL){
        printf("{%d} -> ", header->id);
        header = header->next_stack;
    }
    printf("NULL\n");
}