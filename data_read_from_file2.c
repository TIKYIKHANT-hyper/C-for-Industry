//
// Created by user on 5/3/23.
//
#include <stdio.h>

int main(){
    FILE *fptr;
    int id;
    double balence;
    char name[20];
    int option = 0;
    if((fptr = fopen("/home/user/C-for-Industry/clients.dat","r"))== NULL){
        printf("Error opening file\n");
    }
    else{
        printf("%s",
               "check point\n"
               "1-Display balence zero accounts\n"
               "2-Display credit accounts\n"
               "3-Display debit accounts\n"
               "4-End Process?\n");
        scanf("%d",&option);
        while( option != 4){
            fscanf(fptr, "%d%s%lf", &id, name, &balence);
            switch(option){
                case 1:
                    printf("%-10s %-13s %s\n", "ID", "Name", "Balence");
                    while(!feof(fptr)) {
                        if(balence == 0) {
                            printf("%-10d %-13s %lf\n", id, name, balence);
                        }
                        fscanf(fptr, "%d%s%lf", &id, name, &balence);
                    }
                    break;
                case 2:
                    printf("%-10s %-13s %s\n", "ID", "Name", "Balence");
                    while(!feof(fptr)) {
                        if(balence < 0) {
                            printf("%-10d %-13s %lf\n", id, name, balence);
                        }
                        fscanf(fptr, "%d%s%lf", &id, name, &balence);
                    }
                    break;
                case 3:
                    printf("%-10s %-13s %s\n", "ID", "Name", "Balence");
                    while(!feof(fptr)) {
                        if(balence > 0) {
                            printf("%-10d %-13s %lf\n", id, name, balence);
                        }
                        fscanf(fptr, "%d%s%lf", &id, name, &balence);
                    }
                    break;
            }
            rewind(fptr);
            printf("?\n");
            scanf("%d",&option);
        }
        printf("end of run");
        fclose(fptr);
    }
    return 0;
}