#include<stdio.h>
#include<stdlib.h>
#include "_LeftHeap_H.h"

struct TreeNode{
	int data;
	struct TreeNode *left;//���
	struct TreeNode *right;//�Ҷ�
	int Npl;//��·����
};

int findMin(priorityQueue *H){
	return H->data;
}

/* �ϲ���ʽ�ѵ��������� */
priorityQueue *merge(priorityQueue *H1,priorityQueue *H2){
	if(H1 == NULL)
		return H2;
	if(H2 == NULL)
		return H1;
	if(H1->data > H2->data)//��H1ת���ɸ�ֲС���Ǹ�
	    return merge1(H2,H1);
	else
		return merge1(H1,H2);
}

/* �ϲ���ʽ�ѵ�ʵ������ */
priorityQueue *merge1(priorityQueue *H1,priorityQueue *H2)//H1�ĸ�ֵС��H2�ĸ�ֲ
{
	if(H1->left == NULL)//���ڵ�
		H1->left = H2;//H1->rightҲΪ�գ�H1->NplΪ0
	else {
		/* ��H1�����ӶѺ�H2�ϲ�����ΪH1���ڵ���Һ��� */
		H1->right = merge(H1->right,H2);
		if(H1->left->Npl < H1->right->Npl){
			struct TreeNode *node = H1->left;
			H1->left = H1->right;
			H1->right = node;
		}
		H1->Npl = H1->right->Npl + 1;//�µ���·�������µ��Ҷ��ӵ���·������1
	}
	return H1;
}

priorityQueue *insert(int data,priorityQueue *H){
	struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	node->data = data;
	node->Npl = 0;
	node->left = node->right = NULL;
	H = merge(node,H);
	return H;
}

priorityQueue *deleteMin(priorityQueue *H){
	if(H != NULL){
		priorityQueue *leftHeap,*rightHeap;
		leftHeap = H->left;
		rightHeap = H->right;
		free(H);
		return merge(leftHeap,rightHeap);
	}
}

void traverseHeap(priorityQueue *H){
	if(H == NULL) return;
	else {
		printf("%d ",H->data);
		if(H->left) traverseHeap(H->left);
		if(H->right) traverseHeap(H->right);
	}
}

int main(){
	//int arr[10] = {12,34,8,29,57,88,21,70,36,96};
	int arr[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
 	priorityQueue *H = NULL;
	int i;
	for(i = 0;i < 15;i++){
		H = insert(arr[i],H);
	}
	traverseHeap(H);
	return 0;
}

