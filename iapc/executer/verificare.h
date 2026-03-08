#ifndef _VERIFICARE_H
#define _VERIFICARE_H

#define NR_FILES 10
#include "alocari.h"
int checkOneFile(char *, char *);

int checkAllFiles(MYSOURCE source,int (*)(char *,char*));

#endif
