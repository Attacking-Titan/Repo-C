#include<stdio.h>
int main(){
	int n,sum;
	scanf("%d",&n);
	sum = n;//sum��ʾ���˼�ƿ
	while(n > 2){
		sum += n/3;//�һ�
		n = n / 3 + n % 3;//�һ����ü����ϴζһ���ʣ���
	}
	printf("%d",sum);
	return 0;
}
