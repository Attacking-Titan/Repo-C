#include<stdio.h>
int main(){
	int n,m,res = 0;//nΪ��������mΪƿ����
    scanf("%d",&n);
	while(n > 0 || m >=3){
		res += n;
		m += n;
		n = m / 3;
		m %= 3;
	}
	printf("%d",res);
}
