#include<stdio.h>
#define XNAME(n) x ## n
#define PRINT_X(n) printf("x" #n " = %d\n",x ## n);

/* ##��������������ຯ������滻���֣�##���������ڶ������滻���֣�##������������Ǻ���ϳ�һ���Ǻ� */
int main(){
	int XNAME(1) = 14;//���x1 = 14;
	int XNAME(2) = 20;//���x2 = 20;
	int x3 = 40;
	PRINT_X(1);//���printf("x1 = %d\n",x1);
	PRINT_X(2);//���printf("x2 = %d\n",x2);
	PRINT_X(3);//���printf("x3 = %d\n",x3);
	return 0;
}

