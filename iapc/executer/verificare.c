#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "verificare.h"
#include "executare.h"
#include "alocari.h"
#include "mysource.h"
int checkOneFile(char *source, char *tocheck)
{
  FILE *sourceFile =0;
  FILE *tocheckFile =0;
  char a,b;
  sourceFile = fopen(source,"r");
  if(sourceFile ==NULL)
  {
    fprintf(stderr,"Eroare la deschidere fisier %s\n",source);
    exit(EXIT_FAILURE);
  }

  tocheckFile = fopen(tocheck,"r");
  if(tocheckFile==NULL)
  {
    fprintf(stderr,"Eroare la deschidere fisier %s\n",tocheck);
    exit(EXIT_FAILURE);
  }
  while((a=getc(sourceFile))!=EOF && (b=getc(tocheckFile))!=EOF)
  {
    if(a!=b)
    {
      return 0;
    }
  }
  if(sourceFile!=0)
  {
    fclose(sourceFile);
    sourceFile =0;
  }
  if(tocheckFile!=0)
  {
    fclose(tocheckFile);
    tocheckFile = 0;
  }
  return 1;

}

int checkAllFiles(MYSOURCE source,int (*p)(char *,char *))
{
  int i,sum=0;
  char tocheck[256];
  char input[256];


  for(i=0;i<NR_FILES;i++)
  {
    sprintf(input,"../%s/inputs/input_%d.txt",source.exe,i);
    sprintf(tocheck,"../%s/solutions/sol_%d.txt",source.exe,i);
    if(!run(source.exe,input,"res.txt"))
    {
      exit(EXIT_FAILURE);
    }

    p = &checkOneFile;
    sum+=p("../problem_folder/res.txt",tocheck);
  }
  return sum;
}

