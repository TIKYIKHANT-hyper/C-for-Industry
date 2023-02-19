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
int spreadertoempty(FILE *fileptr,struct studentdata informer,int count);
int binarytotext(FILE *fin,char *fout,struct studentdata stdinfo);
int main(){
    FILE *fptr = NULL;
    fopen_s(&fptr,"D:\\CodeWithCLion\\outest.dat","wb+");
    struct studentdata datatest = {0,"",0};
    spreadertoempty(fptr,datatest,5);
    binarytotext(fptr,"D:\\CodeWithCLion\\outest.txt",datatest);
    fclose(fptr);
    return 0;
}

int spreadertoempty(FILE *fileptr,struct studentdata infomer,int count){
    if(fileptr == NULL){
        printf("No file or such directory \n");
        return -1;
    }
    rewind(fileptr);
    int record = 1;
    while(record <= count){
        infomer.id = record;
        strcpy_t("Kyaw Kyaw",infomer.name);
        infomer.age = record * 5;
        fseek(fileptr,(record-1)*sizeof(struct studentdata),SEEK_SET);
        fwrite(&infomer,sizeof(struct studentdata),1,fileptr);
        record++;
    }
    return 0;//success
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