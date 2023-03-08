//
// Created by Ti Kyi Khant on 3/6/2023.
//

#ifndef CODEWITHCLION_LINKLISTLIB_H
#define CODEWITHCLION_LINKLISTLIB_H
#include "linklistlib.c"
void insert(nodeptr *sptr, int data, char keytoken[MAX]);
void printlist(struct node *header);
int delete(nodeptr *sptr,int res);
int length(nodeptr start);
void appendnode(struct node **header,int data,char spkey[MAX]);
struct node *createnewnode(int data,char *key);
nodeptr find(nodeptr start, const char *key);
int deletefirst(nodeptr *target);
int delete_end(nodeptr *target);
int delete_fun(nodeptr *target,const int id, const char *key);
#endif //CODEWITHCLION_LINKLISTLIB_H
