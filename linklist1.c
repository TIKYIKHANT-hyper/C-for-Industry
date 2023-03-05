#include <stdio.h>
#include "tkklib.h"
#include <stdlib.h>
#define MAX 20
struct node{
    int data;
    char specialkey[MAX];
    struct node *next;
};

struct node *createnewnode(int data,char *key){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    strcpy_t(key,newnode->specialkey);
    return newnode;
}

void insertnode(struct node **nodeheader,int data,char spkey[MAX]){
    struct node *newnode = createnewnode(data,spkey);
    newnode->next = *nodeheader;
    *nodeheader = newnode;
}

void printlist(struct node *header){
    while(header != NULL){
        printf("%d\n",header->data);
        printf("%s\n",header->specialkey);
        header = header->next;
    }
    printf("\n");
}
int isEmpty(struct node *head){
    return head == NULL;
}

void appendnode(struct node **header,int data,char spkey[MAX]){
    struct node *newptr = createnewnode(data,spkey);
    if(newptr != NULL){
        struct node *previousptr = NULL;//assume as start of the list
        struct node *currentptr = *header;//argument pointer is assume as current pointer for start
        while(currentptr != NULL && currentptr->next != NULL){
            previousptr = currentptr;
            currentptr = currentptr->next;
        }
        if(currentptr == NULL){
            *header = newptr;
        }else{
            currentptr->next = newptr;
        }
    }
    else{
        printf("Error appending new nodes");
    }
}
int main(int argc,char *argv[]){
    struct node* Node = NULL;
    appendnode(&Node,1,"Ok");
    appendnode(&Node,2,"Go");
    insertnode(&Node,3,"Shuttle");
    printf("Linked Lists:\n");
    printlist(Node);
    return 0;
}//
// Created by Ti Kyi Khant on 3/5/2023.
//
