#include<stdio.h>
int main()
{
	float pi=3.141592653;
	float f=-0.0000347821;
	float F=0.000743212;
	float ff=123.768;
	printf("%15f-----�Ҷ���\n",pi);
	printf("%-15f-----�����\n",pi);
	printf("%+f-----��ʾ������\n",f);
	printf("%+f-----��ʾ������\n",F);
	printf("% f-----���������ո񣬸�������Ӹ���\n",f);
	printf("% f-----���������ո񣬸�������Ӹ���\n",F);
	printf("%10.6f------��С�ַ���Ⱥ�С��λ��\n",pi);
	printf("%015f------ǰ��0\n",ff);
	return 0; 
}
