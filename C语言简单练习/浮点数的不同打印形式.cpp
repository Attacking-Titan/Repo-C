#include<stdio.h>
int main()
{
	float input;
	printf("Enter a floating-point value:");
	scanf("%f",&input);
	printf("fixed-point notation:%f\n",input);//��ͨС����ʽ
	printf("exponential notatino:%e\n",input);//ָ����ʽ
	printf("p notation:%a\n",input);
	return 0; 
}
