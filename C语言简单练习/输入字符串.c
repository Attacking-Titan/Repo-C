#include<stdio.h>
#include<stdlib.h>
int put1(const char  *string){
	int count = 0; 
	while(*string != '\0'){
	putchar(*string++);//�����*string��string++��
	count++;
	}
	printf("\n");//���뻻�п���ʡ�� 
	return count;//����ַ������л��з�Ҳ��ͳ�����ַ����������� 
}
int main()
{
	int ch_num;
	char str1[30],str2[30];
	gets(str1);//�����������룬����\n�������� ���Զ�����\n 
	printf("%s\n",str1);//�����ո�,\t,\n,\v���������һ��ֻ�����һ������ 
	puts(str1);//�Զ�������ַ���ĩβ�������\n 
	fgets(str2,30,stdin);//fgets���������еĻ��з� 
	fputs(str2,stdout);//fputs�����������ӻ��з� 
	ch_num = put1(str1);
	printf("%d\n",ch_num);
	return 0;
}
