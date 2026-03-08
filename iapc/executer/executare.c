#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "executare.h"

int compile(char *makefile)
{
  char cmd_command[256];
  sprintf(cmd_command,"cd ../problem_folder/ \n make -f %s",makefile);

  if(system(cmd_command)!=0)
  { 
    fprintf(stderr,"Eroare la compilare fisier make\n");
    return 0;
  }



  return 1;
}


int run(char *source_exe,char *input_txt, char *res_txt)
{
  char cmd_command[256];
  sprintf(cmd_command,"cd ../problem_folder/ \n ./%s <../%s/%s >%s",source_exe,source_exe,input_txt,res_txt);

  if(system(cmd_command)!=0)
  {
    fprintf(stderr,"Eroare la executare\n ");
    return 0;
  }
  return 1;
}

