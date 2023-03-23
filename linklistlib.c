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
int size(nodeptr head){
    int i = 0;
    while(head != NULL){
        i++;
        head = head->next;
    }
    return i;
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
nodeptr nodeatIndex(nodeptr head,int index){
    int count = 0;
    if(index >= size(head)){
        printf("Index out of Array\n");
        return NULL;
    }
    while(head != NULL && count < index){
        count++;
        head = head->next;
    }
    return head;
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

int delete_end(nodeptr *target){
    if(*target == NULL){
        printf("Error on deleting empty structure\n");
        return -1;
    }
    else{
        nodeptr currentptr = (*target)->next;
        nodeptr previousptr = *target;
        while(currentptr->next != NULL){
            previousptr = currentptr;
            currentptr = currentptr->next;
        }
        previousptr->next = NULL;
        free(currentptr);
        return 1;
    }
}

int delete_fun(nodeptr *target,const int id, const char *key){
    if(*target == NULL){
        printf("Error on deleting empty structure\n");
        return -1;
    }
    else{
        nodeptr previousptr = *target;
        nodeptr currentptr = (*target)->next;
        if(previousptr->data == id && strcmp_t(previousptr->specialkey,key)== 1){
            *target = currentptr;
            previousptr->next = NULL;
            free(previousptr);
            return 1;//found at first sight and deleted
        }
        while(currentptr != NULL){
            if(currentptr->data == id)
            {
                if(strcmp_t(currentptr->specialkey,key)==1) {
                    previousptr->next = currentptr->next;
                    currentptr->next = NULL;
                    free(currentptr);
                    return 1;//success deleting
                }
            }
            else{
                previousptr = currentptr;
                currentptr = currentptr->next;
            }
        }
    }
    printf("error deleting\n");
    return -1;
}
nodeptr merge(nodeptr a,nodeptr b) {
    nodeptr left = a;
    nodeptr right = b;
    nodeptr current = createnewnode(0,"empty");
    while(left || right){
    if (left == NULL) {
        appendnode(&current,right->data,right->specialkey);
        right = right->next;
    } else if (right == NULL) {
        appendnode(&current,left->data,left->specialkey);
        left = left->next;
    }
    else{
        if(left->data < right->data){
            appendnode(&current,left->data,left->specialkey);
            left = left->next;
        }
        else{
            appendnode(&current,right->data,right->specialkey);
            right = right->next;
        }
    }
}
    nodeptr temphead = current;//for deleting
    current  = current->next;
    free(temphead);
    return current;
}
nodeptr mergeSort(nodeptr start){
    if(start->next == NULL || (start) == NULL){
        return start;
    }
    int middleindex = size(start) / 2;
    nodeptr midnode = nodeatIndex(start,middleindex - 1);
    nodeptr leftnode = start;
    nodeptr rightnode = midnode->next;
    midnode->next = NULL;
    nodeptr righthand = mergeSort(rightnode);
    nodeptr lefthand = mergeSort(leftnode);
    return merge(lefthand,righthand);
}
