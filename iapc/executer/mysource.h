#ifndef _MYSOURCE_H
#define _MYSOURCE_H

typedef struct{
  char *exe;
  char *makefile;
  char* (*pcharArray)(int);
  void (*pdeallocChar)(char *);
  int (*pcompile)(char*);
  //int (*pcheckAllFiles)(MYSOURCE source, int (*)(char *, char *));
}MYSOURCE;

#endif
