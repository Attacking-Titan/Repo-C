/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:
	Description:��������
*/
/* ����һ����λ����ʾ��ʼ���ڣ�����20200202������һ���������ں���һ��ABABBABA�Ļ������� */
#include <stdio.h>
#include <stdlib.h>
//�ж��Ƿ����
int y[4],m[2],d[2];
_Bool check(int Y,int M,int D){
  y[0] = Y / 1000;
  y[1] = Y % 1000 / 100;
  y[2] = Y % 100 / 10;
  y[3] = Y % 10;
  m[0] = M / 10;
  m[1] = M % 10;
  d[0] = D / 10;
  d[1] = D % 10;
  if(y[0] == d[1] && y[1] == d[0] && y[2] == m[1] && y[3] == m[0])
  	return 1;
  else
    return 0;
}

int main(int argc, char *argv[])
{
  int month[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
  int Y,M,D,N,days,first = 0;
  scanf("%d",&N);
  Y = N / 10000;
  M = N / 100;
  D = N % 100;
  while(1){
    while(M <= 12){
      /* �жϴ����������� */
      if(M == 2){
        if(Y % 4 == 0 && Y % 100 != 0 || Y % 400 == 0) days = 28;
          else days = 29;
      }
        else days = month[M];
      /* ��������� */
      while(D <= days){
        if(check(Y,M,D)){
          if(first && y[0] == y[2] && y[1] == y[3]){
            printf("%d",Y * 10000 + M * 100 + D);//�ڶ�������������ABABBABA�Ļ�������
            return 0;
          }
          if(first == 0){
            printf("%d\n",Y * 10000 + M * 100 + D);//��һ����������
            first = 1;
          }
        }
        D++;
      }
      M++;
      D = 1;
   }
   Y++;
   M = 1;
 }
}
