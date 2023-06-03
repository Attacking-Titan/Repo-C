#include <stdio.h>
#include <stdlib.h>
/*
������ը��2015 ��1 ��1�շ��ã���ʱΪ15�죬������2015��1��16�ձ�ը��
��һ������ը����2014 ��11 ��9 �շ��ã���ʱΪ1000 �죬�����������ը��׼ȷ���ڡ�
����������ڣ���ʽΪyyyy-mm-dd ��4 λ���2 λ�·�2 λ���ڡ����磺2015-02-19��
*/
int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
_Bool isLeap(int year){
  return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}
int main(){
	int y,m,d,days,cnt = 53;
	for(y = 2015;;y++){
		for(m = 1;m <= 12;m++){
			if(m == 2) days = day[m] + isLeap(y);
				else days = day[m];
			for(d = 1;d <= days;d++){
				if(cnt == 1000) {
					printf("%d-%02d-%02d",y,m,d);
					return 0;
				}
				cnt++;
			}
		}
	}
}
