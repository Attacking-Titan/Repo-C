#include <stdio.h>
#include <stdlib.h>
/*
С���ر�ϲ��2�������ǹ�Ԫ2020 �꣬���ر���ˣ���Ϊÿ�������϶����Կ���2
���������ֻ��ʾ�����գ����ʴӹ�Ԫ1900 ��1 ��1 �յ���Ԫ9999 ��
12 ��31 �գ�һ���ж����������ϰ���2�����ж������������յ���λ�а�������2��
*/
int main(int argc, char *argv[])
{
  int year,days = 0,temp,flag;
  for(year = 1900;year < 10000;year++){
  temp = year;
  flag = 0;
  while(temp){
  if(temp%10==2){
    flag = 1;
    break;
  }
  temp/=10;
  }
  if(flag==1){
  if(year%4==0 && year%100!=0 || year%400==0) days+=366;
  else days+=365;
  }
    else if(year%4==0 && year%100!=0 || year%400==0)  days+=180;
      else days+=179;
  }
  printf("%d",days);
  return 0;
}
