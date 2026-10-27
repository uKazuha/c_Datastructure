#ifndef MYSTR_H_
#define MYSTR_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int Index;

Index locateSubstr(const char *s,const char *sub);

void get_next(const char *string,int len,int *next);
void get_nextval(const char *string,int len,int *next);
int KMP(const char *S,const char *T);



#endif