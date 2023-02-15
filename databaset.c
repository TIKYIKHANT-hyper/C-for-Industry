//
// Created by Ti Kyi Khant on 2/15/2023.
//
#include <stdio.h>
#include "tkklib.h"
#define MAX 30
struct studentdata{
    int id;
    char name[MAX];
    int age;
};
int main(){
    FILE *fin = NULL;
    fopen_s(&fin,"D:\\CodeWithCLion\\studentdata.dat","wb+");
    struct studentdata student;
    rewind(fin);
    for(int i = 1; i <= 6; i++){
        student.id = i;
        student.age = i * 10;
        strcpy_t("khant",student.name);
        fseek(fin,(i - 1) * sizeof(struct studentdata),SEEK_SET);
        fwrite(&student,sizeof(struct studentdata),1,fin);
    }
    fclose(fin);
    return 0;
}