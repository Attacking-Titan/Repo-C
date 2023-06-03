#include<stdio.h>
#include<stdlib.h>
#define N 30

void fillArray(int arr[],int n){
	int i;
	srand(time(NULL));
	for(i = 0;i<n;i++)
		arr[i] = rand() % 1000 + 1;
}

void showArray(int arr[],int n){
	int i;
	for(i = 0;i<n;i++){
		printf("  %4d  ",arr[i]);
		if((i+1)%10==0) putchar('\n');
	}
	printf("\n");
}

void quickSort(int array[],int low,int high){
	if(low >= high) return;
	int i = low,j = high;
	int index = array[i];//ȡ����ߵ�����Ϊ��׼��
	while(i<j) {
		while(i < j && array[j] >= index)//����Ѱ�ҵ�һ��С��index����
			j--;
		if(i < j) array[i++] = array[j];//��array[j]����array[i]��,����i�����ƶ�
		while(i < j && array[i] < index)//����Ѱ�ҵ�һ������index����
			i++;
		if(i < j) array[j--] = array[i];//��array[j]����array[i]��,����j�����ƶ�
	}
	array[i] = index;//����׼���������Ŀ�
	quickSort(array,low,i-1);//�ݹ���ã�����low��i-1
	quickSort(array,i+1,high);//�ݹ���ã�����i+1��high
}

int main()
{
	int arr[N];
	fillArray(arr,N);
	showArray(arr,N);
	quickSort(arr,0,N);
	showArray(arr,N);
	return 0;
}
