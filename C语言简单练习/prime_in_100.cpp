#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,t,count = 0;
	for(i = 2;i<=100;i++){
		for(j = 2;j<sqrt(i);j++){//���i�ܱ�2-sqrt(i)���ڵ�һ��������������ô���Ǻ���������Ϊ����
			if(i%j==0) break;//������������˳�ѭ��
		}
		if(j>sqrt(i))//���i����2-sqrt(i)���ڵ�һ������������Ϊ����
		{
			printf("%d\t",i);
			count++;
			if(count%5==0)  printf("\n");//ÿ��������������
		}
	}
}
