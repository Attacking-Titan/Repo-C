#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // ���ڴ��������Ĵ���
  int s,a = 2019,b = 324,L,count = 0;
  s = a*b;
  while(s>0){
    if(b<a){
    s-=b*b;
    a-=b;
    }
      else {
      s-=a*a;
      b-=a;
      } 
  count++;
  }
  printf("%d",count);
  return 0;
}
