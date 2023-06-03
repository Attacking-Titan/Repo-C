/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:
	Description:
*/
#include <stdio.h>
#include <stdlib.h>
int max(int a,int b){
	return a > b ? a : b;
}
int main(int argc, char *argv[])
{
  int N;
  scanf("%d",&N);
  int i,j,a[100][100] = {0};
  /* ���� */
  for(i = 0;i < N;i++)
  	for(j = 0;j <= i;j++){
    	scanf("%d",&a[i][j]);
  	}
  /* ��ʼ��dp���� */
  int dp[100][100] = {0};
  dp[0][0] = a[0][0];
  /* ��dp���� */
  for(i = 1;i < N;i++){
	for(j = 0;j <= i;j++){
		if(j == 0) dp[i][j] = dp[i-1][0] + a[i][j];
            else if(j == i) dp[i][j] = dp[i-1][j-1] + a[i][j];
				else dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + a[i][j];
	}
  }
  /* ��� */
  /* ������������ߵĲ�����ȣ�����󵽴��һ�������һ�����м��λ�� */
  if(N % 2 == 0) printf("%d",max(dp[N-1][N/2],dp[N-1][N/2-1]));//NΪż����ȡdp�����N���м�������������
  else printf("%d",dp[N-1][N/2]);//NΪ����
  return 0;
}
