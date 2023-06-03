#include<stdio.h>
#include<stdlib.h>
#define INF 0x7fffffff
#define MAXSIZE 5

struct BinNode{
	int data;
	struct BinNode *child;//��һ������
	struct BinNode *brother;//�ֵ�
};
typedef struct BinNode BinTree;

struct Collection{
	int currentSize;//��¼��ǰ�����������ܽڵ���
	BinTree *Trees[MAXSIZE];//��һά����˳��Ĵ洢�������ĸ��ڵ�
};
typedef struct Collection BinQueue;

int capacity = 1 << MAXSIZE;

BinTree *initTree(int data){
	BinTree *T = (BinTree *)malloc(sizeof(BinTree));
	T->data = data;
	T->child = NULL;
	T->brother = NULL;
	return T;
}

BinQueue *initQueue(){
	BinQueue *H = (BinQueue *)malloc(sizeof(BinQueue));
	H->currentSize = 0;
	/* ��ʼ�������� */
	int i;
	for(i = 0;i < MAXSIZE;i++){
		H->Trees[i] = NULL;
	}
	return H;
}

void preOrder(BinTree *T,BinTree *father){
	if(T != NULL) {
		printf("data:%d ",T->data);
		if(father) printf("father:%d ",father->data);
		else printf("father:NULL ");
		if(T->brother) printf("brother:%d",T->brother->data);
		else printf("brother:NULL");
		putchar('\n');
 		preOrder(T->child,T);
 		preOrder(T->brother,father);
	}
}

void traverseQueue(BinQueue *H){
	int i;
	for(i = 0;i < MAXSIZE;i++){
		if(H->Trees[i] != NULL){
			printf("B%d��\n",i);
			preOrder(H->Trees[i],NULL);
			putchar('\n');
		}
	}
}

/* �ϲ����ö�������T2���T1�Ķ��� */
BinTree *combineTree(BinTree *T1,BinTree *T2){
	if(T1->data > T2->data)//Ĭ��T1��dataС��T2��data
		return combineTree(T2,T1);
	T2->brother = T1->child;
	T1->child = T2;
	return T1;
}

/* �ϲ������������ */
BinQueue *merge(BinQueue *H1,BinQueue *H2)//����H1
{
	if(H1->currentSize + H2->currentSize > capacity)
		printf("�ϲ����ᳬ������");
	BinTree *T1,*T2,*carry = NULL;//carry��ʾ�ϲ�������ĸ���Ķ�����
	H1->currentSize += H2->currentSize;
	int i,j;
	for(i = 0,j = 1;j <= H1->currentSize;i++,j *= 2){
		T1 = H1->Trees[i];
		T2 = H2->Trees[i];
		switch(!!T1 + 2 * !!T2 + 4 * !!carry){
			case 0:/* û�ж����� */
					break;
            case 1:/* ֻ��H1 */
                    break;
            case 2:/* ֻ��H2 */
					H1->Trees[i] = T2;
					H2->Trees[i] = NULL;
					break;
			case 4:/* ֻ��carry */
					H1->Trees[i] = carry;
					carry = NULL;
					break;
			case 3:/* H1��H2 */
			        carry = combineTree(T1,T2);
			        H1->Trees[i] = H2->Trees[i] = NULL;
			        break;
			case 5:/* H1��carry */
                    carry = combineTree(T1,carry);
                    H1->Trees[i] = NULL;
                    break;
			case 6:/* H2��carry */
					carry = combineTree(T2,carry);
					H2->Trees[i] = NULL;
					break;
			case 7:/* H1��H2��carry���� */
					H1->Trees[i] = carry;
					carry = combineTree(T1,T2);
					H2->Trees[i] = NULL;
					break;
		}
	}
	return H1;
}

BinQueue *createQueue(int data[],int length){
	if(data == NULL) return;
	BinQueue *H1 = initQueue();
	BinQueue *H2 = initQueue();
	H1->Trees[0] = initTree(data[0]);
	H1->currentSize = 1;
	int i = 1;
	while(i < length){
		H2->Trees[0] = initTree(data[i]);
		H2->currentSize = 1;
		merge(H1,H2);
		i++;
	}
	return H1;
}

_Bool isEmpty(BinQueue *H){
	int i;
	for(i = 0;i < capacity;i++){
		if(H->Trees[i]) return 0;
	}
	return 1;
}

int deleteMin(BinQueue *H) {
	if(isEmpty(H)){
		printf("�������Ϊ�գ�");
		return -INF;
	}
	int i,j;
	int minIndex,min = INF;
	BinQueue *deletedQueue;
	BinTree *deletedTree,*root;
    for(i = 0;i < MAXSIZE;i++){
    	if(H->Trees[i] && H->Trees[i]->data < min){
			/* ������Сֵ */
			minIndex = i;
		}
	}
	min = H->Trees[minIndex]->data;
	/* �ͷ���С���ڵ� */
	deletedTree = H->Trees[minIndex];
	root = deletedTree;
	deletedTree = deletedTree->child;
	free(root);
	/* ��H->Tree[minIndex]�Ķ��������ӷ���deletedTree�� */
	deletedQueue = initQueue();
 	deletedQueue->currentSize = (1 << minIndex) - 1;//2��minIndex�η���1
 	for(j = minIndex - 1;j >= 0;j--){
		deletedQueue->Trees[j] = deletedTree;
		deletedTree = deletedTree->brother;
  		deletedQueue->Trees[j]->brother = NULL;
	}
	H->Trees[minIndex] = NULL;
	H->currentSize -= deletedQueue->currentSize + 1;
	merge(H,deletedQueue);
	return min;
}

int main(){
	int arr[10] = {23,43,12,9,37,84,20,77,59,62};
 	BinQueue *H = createQueue((int *)arr,10);
 	printf("����������У�\n");
 	traverseQueue(H);
 	deleteMin(H);
 	printf("ɾ����Сֵ��\n");
  	traverseQueue(H);
	return 0;
}

