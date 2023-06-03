#include<stdio.h>
#include<stdlib.h>
#define INF 0x7fffffff

typedef struct Heap{
	int capacity;//����
	int size;
	int *data;
}Heap;

/* ��ʼ���� */
Heap* initHeap(int capacity){
	Heap *H = (Heap *)malloc(sizeof(Heap));
	H->capacity = capacity;
	H->size = 0;
	H->data = (int *)malloc(sizeof(int) * (capacity + 1));
	H->data[0] = -INF;
	return H;
}

_Bool isFull(Heap *H){
	return H->size == H->capacity + 1;
}

void insert(int data,Heap *H){
	int i;
	if(isFull(H)){
		printf("���ȶ���������\n");
		return;
	}
	/* ����,�ڸ��ڵ���� */
	for(i = ++H->size;H->data[i / 2] > data;i /= 2){
		H->data[i] = H->data[i / 2];
	}
	H->data[i] = data;
}

_Bool isEmpty(Heap *H){
    return H->size == 0;
}

int deleteMin(Heap *H){
	int i,child;
	int min,last;
	if(isEmpty(H)) {
		printf("���ȶ���Ϊ�գ�\n");
		return;
	}
	min = H->data[1];
	last = H->data[H->size--];
	for(i = 1;i * 2 <= H->size;i = child){
		child = i * 2;//��ȡ����
		/* �Ƚϳ����Һ��ӵĽ�С�� */
		if(child != H->size && H->data[child + 1] < H->data[child])
			child++;
		/* ���last�������Һ��ӣ����� */
		if(last > H->data[child])
			H->data[i] = H->data[child];
		else break;//last���ϲ�������
	}
	H->data[i] = last;//��last����
	return min;
}

Heap *buildHeap(int* data,int length){
	Heap *H = initHeap(length);
	int i;
	for(i = 0;i < length;i++){
  		insert(data[i],H);
	}
	return H;
}

int main() {
	int arr[20];
	int i;
	srand(time(NULL));
	for(i = 0;i < 20;i++){
		arr[i] = rand() % 1000;
	}
	Heap *H = buildHeap(arr,20);
	for(i = 0;i < 20;i++){
		arr[i] = deleteMin(H);
	}
	for(i = 0;i < 20;i++){
		printf("%d ",arr[i]);
	}
	putchar('\n');
	return 0;
}
