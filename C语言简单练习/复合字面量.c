#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	//������������Ҳ�������Ϊǿ��ת��,���Բ���Ҫ���ⴴ��һ������ 
	char *p1 = (char [8]){'a','b','c','d','e','f','g','\0'};
	char *p2 = (char [11]){"hello,world"};
	int *pt = (int[4]){10,20,30,40};//���������������Բ���Ҫ���ȴ������飬����������������һ���������飬�����ڴ�����ͬʱʱʹ���� 
    for(i=0;i<4;i++)
    printf("%d ",pt[i]);
    printf("\n");
    for(i=0;i<8;i++)
    printf("%c ",p1[i]);
    printf("\n");
    for(i=0;i<11;i++)
    printf("%c",p2[i]);
    return 0;
}
