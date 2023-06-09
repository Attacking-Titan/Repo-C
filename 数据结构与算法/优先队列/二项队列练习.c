#include<stdio.h>
#include<stdlib.h>
#define INF 0x7fffffff
#define MAXSIZE 5

struct BinNode{
	int data;
	struct BinNode *child;//第一个儿子
	struct BinNode *brother;//兄弟
};
typedef struct BinNode BinTree;

struct Collection{
	int currentSize;//记录当前队列中树的总节点数
	BinTree *Trees[MAXSIZE];//用一维数组顺序的存储二项树的根节点
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
	/* 初始化二项树 */
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
			printf("B%d：\n",i);
			preOrder(H->Trees[i],NULL);
			putchar('\n');
		}
	}
}

/* 合并两棵二项树，T2变成T1的儿子 */
BinTree *combineTree(BinTree *T1,BinTree *T2){
	if(T1->data > T2->data)
		return combineTree(T2,T1);
	T2->brother = T1->child;
	T1->child = T2;
	return T1;
}

/* 合并两个二项队列 */
BinQueue *merge(BinQueue *H1,BinQueue *H2)//返回H1
{
	if(H1->currentSize + H2->currentSize > capacity)
		printf("合并将会超出容量");
	BinTree *T1,*T2,*carry = NULL;
	H1->currentSize += H2->currentSize;
	int i,j;
	for(i = 0,j = 1;j <= H1->currentSize;i++,j = j << 1){
		T1 = H1->Trees[i];
		T2 = H2->Trees[i];
		switch(!!T1 + 2 * !!T2 + 4 * !!carry) {
			case 0:
				/* T1、T2、carry均为空*/
				break;
			case 1:
				/* 只有T1 */
				break;
			case 2:
				/* 只有T2 */
				H1->Trees[i] = T2;
				H2->Trees[i] = NULL;
				break;
			case 3:
				/* T1和T2 */
				carry = combineTree(T1,T2);
				H1->Trees[i] = NULL;
				H2->Trees[i] = NULL;
				break;
			case 4:
				/* 只有carry */
				H1->Trees[i] = carry;
				carry = NULL;
				break;
			case 5:
				/* T1和carry */
				carry = combineTree(T1,carry);
				H1->Trees[i] = NULL;
				break;
			case 6:
				/* T2和carry */
				carry = combineTree(T2,carry);
				H2->Trees[i] = NULL;
				break;
			case 7:
				/* T1、T2、carry均有 */
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

int deleteMin(BinQueue *H){
	if(isEmpty(H)) {
		printf("二项队列为空！");
		return -INF;
	}
	/* 获取最小值及其所在二项树的索引 */
	int i;
	int minIndex,min = INF;
	for(i = 0;i < MAXSIZE;i++){
		if(H->Trees[i] && H->Trees[i]->data < min) {
			minIndex = i;
		}
	}
	min = H->Trees[minIndex]->data;
	/* 释放最小值 */
	BinTree *root = H->Trees[minIndex];
	BinTree *deletedTree = H->Trees[minIndex]->child;
	free(root);
	/* 将删除的二项树放入deleteQueue中 */
	BinQueue *deletedQueue = initQueue();
	deletedQueue->currentSize = 1 << minIndex - 1;
	for(i = minIndex - 1;i >= 0;i--){
			deletedQueue->Trees[i] = deletedTree;
			deletedTree = deletedTree->brother;
			deletedQueue->Trees[i]->brother = NULL;
	}
	H->Trees[minIndex] = NULL;
	H->currentSize -= deletedQueue->currentSize + 1;
	merge(H,deletedQueue);
	return min;
}

int main(){
	int arr[10] = {23,43,12,9,37,84,20,77,59,62};
 	BinQueue *H = createQueue((int *)arr,10);
 	printf("创建二项队列：\n");
 	traverseQueue(H);
 	deleteMin(H);
 	printf("删除最小值：\n");
  	traverseQueue(H);
	return 0;
}

