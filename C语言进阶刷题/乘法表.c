#include <stdio.h>
#include <stdlib.h>
/*����P�������P �����µĳ˷���*/
void fun(int d,int n)
{
  int r; 
  r=d/n;
  if(d>=n)fun(d/n,n);
  printf("%d",d%n);
}
int main(int argc, char *argv[])
{
  // ���ڴ��������Ĵ���
  int n,i,j;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  for(j=1;j<=i;j++){
  printf("%d*%d=",i,j);
  fun(i*j,n);
  printf(" ");
  if(j==i)printf("\n");
  }
  return 0;
}
