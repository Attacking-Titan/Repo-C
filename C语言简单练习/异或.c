#include<stdio.h>
void swap(int *a,int *b){
	if(&(*a)==&(*a)) return;
	*a^=*b;
	*b^=*a;
	*a^=*b;
}
int main()
{
	int a = 3;
	int *p = &a;
	printf("��򽻻���������ֵ�����ܼӿ��ٶ�\n");
	printf("���ͨ�����������ֵ����һ������\n");
	printf("���������ĵ�ַ��ͬʱ������򽻻����ǵ�ֵ��ʹ������ȫ��Ϊ0\n");
	printf("���Խ�����������ֵǰ��Ҫ��������Ƿ���ͬһ��ַ\n");
	printf("a = %d\n",a);
	swap(&a,&a);
	printf("&a = %d\n",&a);
	printf("&(*p) = %d\n",&(*p));
	printf("a^a��a = %d",a);
	return 0;
}
