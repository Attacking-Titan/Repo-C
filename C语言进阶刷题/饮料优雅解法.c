#include<stdio.h>
int main(){
	int n,i;
	scanf("%d",&n);
	//i<=n��ʾ������ƿ����ʣ��
	for(i = 3;i <= n;i+=3)
		n++;//ÿ�κ���ƿ����һƿ
	printf("%d",n);
	return 0;
}
