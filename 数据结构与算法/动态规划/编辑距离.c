#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int min(int a,int b,int c){
	if(a>b) a = b;
	if(a>c) a = c;
	return a;
}
int mindistance(char *s1,char *s2){
	int length1 = strlen(s1);
	int length2 = strlen(s2);
	int i,j,dp[length1+1][length2+1];
	for(i = 0;i<=length1;i++){
		dp[i][0] = i;//ֻ��ɾ������ 
	}
	for(i = 0;i<=length2;i++){
		dp[0][i] = i;//ֻ�������� 
	}
	for(i = 1;i<=length1;i++){
		for(j = 1;j<=length2;j++)
		{
			//���s1[i]��s2[j]���,��i���ַ���Ӧ���±�Ӧ����i-1; 
			if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];//���s1��i���ַ���s2��j���ַ���� 
				else dp[i][j] = min(dp[i-1][j-1],dp[i][j-1],dp[i-1][j])+1;
		}
	}
	return dp[length1][length2];
}

int main()

{
	char s1[50],s2[50];
	scanf("%s%s",s1,s2);
	printf("%d",mindistance(s1,s2));
	return 0;
}
