/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:23/03/23 14:41
	Description:ͨ��״̬ѹ������������
*/
#include<stdio.h>
long long f(int rows,int cols){
	if(cols == 0 || cols == rows) return 1;
	else if(cols == 1) return rows;
	int dp[1024],p,q;//�к��д�0��ʼ����
	dp[0] = 1;
	dp[1] = 1;
	p = 2;//�ӵ����п�ʼ
	while(p <= rows){
		for(q = p;q > 0;q--){
			dp[q] = dp[q] + dp[q-1];//����ÿ�μ���ֻ��Ҫ��һ���ֵ���ʿ��Խ���״̬ѹ��
		}
		p++;
	}
	return dp[cols];
}
int main(){
	int rows,cols;
	printf("rows = ");
	scanf("%d",&rows);
	printf("cols = ");
	scanf("%d",&cols);
	printf("f(%d,%d) = %lld",rows,cols,f(rows,cols));
	return 0;
}

