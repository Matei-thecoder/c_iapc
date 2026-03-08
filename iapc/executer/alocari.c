#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *charArray(int n)
{
  char *c =0;
  c = (char *)malloc(n*sizeof(char));
  if(c==NULL)
  {
    fprintf(stderr,"Alocare esuata\n");
    exit(EXIT_FAILURE);
  }
  return c;
}

void deallocChar(char *c)
{
  memset(c,0,strlen(c)*sizeof(char));
  free(c);
}
