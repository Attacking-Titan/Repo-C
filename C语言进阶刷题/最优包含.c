#include<stdio.h>
#include<string.h>
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	char S[1001]={'0'},T[1001]={'0'};
	int lens,lent,i,j;
	gets(S+1);//��֤S[j]ΪS�ĵ�j���ַ�
	gets(T+1);//��֤T[i]ΪT�ĵ�i���ַ�
	lens = strlen(S);
	lent = strlen(T);
	int dp[lent+1][lens+1];//dp[i][j]��ʾSǰj���ַ�ת������Tǰi���ַ�����Ҫ�Ĳ�����
	for(j = 0;j<lens;j++){
		dp[0][j] = 0;//��TΪ��ʱ��ֻ��ɾ���ַ����ɣ���ɾ���������
	}
	//����һ���ַ���s1Ҫ������һ��s2��s1�е��ַ���������ڵ���s2
	for(i = 1;i<=lent;i++){
	//���ڼ���dp[i][i]ʱ�޷���S�е��ַ�����ɾ������������Ҫ��������j==i�����
	if(T[i]==S[i]) dp[i][i] = dp[i-1][i-1];
		else dp[i][i] = dp[i-1][i-1]+1;//ֻ�����滻
		for(j = i+1;j<=lens;j++)
		if(T[i]==S[j]) dp[i][j] = dp[i-1][j-1];//T�е�i���ַ�����S�е�j���ַ�
		else {
			dp[i][j] = min(dp[i][j-1],dp[i-1][j-1]+1);//ɾ�����滻
		}
	}
	printf("%d",dp[lent][lens]);
	return 0;
}
