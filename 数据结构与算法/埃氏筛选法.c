#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<math.h>
#define N 2000000
_Bool is_prime(int n){
	int i=2;
	int m = sqrt(n);
	while(i<=m){
		if(n % i == 0)return 0;
		i++;
	}
	return 1;
}
//����ɸѡ�� 
int main(){
	int i,j,count = 0;
	_Bool prime[N+1];
	int m = sqrt(N);
	memset(prime,1,sizeof(prime));//��ʼ��prime����Ԫ��ȫ��Ϊ1 
	//�ҳ�sqrt(N)���ڵ�ȫ������ 
	for(i = 2;i <= m;i++){
		if(is_prime(i) == 0)
		prime[i] = 0;
	} 

	//ɸѡ 
	printf("\t");
	for(i = 2;i <= m;i++){
		//��sqrt(N)���ڵ�������ɸѡN*N���ڵ����� 
		if(prime[i])	
		for(j = m+1;j <= N;j++)
		if( j%i == 0)prime[j]=0;
	}
	
	//��ӡ���� 
	for(i=2;i<=N;i++) 
	if(prime[i]){
		printf("%d\t",i);
		count++; 
	}
	printf("\n2000000�����ܹ�%d������",count); 
	return 0;
}

