#include <stdio.h>
#include<math.h>

int main(int argc, char *argv[])
{
  // ���ڴ��������Ĵ���
  int i=20000,j,count;
  while(1){
  count = 0;
  for(j=1;j<=i;j++)
  if(i%j==0)count++;
  if(count==100)break;
  i++;
  }
  printf("%d",i);
  return 0;
}
