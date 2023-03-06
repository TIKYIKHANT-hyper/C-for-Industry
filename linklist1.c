#include <stdio.h>
#include "tkklib.h"
#include <stdlib.h>
#define MAX 20
struct node{
    int data;
    char specialkey[MAX];
    struct node *next;
};
typedef struct node *nodeptr;
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
int swap(nodeptr *sptr,int order){
    nodeptr *temptr = *sptr;
    (*sptr) = (*sptr)->next;
    (*sptr)->next = *temptr;
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

int delete(nodeptr *sptr,int res){
    if(res == ((*sptr)->data)){
        nodeptr temp = *sptr;
        *sptr = (*sptr)->next;//dethreading
        free(temp);
        return res;
    }
    else{
        nodeptr previousptr = *sptr;
        nodeptr currentptr = (*sptr)->next;

        while(currentptr != NULL && currentptr->data != res){
            previousptr = currentptr;
            currentptr = currentptr->next;
        }
        if(currentptr != NULL){
            nodeptr temptr = currentptr;
            previousptr->next = currentptr->next;
            free(temptr);
            return res;
        }
        return -1;//data for deleting not found
    }
}
int sortdata(nodeptr *sptr,int order){
    nodeptr previous = *sptr;
    nodeptr current = (*sptr)->next;
    if(isEmpty(*sptr)){
        return -1;//no data to sort
    }
    while(current != NULL && current->next != NULL){
        if(previous->data > current->data ){
            //swap(previous,current,current->next);
        }
    }
    return 0;
}
void insert(nodeptr *sptr,int data,char *key){

}
int main(int argc,char *argv[]){
    struct node* Node = NULL;
    appendnode(&Node,1,"Ok");
    appendnode(&Node,2,"Go");
    insertnode(&Node,3,"Shuttle");
    appendnode(&Node,4,"Lamp");
    printf("Linked Lists:\n");
    printlist(Node);
    swap(Node,1);
    printlist(Node);
    return 0;
}
//
// Created by Ti Kyi Khant on 3/5/2023.
//