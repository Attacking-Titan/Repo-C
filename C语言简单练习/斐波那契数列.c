#include<stdio.h>
#include<stdlib.h>
#define N 100
long long helper[N+1]={0};//long longֻ�ܼ��㵽fib(92); 
//������¼�ĵݹ�д�� 
long long fib(long long n){
	if(n==1)return 1;
	else if(helper[n-1] == 0)helper[n-1] = fib(n-1);
	if(n==2)return 1;
	else if(helper[n-2] == 0)helper[n-2] = fib(n-2);
	return helper[n-1] + helper[n-2];
}
int main()
{
	int n,i;
	printf("n=");
	scanf("%d",&n);
	printf("fib[%d]=%lld\n",n,fib(n));
	return 0;
}
