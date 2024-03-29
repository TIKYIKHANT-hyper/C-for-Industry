//
// Created by bluephoenix on 2/11/2023.
//
#include <stdio.h>
#include <string.h>
struct STUDENT {
    char name[20];
    int age;
    int student_id;
};

int propagateEmptyData(FILE* fptr,struct STUDENT student_data,int count);
int read4Print(FILE* fptr,struct STUDENT student_data);
int bin2TextFile(FILE* fi,char *oFname,struct STUDENT student_data);

int main(){
    int record =0 ;
    struct STUDENT student_data = {"",0,0};
    FILE *fptr = NULL;
    char fname[]="d:\\data.dat";
    fopen_s(&fptr,fname,"wb+");
    if(fptr==NULL)
    {
        return 1;
    }

    propagateEmptyData(fptr,student_data,5);
    //read4Print(fptr,student_data);
    bin2TextFile(fptr,"d:\\out.txt",student_data);

    fclose(fptr);
    return 0;
}

int propagateEmptyData(FILE* fptr,struct STUDENT student_data,int count)
{
    if(fptr==NULL)
    {
        printf("propagate error! no such file \n");
        return 1;
    }
    //writing 100 empty records into file
    rewind(fptr);
    for(int record=1;record<=count;record++)
    {
        student_data.student_id = record;
        strcpy(student_data.name,"aung");
        student_data.age = record *10;
        fseek(fptr,(record-1)*sizeof(struct STUDENT),SEEK_SET);
        fwrite(&student_data,sizeof(struct STUDENT),1,fptr);
    }
    return 0;
}

int read4Print(FILE* fptr,struct STUDENT student_data)
{
    if(fptr==NULL)
    {
        printf("read error! no such file \n");
        return 1;
    }
    int record =1;
    rewind(fptr);
    while(!feof(fptr))
    {
        student_data.student_id = 0;
        strcpy(student_data.name,"");
        student_data.age = 0;
        fseek(fptr,(record-1)*sizeof(struct STUDENT),SEEK_SET);
        fread(&student_data,sizeof(struct STUDENT),1,fptr);
        if(student_data.student_id!=0)
        {
            printf("id=%-6dname=%-10sage=%6d \n",student_data.student_id,student_data.name,student_data.age);
        }

        record++;
    }
    return 0;
}

int bin2TextFile(FILE *fi,char *oFname,struct STUDENT student_data)
{
    FILE * fo = NULL;
    fopen_s(&fo,oFname,"w+");    //text file output
    if(fi==NULL)
    {
        printf("read error! no such input file \n");
        return 1;
    }
    if(fo==NULL)
    {
        printf("read error! no such output file \n");
        return 1;
    }

    int record =1;
    rewind(fi);
    while(!feof(fi))
    {
        student_data.student_id = 0;
        strcpy(student_data.name,"");
        student_data.age = 0;
        fseek(fi,(record-1)*sizeof(struct STUDENT),SEEK_SET);
        fread(&student_data,sizeof(struct STUDENT),1,fi);
        if(student_data.student_id!=0)
        {
            if(record!=1)
            {
                fprintf(fo,"\n");
            }
            printf("id=%-6dname=%-10sage=%6d \n",student_data.student_id,student_data.name,student_data.age);
            fprintf(fo,"id=%-6dname=%-10sage=%6d",student_data.student_id,student_data.name,student_data.age);
        }

        record++;
    }

    fclose(fo);
    return 0;
}