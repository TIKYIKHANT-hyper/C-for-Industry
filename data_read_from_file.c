//
// Created by user on 5/3/23.
//
#include <stdio.h>

int main(){
    FILE *fptr;
    int id;
    double balence;
    char name[20];
    if((fptr = fopen("/home/user/C-for-Industry/clients.dat","r"))== NULL){
        printf("Error opening file\n");
    }
    else{
        printf("%-10s %-13s %s","ID","Name","Balence\n");
        fscanf(fptr,"%d%s%lf",&id, name, &balence);
        while(!feof(fptr)){
            printf("%-10d%-13s%7.2f\n",id,name,balence);
            fscanf(fptr,"%d%s%lf", &id, name, &balence);
        }
        fclose(fptr);
    }
    return 0;
}