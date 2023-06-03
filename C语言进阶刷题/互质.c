#include <stdio.h>
#include <stdlib.h>
/*������ 2020 ��, ������ 10 �� 18 �ա� ������ 1 �� 2020 ��, �ж��ٸ����� 1018 ���ʡ�*/
int gcd(int a,int b){
  int t = 1;
  do{
    t = a % b;
    a = b;
    b = t;
  }while(t != 0);
  return a;
}
int main(int argc, char *argv[])
{
  int i,ans = 0;
  for(i = 1;i < 1018;i++)
    if(gcd(1018,i)==1) ans++;
  for(i = 1019;i <= 2020;i++)
    if(gcd(i,1018) == 1) ans++;
  printf("%d",ans);
  return 0;
}
