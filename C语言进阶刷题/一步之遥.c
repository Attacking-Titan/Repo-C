#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // ���ڴ��������Ĵ���
  int count = 0,d = 0;
  while(d!=1){
    if(d > 1)d-=127;
    else d+=97;
    count++;
  }
  printf("%d",count);
  return 0;
}
