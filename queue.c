//
// Created by Ti Kyi Khant on 3/14/2023.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct queuedata{
    int key;
}queueDATA;

typedef struct queueNode{
    int id;
    queueDATA data;
    struct queueNode *next_node;
}queueNODE;

typedef queueNODE * queuePtr;
int isEmpty(queuePtr head);
void printQueue(queuePtr head);
int enqueue(queuePtr * head, queuePtr * tail, int data);
int deque(queuePtr *head, queuePtr *tail);
int main(){
    queuePtr head = NULL;
    queuePtr tail = NULL;
    enqueue(&head,&tail,1);
    enqueue(&head,&tail,2);
    enqueue(&head,&tail,3);
    enqueue(&head,&tail,4);
    printQueue(head);
    deque(&head,&tail);
    printQueue(head);
}

int enqueue(queuePtr *head, queuePtr * tail, int data){
    queuePtr newnode = (queuePtr)malloc(sizeof(queueNODE));
    if(newnode != NULL){
        newnode->id = data;
        newnode->data.key = data * 10;
        newnode->next_node = NULL;
        if(isEmpty(*head)){
            *head = newnode;
        }
        else{
            (*tail)->next_node = newnode;
        }
        *tail = newnode;
        return 1;
    }
    else{
        printf("node is not inserted no memory available\n");
        return 0;
    }
}

int isEmpty(queuePtr head){
    return head == NULL;
}

void printQueue(queuePtr head){
    queuePtr current = head;
    if(current == NULL){
        printf("Queue is empty\n");
    }
    while(current != NULL){
        printf("{%d}.%d->",current->id,current->data.key);
        current = current->next_node;
    }
    printf("NULL\n");
}

int deque(queuePtr *head, queuePtr *tail){
    int value = (*head)->id;
    int subdata = (*head)->data.key;
    queuePtr temptr = *head;
    *head = (*head)->next_node;
    if(*head == NULL){
        *tail = NULL;
    }
    free(temptr);
    return value,subdata;
}