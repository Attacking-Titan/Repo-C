#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/*
A �еĳ�������λ���, ����ǰ��λ����Ϊ���� 0 �� 9 , ������ĸA ��F, ÿλ�� 16 �ֿ��ܡ�
����λֻ�������� 0 �� 9��Ϊ�˼����ʱ�, �����в������� ����λ����ͬ���ַ���
����, 202020 �ǺϷ��ĳ���, AAA202 ���ǺϷ��ĳ���, ��Ϊǰ������ ĸ��ͬ������, A ���ж��ٸ��Ϸ��ĳ���?
*/
_Bool check(char *p)
{
  int i; 
  for(i=0;i<4;i++)
  {
  if(*(p+i)==*(p+i+1)&&*(p+i)==*(p+i+2))return 0;
  }
  return 1;
}
int main(int argc, char *argv[])
{
  // ���ڴ��������Ĵ���
  char str[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  char arr[6];
  char *p=&str[0];
  short i,j,k,m,n,r;
  long count=0;
  for(i=0;i<16;i++){
    arr[0]=*(p+i);
    for(j=0;j<16;j++){
      arr[1]=*(p+j);
      for(k=0;k<16;k++){
        arr[2]=*(p+k);
        for(m=0;m<10;m++){
          arr[3]=*(p+m);
          for(n=0;n<10;n++){
            arr[4]=*(p+n);
            for(r=0;r<10;r++){
              arr[5]=*(p+r);
              if(check(&arr[0]))count++;
            }
          }
        }
      }
    }
  }
  printf("%ld",count);
  return 0;
}
