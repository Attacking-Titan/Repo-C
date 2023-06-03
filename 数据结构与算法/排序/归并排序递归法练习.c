#include<stdio.h>
#include<time.h>
void fillArr(int arr[],int n){
	int i;
	srand(time(NULL));
	for(i = 0;i<n;i++)
		arr[i] = rand()%1000;
}

void showArr(int arr[],int n){
	int i;
	for(i = 0;i<n;i++)
		printf(" %3d ",arr[i]);
	putchar('\n');
}

void mergeSort(int arr[],int reg[],int start,int end){
	if(start >= end) return;//���������ֻ��һ��Ԫ������������ģ�ֱ�ӷ���
	int len = end - start,mid = (len >> 1) + start;
	int start1 = start,end1 = mid;
	int start2 = mid + 1,end2 = end;
	mergeSort(arr,reg,start1,end1);
	mergeSort(arr,reg,start2,end2);
	int k = start;
	while(start1 <= end1 && start2 <= end2)
		reg[k++] = (arr[start1] < arr[start2]) ? arr[start1++] : arr[start2++];
	/* [start1,end1]��[start2,end2]�����ֿ�����һ����δ����reg�� */
	while(start1 <= end1)//��[start1,end1]��ʣ�ಿ�ֲ���arr��
		reg[k++] = arr[start1++];
	while(start2 <= end2)//��[start2,end2]��ʣ�ಿ�ֲ���arr��
		reg[k++] = arr[start2++];
	/* ����������õĲ��ֵ�arr�� */
	for(k = start;k <= end;k++)
		arr[k] = reg[k];
}

int main(){
	int n;
	printf("n = ");
	scanf("%d",&n);
	int arr[n],reg[n];
	fillArr(arr,n);
	showArr(arr,n);
	mergeSort(arr,reg,0,n-1);
	showArr(arr,n);
	return 0;
}
