#include <stdio.h>
#include "tkklib.h"
#define MAX 50
struct student{
    int id;
    int age;
    char name[MAX];
};
int main(int argc,char **argv){
    struct student mgmg = {1,16,"MgMg"};
    FILE *fout = NULL;
    fopen_s(&fout,"D:\\CodeWithCLion\\studentdata.dat","wb+");
    if(fout == NULL){
        return 1;
    }
    fseek(fout,(mgmg.id - 1)* sizeof(struct student),SEEK_SET);
    fwrite(&mgmg,sizeof (struct student),1,fout);
    return 0;
}