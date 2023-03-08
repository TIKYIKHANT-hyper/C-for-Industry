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
    printlist(start);
    nodeptr res = find(start,"Piko");
    printf("%x",res);
    return 0;
}