#include<stdio.h>
#include<time.h>
#define N 20

void fillArr(int *arr,int n){
	int i;
	srand(time(NULL));
	for(i = 0;i<n;i++)
        arr[i] = rand()%1000;
}

void showArr(const void *arr,int n){
	int i;
	const int *p = (const int *)arr;
	for(i = 0;i<n;i++){
		printf(" %3d ",p[i]);
	}
	printf("\n");
}

//�����趨һ���ֽ�ֵ��ͨ���÷ֽ�ֵ������ֳ�����������
//�����ڻ���ڷֽ�ֵ�����ݼ��е������ұߣ�С�ڷֽ�ֵ�����ݼ��е��������
//����ߺ��ұߵ������ظ���������
void quickSort(int arr[],int left,int right){
	if(left<right) {
		int i,j,pivot,temp;
		i = left,j = right,pivot = left;
		while(i<j){
			while(arr[i]<=arr[pivot] && i<right)//����Ѱ�ҵ�һ�����ڵ��ڻ�׼ֵ����
				i++;
			while(arr[j]>arr[pivot])//����Ѱ�ҵ�һ��С�ڻ�׼ֵ����
				j--;
  			if(i<j){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}//������ҵ��ĵ�һ�����ڻ�׼ֵ�������ұ��ҵ��ĵ�һ�����ڻ�׼ֵ��������
		}
		/* ����׼ֵ��arr[j]���� */
		if(pivot!=j){
			temp = arr[pivot];
			arr[pivot] = arr[j];
			arr[j] = temp;
		}
		quickSort(arr,left,j-1);
		quickSort(arr,j+1,right);
	}//�����߽�С���ұ߽���ִ�п�������
}

int main(){
	int arr[N];
	fillArr(arr,N);
	showArr(arr,N);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	quickSort(arr,0,N-1);
	showArr(arr,N);
	return 0;
}
