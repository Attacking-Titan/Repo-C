#include<stdio.h>
int step(int n,int num){
    if(n==39){
		if(num%2==0) return 1;//�ҽŴﵽ�յ�
		else return 0;//�����յ�,���ҽ����
	}
	if(n>39) return 0;//�����յ�
	return step(n+1,num+1)+step(n+2,num+1);//��ǰ��һ���������ܵ����յ�������
}
int main()
{
	 printf("%d",step(0,0));
	 return 0;
}
