#ifndef _ALOCARI_H
#define _ALOCARI_H

#define DIM 30
#include "mysource.h"
/*typedef struct {
  char *exe;
  char *makefile;
  char* (*pcharArray)(int);
  void (*pdeallocChar)(char *);
} MYSOURCE;
*/

char *charArray(int );
void deallocChar(char *);


#endif
