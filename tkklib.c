//
// Created by Ti Kyi Khant on 1/20/2023.
//
#include <stdio.h>
#define INDEXES_MAX 100
typedef struct{
    int status;
    int indexes[INDEXES_MAX];
    int indexes_size;
} INDEXES;
int strlen_t(const char *s){
    int x = 0;
    for(; *s != '\0'; s++){
        x++;
    }
    return x;
}

int strcmp_t(const char *s1, const char *s2){
    if(strlen_t(s1) < strlen_t(s2)){
        //printf("first string is shorter than second string\n");
        return 1;
    }
    else if(strlen_t(s1) > strlen_t(s2)){
        //printf("first string is longer than second string\n");
        return 1;
    }
    else{
        for(;*s1 == *s2; s1++,s2++){
            if(*s1 == '\0' && *s2 == '\0'){
                return 0;
            }
        }
    }
    return 1;
}
/*
void strcon_t(const char *s1, const char *s2, char *target){
    int count = 0;
    for(; (target[count] = s1[count])!='\0';count++){
        ;
    }
    for(; (target[count] = *s2) != '\0';count++,s2++){
        ;
    }
}
*/

void strcon_t(char *s1,const char *s2){
    int count = 0;
    for(; *s1 != '\0'; s1++){
        count++;
    }
    //count++;
    for(; *s2 != '\0'; s2++,count++){
        s1[count] = *s2;
    }
}

void strcpy_t(const char *origin , char *target){
    for(;(*target = *origin) != '\0'; target++,origin++){

    }
}

int pow_t(const int base,int expo){
    int result = 1;
    if (expo == 1){
        return base;
    }
    else if (expo == 0){
        return 1;
    }
    else{
        while(expo > 0){
            result *= base;
            expo--;
        }
        return result;
    }
}

void decToBinConverter(const int num){
    int x = 1 << 7;
    int numcpy = num;

    for(int i = 0; i < 8; i++){
        if((i%4)==0){
            printf(" ");
        }
        if((x & numcpy)==0){
            printf("0");
            numcpy = numcpy<<1;
        }
        else{
            printf("1");
            numcpy = numcpy<<1;
        }
    }

}
int binarysearch(int *arr,int z){
    int arrlen_t(int *arrptr);
    int middleterm(int *arrptr);
    int start = 0;
    int end = arrlen_t(arr)-1;
    int middle = middleterm(arr);//start + (end - start)/2
    while(start <= end){
        if(z == arr[middle]){
            return middle;
        }
        else if(z > arr[middle]){
            start = middle + 1;
            middle = start + (end - start)/2;
        }
        else if(z < arr[middle]){
            end = middle - 1;
            middle = start + (end - start)/2;
        }
    }
    return -1;
}

int arrlen_t(int *arrptr){
    int i;
    for(i = 0; *arrptr != '\0';arrptr++){
        i++;
    }
    return i-1;
}

int middleterm(int *arrptr){
    int i = (arrlen_t(arrptr)/2)-1;
    return i;
}

void reverse(const char *const sPtr){
    if('\0' == sPtr[0]){
        return;
    }
    else{
        reverse(&sPtr[1]);
        putchar(sPtr[0]);
    }
}

int c2i(const char ch){
    if(ch >= 48 && ch <= 57){
        return ch - 48;
    }
    else {
        return -1;
    }
}



void strclear(char *str){
    for(;*str != '\0'; str++){
        *str = '\0';
    }
}

int s2i(char *str,int count){
    int res = 0;
    for(;*str != '\0' && count > 0; count--,str++ ){
        res += pow_t(10,count - 1) * c2i(*str);
    }
    return res;
}

int strchr_t(const char *str,const char ch,const int count){
    int i = 0;
    while(str[i] != '\0' && i < count){
        if(str[i] == ch){
            return i;
        }
        else{
            i++;
        }
    }
    return -1;
}

INDEXES find_allch(char *str,char ch,int count){
    INDEXES indexes;
    indexes.status = 0;
    int strcounter = 0;
    int fillcounter = 0;
    while(str[strcounter] != '\0' && strcounter < count){
        if(str[strcounter] == ch){
            indexes.indexes[fillcounter++] = strcounter;
            indexes.status = 1;
        }
            strcounter++;
    }
    indexes.indexes_size = fillcounter;
    return indexes;
}

void lstrip_t(const char *origin, char *target,const int count){
    int upperctr = 0;
    int innerctr = 0;
    while(origin[upperctr] == ' '){
        upperctr++;
    }
    for(; innerctr < count - upperctr; innerctr++){
        target[innerctr] = origin[upperctr+innerctr];
    }
}
void rstrip_t(const char *origin, char *target,const int count){
    int upperctr = strlen_t(origin) - 1;
    while(origin[upperctr] == ' '){
        upperctr--;
    }
    int innerctr;
    for(innerctr = 0; innerctr <= upperctr && innerctr < count; innerctr++){
        target[innerctr] = origin[innerctr];
    }
    target[innerctr] = '\0';
}

void strip_t(const char *origin, char *target,const int count){
    int lctr = 0;
    int rctr = strlen_t(origin) - 1;
    int innerctr;
    while(origin[lctr] == ' '){
        lctr++;
    }
    while(origin[rctr] == ' '){
        rctr--;
    }
    for(innerctr = 0; lctr <= rctr && innerctr < count; innerctr++,lctr++){
        target[innerctr] = origin[lctr];
    }
    for(;innerctr < strlen_t(target); innerctr++) {
        target[innerctr] = '\0';
    }
}

int strncmp_t(char *first,char *second,int firstlen,int secondlen,int startindex){
    if(secondlen > firstlen){
        return 1;
    }
    for(int i = 0; i < secondlen; i++){
        if(first[startindex+i] != second[i]){
            return 1;
        }
    }
    return 0;
}

INDEXES findAllstr_t(char *target,char *str){
    INDEXES result,data;
    int i;
    int si = 0;
    data.status=0;
    result = find_allch(target,str[0], strlen_t(target));
    if(result.status){
        for(i = 0; i < result.indexes_size; i++){
            int startindex = result.indexes[i];
            int status = strncmp_t(target,str, strlen_t(target), strlen_t(str),startindex);
            if(status==0){
                data.indexes[si++] = startindex;
                data.status = 1;
            }

        }
    }
    else{
        data.status = 0;
    }
    data.indexes_size = si;
    return data;
}

int strchrr_k(const char *str,const char ch,int count){
    int i = count - 1;
    while(str[i] != '\0'){
        if(str[i] == ch){
            return i;
        }
        else{
            i++;
        }
    }
}