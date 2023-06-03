/*
    ���ȶ��е�ʵ��
    ��������ڵ�i���丸����i/2����������2i�����Һ�����2i+1��
*/
#include<stdio.h>
#include<stdlib.h>
#define INF 0x7fffffff

/* ����� */
struct Heap{
	int capacity;//����
	int size;//��¼��������һ��Ԫ�ص�����
	int *data;//һά�����ʾ�����
};
typedef struct Heap priorityQueue;

/* �������ȶ��� */
priorityQueue *createQueue(int capacity){
 	priorityQueue *Q = (priorityQueue *)malloc(sizeof(priorityQueue));
 	Q->capacity = capacity;
 	Q->data = (int *)malloc(sizeof(int) * capacity + 1);//Q->data[0]���ڴ�ű�ʶ�����Զ�����һ���ռ�
	Q->data[0] = -INF;//����һ����ʶ������ֹ����
	Q->size = 0;
	return Q;
}

/* ���� */
void insert(priorityQueue *Q,int data){
	if(Q->size == Q->capacity) {
		printf("���ȶ���������\n");
		return;
	}
	/* ����,���뷨 */
	int i;
	for(i = ++Q->size;data < Q->data[i / 2];i /= 2 ){
		Q->data[i] = Q->data[i / 2];
	}
	Q->data[i] = data;//����
}

/* ��ʼ�����ȶ��� */
void initQueue(priorityQueue *Q,int data[],int length){
	int i;
	for(i = 0;i < length;i++){
  		insert(Q,data[i]);//��data[i]���뵽���ȶ�����
	}
}

/* �������ȶ��� */
void traverseQueue(priorityQueue *Q){
	int i;
	for(i = 1;i <= Q->size;i++){
		printf("%d(%d) ",Q->data[i],Q->data[i / 2]);
	}
	putchar('\n');
}

/* ɾ����СԪ  */
void deleteMin(priorityQueue *Q){
	if(Q->size == 0) {
		printf("���ȶ���Ϊ�գ�");
		return;
	}
	int last = Q->data[Q->size--];//��ȡ�������һ������
	/* ɾ����СԪ����ֿ�λ��������Ľڵ������ƶ���last������Ͽ�λ������ֱ�ӽ�last�ŵ���λ�� */
	/* ���� */
	int i,child;
	for(i = 1;i * 2 <= Q->size;i = child){
		/* ��ȡ���Һ����и�С���Ǹ� */
		child = 2 * i;
		if(Q->data[child + 1] < Q->data[child])
			child++;
		/* �ж�last�Ƿ���Ͽ�λ */
		if(last < Q->data[child])//���last�����Һ��Ӷ�С
			break;
		else
			Q->data[i] = Q->data[child];//��С�ĺ������Ƶ��丸�׵�λ��
	}
	Q->data[i] = last;
}

/* ���ҹؼ��� */
int find(priorityQueue *Q,int key){
	int i;
	for(i = 1;i <= Q->size;i++){
		if(Q->data[i] == key) return i;
	}
	return 0;
}

/* ��߹ؼ��ֵ�ֵ */
void increaseKey(priorityQueue *Q,int alter,int key){
	int index = find(Q,key);
	if(index == 0){
		printf("���ȶ����в�����%d�ؼ���\n",key);
		return;
	}
	else {
		/* ���� */
		int i,child;
		key += alter;//��߹ؼ��ֵ�ֵ
		Q->data[index] = key;
		for(i = index;i * 2 <= Q->size;i = child){
			/* ��ȡ���Һ����еĸ�С���Ǹ� */
			child = i * 2;
			if(Q->data[child + 1] < Q->data[child])
				child++;
			if(key < Q->data[child])
				break;
			else
				Q->data[i] = Q->data[child];//��ǰ����
		}
		Q->data[i] = key;//����
	}
}

/* ���͹ؼ��ֵ�ֵ */
void decreaseKey(priorityQueue *Q,int alter,int key){
	int index = find(Q,key);
	if(index == 0){
		printf("���ȶ����в�����%d�ؼ���\n",key);
		return;
	}
	else {
		/* ���� */
		int i;
		key -= alter;//���͹ؼ��ֵ�ֵ
		for(i = index;key < Q->data[i / 2];i /= 2) {
			Q->data[i] = Q->data[i / 2];//�����
		}
		Q->data[i] = key;
	}
}

void deleteKey(priorityQueue *Q,int key){
	decreaseKey(Q,INF,key);
	deleteMin(Q);
}

int main(){
	int arr[10] = {78,34,12,10,56,39,77,24,9,57};
 	priorityQueue *Q = createQueue(10);
 	printf("ע��������ÿһ�����ݺ���������ڵ�����Ϊ���ǵĸ���\n");
 	printf("�������ȶ��У�");
  	initQueue(Q,arr,10);
   	traverseQueue(Q);
   	printf("ɾ����СԪ��");
   	deleteMin(Q);
   	traverseQueue(Q);
   	printf("��10���߳�30��");
   	increaseKey(Q,20,10);
   	traverseQueue(Q);
   	printf("��56���ͳ�20��");
   	decreaseKey(Q,36,56);
   	traverseQueue(Q);
   	printf("ɾ��77��");
   	deleteKey(Q,77);
   	traverseQueue(Q);
	return 0;
}

