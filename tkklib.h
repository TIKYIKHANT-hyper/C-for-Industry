//
// Created by Ti Kyi Khant on 1/20/2023.
//

#include "tkklib.c"
int arrlen_t(int *arrptr);
int middleterm(int *arrptr);
int strlen_t(const char *s);
int strcmp_t(const char *s1, const char *s2);// return 0 if the two string are the same else 1 is returned
void strcon_t(char *s1,const char *s2);
void strcpy_t(const char *origin , char *target);
int pow_t(const int base,int expo);
void decToBinConverter(const int num);
int binarysearch(int *arr,int z);
int arrlen_t(int *arrptr);
int middleterm(int *arrptr);
void reverse(const char *const sPtr);
int c2i(const char ch);
void strclear(char *str);
int s2i(char *str,int count);
int strchr_t(const char *str,const char ch,const int count);
INDEXES find_allch(char *str,char ch,int count);//returns status 1 on success
void lstrip_t(const char *origin,char *target,const int count);
void rstrip_t(const char *origin, char *target,const int count);
void strip_t(const char *origin, char *target,const int count);
int strncmp_t(char *first,char *second,int firstlen,int secondlen,int startindex);//returns 0 on success , 1 on failure
INDEXES findAllstr_t(char *target,char *str);//returns status 1 on success
int strchrr_t(const char *str,const char ch,int count);
int isdigit_t(const int ch);//returns original value on success, -1 on failure
int isalpha_t(const int ch);//returns 0 on success, -1 on failure
char i2c(const int ch);//returns character on success, -1 on failure
int intarrlen(const int *arrptr);