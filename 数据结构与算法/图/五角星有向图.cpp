#include<stdio.h>
int main()
{
	int a[5][5] = {
	{0,1,1,0,1},
	{0,0,0,1,0},
	{0,1,0,1,1},
	{1,0,0,0,1},
	{0,1,0,0,0}
	};
	int deg_2[5][5] = {0};//ͨ·��Ϊ2
	int deg_3[5][5] = {0};//ͨ·��Ϊ3
	int i,j,k;
	for(i = 0;i < 5;i++)
		for(j = 0;j < 5;j++)
			for(k = 0;k<5;k++)
				if(a[i][k]*a[k][j]>0) deg_2[i][j]++;//���v[i]��v[j]���ڳ���Ϊ2��ͨ·
	for(i = 0;i < 5;i++){
		printf("\t");
		for(j = 0;j < 5;j++)
			printf("%d ",deg_2[i][j]);
	printf("\n");
	}
	printf("- - - - - - - - - - - - - -\n");
	for(i = 0;i < 5;i++)
		for(j = 0;j < 5;j++)
			for(k = 0;k< 5;k++)
				if(deg_2[i][k]*a[k][j]>0) deg_3[i][j] += deg_2[i][k];//���v[i]��v[j]���ڳ���Ϊ3��ͨ·
	for(i = 0;i < 5;i++){
		printf("\t");
		for(j = 0;j < 5;j++)
			printf("%d ",deg_3[i][j]);
	printf("\n");
	}
	return 0;
}
