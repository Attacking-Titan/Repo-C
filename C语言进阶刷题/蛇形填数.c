#include<stdio.h>
/* ģ���������� */
int main(){
	int a[50][50],i,j,row,col,num = 1;
	for(i = 0;i < 50;i++){
		/* ��i�У�ÿ����һ����*/
		col = i;//��һ�дӵ�i����ʼ��
		for(row = 0;row <= i;row++){
			a[row][col] = num;
			num++;
			col--;
		}
	}
	printf("%d",a[19][19]);
	return 0;
}

