//
// Created by Ti Kyi Khant on 3/6/2023.
//
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

void insert(nodeptr *sptr, int data, char keytoken[MAX]){
    nodeptr newptr = createnewnode(data,keytoken);
    if(newptr != NULL){
        nodeptr previousptr = NULL;//start pointer
        nodeptr currentptr = *sptr;

        while(currentptr != NULL && currentptr->next != NULL){
            previousptr = currentptr;
            currentptr = currentptr->next;
        }
        if(previousptr == NULL){
            newptr->next = *sptr;
            *sptr = newptr;
        } else{
            previousptr->next = newptr;
            newptr->next = currentptr;
        }
    }
}

int length(nodeptr start){
    int count = 0;
    if(start == NULL){
        return 0;
    }
    while(start != NULL){
        count++;
        start = start->next;
    }
    return count;
}

nodeptr find(nodeptr start, const char *key){
    if(start == NULL){
        return NULL;
    }
    while(start != NULL){
        if(strcmp_t(start->specialkey,key)==1){
            return start;
        }
        else{
            start = start->next;
        }
    }
    return NULL;
}

int deletefirst(nodeptr *target){
    if(*target == NULL){
        printf("Error cannot delete empty structure");
        return -1;
    }
    else{
        nodeptr currentptr = *target;
        if((*target)->next == NULL){
            *target = NULL;
            free(currentptr);
            return 1;
        }
        else{
            *target = currentptr->next;
            free(currentptr);
            return 1;
        }
    }
}