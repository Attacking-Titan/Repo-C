#include<stdio.h>
#include<memory.h>
int main()
{
	int a[9][9] = {
	{0,1,1,1,1,1,1,1,1},
	{1,0,1,1,1,0,1,1,1},
	{1,1,0,1,1,0,1,0,0},
	{1,1,1,0,0,1,1,1,0},
	{1,1,1,0,0,1,1,1,1},
	{1,0,0,1,1,1,1,1,0},
	{1,1,1,1,1,1,0,0,1},
	{1,1,0,1,1,1,0,0,1},
	{1,1,0,0,1,0,1,1,0},
	};
	int deg_2[9][9];
	int deg_3[9][9];
	int i,j,k,triangleNum = 0;
	memset(deg_2,0,sizeof(deg_2));
	memset(deg_3,0,sizeof(deg_3));
	for(i = 0;i<9;i++)
		for(j = 0;j<9;j++)
			for(k = 0;k<9;k++)
				if(a[i][k]*a[k][j]>0) deg_2[i][j]++;//v[i]��v[j]֮���γɳ���Ϊ1��ͨ·
	for(i = 0;i<9;i++)
		for(j = 0;j<9;j++)
			for(k = 0;k<9;k++)
				if(deg_2[i][k]*a[k][j]>0) deg_3[i][j]+=deg_2[i][k];//v[i]��v[j]֮���γɳ���Ϊ2��ͨ·
    for(i = 0;i<9;i++) {
    	printf("\t");
		for(j = 0;j<9;j++)
			printf("%d ",deg_2[i][j]);
	printf("\n");
	}
	printf("- - - - - - - - - - - - - - - - - - - - - - -\n");
	for(i = 0;i<9;i++) {
    	printf("\t");
		for(j = 0;j<9;j++)
			printf("%d ",deg_3[i][j]);
	printf("\n");
	}
	printf("- - - - - - - - - - - - - - - - - - - - - - -\n");
	for(i = 0;i<9;i++)
			triangleNum += deg_3[i][i];
	printf("%d",triangleNum/3);
	return 0;
}
