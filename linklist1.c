#include <stdio.h>
#include "tkklib.h"
#include <stdlib.h>
#define MAX 20
struct node{
    int data;
    char specialkey[MAX];
    struct node *next;
};

struct node *createnewnode(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertnode(struct node **nodeheader,int data){
    struct node *newnode = createnewnode(data);
    newnode->next = *nodeheader;
    *nodeheader = newnode;
}

void printlist(struct node *header){
    while(header != NULL){
        printf("%d\n",header->data);
        header = header->next;
    }
    printf("\n");
}
int isEmpty(struct node *head){
    return head == NULL;
}
int main(int argc,char *argv[]){
    struct node* Node = NULL;
    insertnode(&Node,1);
    insertnode(&Node,2);
    insertnode(&Node,3);
    insertnode(&Node,4);
    printf("Linked Lists:\n");
    printlist(Node);
    return 0;
}//
// Created by Ti Kyi Khant on 3/5/2023.
//
