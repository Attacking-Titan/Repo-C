#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 25
int main()
{
	_Bool flag=1; 
	int i,j,k,arr[N];
	srand(time(NULL));
	for(i=0;i<N;i++){
		arr[i] = rand()%1000;
		srand(arr[i]);
	}
	//ԭʼ���� 
	for(i=0;i<N;i++){
		printf("  %3d  ",arr[i]);
	}
	printf("\n\n");
	for(i=0;i<N-1&&flag==1;i++){
	flag = 0; 
		for(j=0;j<N-i-1;j++){
			if(arr[j]>arr[j+1]){
				arr[j] = arr[j]+arr[j+1];
				arr[j+1] = arr[j]-arr[j+1];
				arr[j] = arr[j]-arr[j+1];
				flag = 1;//�����˽�����flag=1 
			}
		}
	//��ӡ���� 
	for(k=0;k<N;k++){
		if(k==N-i-1)printf(" [%3d] ",arr[k]);
		else printf("  %3d  ",arr[k]);
	}
	printf("\n\n");
	//�����һ��û�н��н���˵�������Ѿ�������ˣ�ֹͣ���� 
	}
	return 0;
}
