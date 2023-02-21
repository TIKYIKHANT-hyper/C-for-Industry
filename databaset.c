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

int binarytotext(FILE *fin,char *fout,struct studentdata stdinfo);
int dummydatafiller(FILE *fptr, char *name, int age, struct studentdata stdinfo , int count);
int printrecord(FILE *fptr, int index, struct studentdata stdinfo);
int main(){
    FILE *fptr = NULL;
    fopen_s(&fptr,"D:\\CodeWithCLion\\outest.dat","wb+");
    struct studentdata datatest = {0,"",0};
    dummydatafiller(fptr,"Hello",12,datatest,5);
    binarytotext(fptr,"D:\\CodeWithCLion\\outest.txt",datatest);
    printrecord(fptr,3,datatest);
    fclose(fptr);
    return 0;
}

int binarytotext(FILE *fin,char *fout,struct studentdata stdinfo){
    FILE *fileout = NULL;
    fopen_s(&fileout,fout,"w+");
    int record = 1;
    if(fileout == NULL){
        printf("No output file or such directory!\n");
        return -1;
    }
    if(fin == NULL){
        printf("No input file or such directory!\n");
        return -1;
    }
    rewind(fin);
    while(!feof(fin)){
        stdinfo.id = 0;
        stdinfo.age = 0;
        strcpy_t("",stdinfo.name);
        fseek(fin,sizeof(struct studentdata)*(record - 1),SEEK_SET);
        fread(&stdinfo,sizeof(struct studentdata),1,fin);
        if(stdinfo.id != 0){
        if(record != 1){
            fprintf(fileout,"\n");
        }
        fprintf(fileout,"id = %-5d name = %-10s age = %-5d",stdinfo.id,stdinfo.name,stdinfo.age);
    }
    record++;
    }
    fclose(fileout);
    return 0;
}

int dummydatafiller(FILE *fptr, char *name, int age, struct studentdata stdinfo , int count){
    if(fptr == NULL){
      printf("No such input file or directory");
      return -1;
    }
    rewind(fptr);
    int record = 1;
    while(record <= count){
        strcpy_t(name,stdinfo.name);
        stdinfo.id = record;
        stdinfo.age = age;
        fseek(fptr,(record - 1) * sizeof(struct studentdata),SEEK_SET);
        fwrite(&stdinfo,sizeof(struct studentdata),1,fptr);
        record++;
    }
    return 0;
}

int printrecord(FILE *fptr, int index, struct studentdata stdinfo){
    if(fptr == NULL){
        printf("No such input file or directory");
        return -1;
    }
    rewind(fptr);
    int record = 1;
    while(record <= index){
        strcpy_t("",stdinfo.name);
        stdinfo.id = 0;
        stdinfo.age = 0;
        fseek(fptr,(record - 1)*sizeof(struct studentdata),SEEK_SET);
        fread(&stdinfo,sizeof(struct studentdata),1,fptr);
        printf("ID = %-2d name = %-20s age = %-2d\n",stdinfo.id,stdinfo.name,stdinfo.age);
        record++;
    }
    return 0;
}