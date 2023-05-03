//
// Created by user on 5/3/23.
//
#include <stdio.h>

int main(){
    char name[20];
    int id;
    double balance;

    FILE *cfPtr;
    if((cfPtr = fopen("/home/user/C-for-Industry/clients.dat","w"))== NULL){
        printf("cannot open file\n");
    }
    else{
        printf("Enter the account,name and balance:\n");
        printf("Enter EOF to exit\n");
        scanf("%d%s%lf", &id, name, &balance);

        while(!feof(stdin)){
            fprintf(cfPtr,"%d %s %.2f\n",id,name,balance);
            scanf("%d%s%lf", &id, name, &balance);
        }
        fclose(cfPtr);
    }
    return 0;
}