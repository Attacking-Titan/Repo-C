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

void traverseHeap(Heap *H){
	int i;
	for(i = 1;i <= H->size;i++){
		printf("%d ",H->data[i]);
	}
	putchar('\n');
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

int find(Heap *H,int key){
	int i;
	for(i = 1;i <= H->size;i++){
		if(H->data[i] == key) return i;
	}
	return 0;
}

Heap *buildHeap(int* data,int length){
	Heap *H = initHeap(length);
	int i;
	for(i = 0;i < length;i++){
  		insert(data[i],H);
	}
	return H;
}

void decreaseKey(int key,int alter,Heap *H){
	int index = find(H,key);
	if(index == 0) {
		printf("���ȶ����в�����%d��\n",key);
		return;
	}
	H->data[index] -= alter;//���͹ؼ��ֵ�ֵ
	/* ���� */
	int i;
	int data = H->data[index];
	for(i = index;H->data[i / 2] > data;i /= 2){
		H->data[i] = H->data[i / 2];
	}
	H->data[i] = data;
}

void increaseKey(int key,int alter,Heap *H){
	int index = find(H,key);
	if(index == 0) {
		printf("���ȶ����в�����%d��\n",key);
		return;
	}
	H->data[index] += alter;//���ӹؼ��ֵ�ֵ
	/* ���� */
	int i;
	int data = H->data[index];
	int child;
	for(i = index,child = i * 2;i * 2 <= H->size;i = child){
		if(H->data[child + 1] < H->data[child])
			child++;
		if(H->data[child] < data) {
			H->data[i] = H->data[child];
		}
		else break;
	}
 	H->data[i] = data;
}

void deleteKey(Heap *H,int key){
	if(find(H,key) == 0) {
		printf("���ȶ����в�����%d",key);
		return;
	}
	decreaseKey(key,INF,H);
	deleteMin(H);
}

int main(){
	int arr[10] = {13,24,31,10,19,75,44,25,17,63};
	Heap *H = buildHeap(arr,10);
	printf("�������ȶ��У�");
	traverseHeap(H);
	deleteMin(H);
	printf("ɾ����СԪ��");
 	traverseHeap(H);
 	printf("���ؼ���24����12��");
 	decreaseKey(24,12,H);
 	traverseHeap(H);
	printf("���ؼ���17����18��");
  	increaseKey(17,18,H);
   	traverseHeap(H);
   	printf("ɾ���ؼ���31��");
   	deleteKey(H,31);
   	traverseHeap(H);
	return 0;
}

