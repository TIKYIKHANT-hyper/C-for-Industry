//
// Created by Ti Kyi Khant on 3/14/2023.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct queuedata{
    int id;
}queueDATA;

typedef struct queueNode{
    queueDATA idData;
    struct queueNode *next_node;
}queueNODE;
typedef queueNODE * queuePtr;
int isEmpty(queuePtr head);
void printQueue(queuePtr head);
int enqueue(queuePtr * head, queuePtr * tail, int data);
int main(){
    queuePtr head = NULL;
    queuePtr tail = NULL;
    enqueue(head,tail,1);
    enqueue(head,tail,2);
}

int enqueue(queuePtr * head, queuePtr * tail, int data){
    queuePtr newnode = (queuePtr) malloc(sizeof(queueNODE));
    if(newnode != NULL){
        newnode->idData;
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
        printf("{%d}->",current->idData);
        current = current->next_node;
    }
}