#include <stdio.h>
#include <stdlib.h>
int count = 0;
int n,m;
void Hanoi(int n,char A,char B,char C){
  if(n==1) {
    count++;
    if(count==m) printf("#%d: %c->%c\n",n,A,C);//�����������m�����ʱ�Ķ���
    return;//��ֻ��һ������ʱ��ֻ���A���ƶ���C��
  }
  Hanoi(n-1,A,C,B);//��1~n-1�����Ӵ�A�ƶ���B��
  count++;//��n�����Ӵ�A���ƶ���C��
  if(count==m) printf("#%d: %c->%c\n",n,A,C);//�����������m�����ʱ�Ķ���
  Hanoi(n-1,B,A,C);//��1~n-1�����Ӵ�B���ƶ���C��
}
int main(int argc, char *argv[])
{
  int N;
  scanf("%d%d",&n,&m);
  Hanoi(n,'A','B','C');
  printf("%d",count);
  return 0;
}
