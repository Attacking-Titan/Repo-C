#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
int main()
{
	int i,j,k,low,high,mid,arr[N],temp;
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
	//�������� 
	for(i=1;i<N;i++){
		temp = arr[i];
		low = 0;
		high = i-1;//���ö��ֲ��ҷ����Ҳ���λ��
		while(low<=high){
			mid = (low + high)/2;
			if(temp<arr[mid]) high = mid-1;
			else low = mid + 1;
		}
		for(j=i-1;j>=high+1;--j)//�ƶ�Ųλ 
			arr[j+1]=arr[j];
		arr[high+1] = temp;
		//��ӡ
		for(k=0;k<N;k++){
			if(k==i) printf(" [%3d] ",arr[k]);
			else if(k==low) printf("��%3d��",arr[k]);
			else printf("  %3d  ",arr[k]);
		}
		printf("\n\n");
	}
	return 0;
}
