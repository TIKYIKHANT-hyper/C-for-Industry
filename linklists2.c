//
// Created by Ti Kyi Khant on 3/6/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "linklistlib.h"
#define MAX 20
struct nodedata{
    int data;
    char specialkey[MAX];
};
int main(){
    nodeptr *start = NULL;
    insertnode(&start,1,"Demo");
    insert(&start,2,"Piko");
    insert(&start,3,"Nano");
    insert(&start,4,"Micro");
    printlist(start);
    nodeptr newnode = mergeSort(start);
    printlist(newnode);
    return 0;
}