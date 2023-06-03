/*
	��ʽ�ѣ��ݹ鶨�壬��ṹ����������ƣ�������ʽ���ǲ�ƽ��Ķ�����
	Npl(��) >= Npl(��)
	�������ڵ���ʽ�Ѻϲ����Եõ���ʽ�ѣ��������ƣ�����ͨ���ݹ�ĺϲ��õ���ʽ��
    ��˺ϲ���ʽ��Ҳ�ǵݹ鶨�壬
	��κϲ�������ʽ�ѣ�
    �Ƚ����и�ֲ��С����ʽ�ѵ����ӶѺ͸�ֲ�ϴ����ʽ�Ѻϲ��õ��µ���ʽ�ѣ�
	�ٽ������ʽ�Ѻ�ԭ���Ǹ���ֲ��С����ʽ�ѵ����ӶѺϲ�
	�ϲ��õ�����ʽ�����Npl(��) < Npl(��)����ô���������Ӷ�
 */
#include<stdio.h>
#include<stdlib.h>
#include "leftHeap_H.h"

struct TreeNode{
	int data;
	int Npl;//��·����
	struct TreeNode *left;//���Ӷ�
	struct TreeNode *right;//���Ӷ�
};

void traverseQueue(priorityQueue *Q,priorityQueue *father,int flag){
	if(father)	printf("%d(%d_%s) Npl:%d\n",Q->data,father->data,flag ? "��" : "��",Q->Npl);
	else printf("%d(null) Npl:%d\n",Q->data,Q->Npl);
 	if(Q->left)
		traverseQueue(Q->left,Q,1);
	if(Q->right)
		traverseQueue(Q->right,Q,0);
}

priorityQueue *initHeap(int data){
	Heap *H = (Heap *)malloc(sizeof(Heap));
	H->data = data;
	H->Npl = 0;
	H->left = NULL;
	H->right = NULL;
	return H;
}

/* �ϲ�H1��H2���������� */
priorityQueue *merge(priorityQueue *H1,priorityQueue *H2){
	/* �ݹ���ֹ���� */
    if(H1 == NULL)
		return H2;
	if(H2 == NULL)
		return H1;
	/* �����ݹ�ϲ� */
	if(H1->data > H2->data)//��H1ת���ɸ�ֲС���Ǹ�
	    return merge1(H2,H1);
	else
		return merge1(H1,H2);
}

/* �ڴ˺����У�H1�ĸ�ֲС��H2 */
priorityQueue *merge1(priorityQueue *H1,priorityQueue *H2){
	/* �ϲ���ֹ���� */
	if(H1->left == NULL)//H1Ϊ���ڵ�
		H1->left = H2;
	/* �����ݹ�ϲ� */
    else{
		H1->right = merge(H1->right,H2);
		if(H1->left->Npl < H1->right->Npl){
			/* ���������Ӷ� */
			Heap *H = H1->left;
			H1->left = H1->right;
			H1->right = H;
		}
		H1->Npl = H1->right->Npl + 1;//����Npl
	}
	return H1;
}

priorityQueue *insert(int data,priorityQueue *H){
	return merge(initHeap(data),H);
}

priorityQueue *deleteMin(priorityQueue *H){
 	priorityQueue *left,*right;
 	left = H->left;
 	right = H->right;
 	free(H);
	return merge(left,right);
}

int main(){
	//int arr[10] = {12,34,8,29,57,88,21,70,36,96};
	int arr[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	printf("������ʽ�ѣ�\n");
 	priorityQueue *H = NULL;
	int i;
	for(i = 0;i < 15;i++){
		H = insert(arr[i],H);
	}
	traverseQueue(H,NULL,1);
	printf("ɾ����СԪ��\n");
	H = deleteMin(H);
	traverseQueue(H,NULL,1);
	return 0;
}

