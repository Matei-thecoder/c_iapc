#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alocari.h"
#include "executare.h"
#include "verificare.h"
#include "mysource.h"
//ordine fisiere: executabil makefile 
// fisierul de iesire se va numi by default res.txt

//TODO:
//verificare parametri
//gasit o solutie de compartimentalizare
//stergerea fisierelor primite
//calcularea unui scor si returnarea lui.
//de acum de gandit sistemul sa primeasca mai multe fisiere de text source. pe alta data.
int main(int argc,char *argv[])
{
  
  MYSOURCE source; 
  int score=0;
  source.pcharArray = &charArray;
  source.pdeallocChar = &deallocChar;
  source.pcompile = &compile;
  //source.pcheckAllFiles = &checkAllFiles;
  if(argc<2)
  {
    fprintf(stderr,"Not enough files\n");
    exit(EXIT_FAILURE);
  }
  
  source.exe = source.pcharArray(strlen(argv[1]));
  source.makefile = source.pcharArray(strlen(argv[2]));
  
  strcpy(source.exe,argv[1]);
  strcpy(source.makefile,argv[2]);
  
  if(!source.pcompile(source.makefile))
  {
    exit(EXIT_FAILURE);
  }

  score = checkAllFiles(source,&checkOneFile);

  printf("Your score is %d\n",score);

  source.pdeallocChar(source.exe);
  source.pdeallocChar(source.makefile);
  source.exe = 0;
  source.makefile = 0;

  return 0;
}

