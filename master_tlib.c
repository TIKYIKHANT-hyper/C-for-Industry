#include <stdio.h>

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

void strcon_t(const char *s1, const char *s2, char *target){
    
    int count = 0;
    for(; (target[count] = s1[count])!='\0';count++){
        ;
    }
    for(; (target[count] = *s2) != '\0';count++,s2++){
        ;
    }
    
    
}

void strcpy_t(const char *origin , char *target){
    
        for(;(*target = *origin) != '\0'; target++,origin++){
        ;
        }
    
}