#include <stdio.h>
#include <stdlib.h>
#define N 20

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

void max_heapify(int arr[], int start, int end) {
    //�������ڵ�ָ����ӽڵ�ָ��
	int root = start;
    int child = root * 2 + 1;
    while (child <= end) { //���ӽڵ�ָ���ڷ�Χ�ڲ����Ƚ�
        if (child + 1 <= end &&  arr[child + 1] > arr[child]) //��ȡ���Һ����нϴ���Ǹ�
            child++;
        if (arr[root] > arr[child]) //������ڵ�������Һ��ӽڵ�
		{
   			return;
		}
        else { //�������ӽڵ㲢�����Ƚ�
			int temp = arr[root];
			arr[root] = arr[child];
			arr[child] = temp;
			root = child;
            child = root * 2 + 1;
        }
    }
}

void HeapSort(int arr[], int len) {
    int i;
	/* ��ʼ�����Ӻ���ǰ���������һ������ */
    for (i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
	//�Ƚ���һ��Ԫ�غ����ź�Ԫ�ص�ǰһλ�������������µ�����ֱ���������
    for (i = len - 1; i > 0; i--) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
        max_heapify(arr, 0, i - 1);//��������
    }
}

int main() {
	int arr[N];
 	fillArray(arr,N);
 	showArray(arr,N);
 	HeapSort(arr,N);
 	showArray(arr,N);
    return 0;
}

