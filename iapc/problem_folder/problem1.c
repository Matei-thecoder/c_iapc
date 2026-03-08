#include <stdio.h>

int main(void)
{
	int n,i;
  int v[100]={};
  scanf("%d",&n);
  for(i=0;i<n;++i)
  {
    scanf("%d",v+i);
  }

  for(i=0;i<n;i++)
  {
    printf("%d ",v[i]);
  }
  //printf("\n");
	return 0;
	
}
