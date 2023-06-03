#include<stdio.h>
/*
С���ر�ϲ��2�������ǹ�Ԫ2020 �꣬���ر���ˣ���Ϊÿ�������϶����Կ���2
���������ֻ��ʾ�����գ����ʴӹ�Ԫ1900 ��1 ��1 �յ���Ԫ9999 ��
12 ��31 �գ�һ���ж����������ϰ���2�����ж������������յ���λ�а�������2��
*/
int day[] = {
	0,31,28,31,30,31,30,31,30,31,31,30,31
};
_Bool is_leap(int y){
	return y % 400==0 || y % 4==0 && y % 100!=0;
}//�ж�����
int daysOfMonth(int y,int m){
	if(m==2) return 28 + is_leap(y);
	return day[m];
}//��ȡĳ�µ��������
_Bool check(int x,int y,int z){
	int a[] = {x,y,z},i;
	for(i = 0;i < 3;++i)
		while(a[i] > 0)
			if(a[i] % 10 ==2) return 1;
				else a[i] /= 10;
   return 0;
}//������������Ƿ���2
int main(){
	int i,j,k;
	int res = 0;
	for(i = 1900;i <= 9999;i++)
		for(j = 1;j <= 12; ++j)
			for(k = 1; k <= daysOfMonth(i,j);k++)
				res += check(i,j,k);
   printf("%d",res);
}
