#include<stdio.h>
#include<stdlib.h>
#define INF 0x7fffffff//int���ֵ��ʮ�����Ʊ�ʾ
typedef struct TreeNode{
	int weight;//Ȩ��
	int parent;//���ڵ�
	int lchild;//����
	int rchild;//�Һ���
}TreeNode;

typedef struct HFTree{
	TreeNode *data;//��һ��˳��Ķ������Ľṹ���������洢��������
	int length;//��¼���������еĽڵ�����
}HFTree;

HFTree* initTree(int *weight,int length){
	HFTree* T = (HFTree *)malloc(sizeof(HFTree));//����һ�ù�������
	T->data = (TreeNode *)malloc(sizeof(TreeNode) * (2 * length - 1));//�������ݵĿռ�
	T->length = length;
	int i;
	for(i = 0;i < length;i++){
		T->data[i].weight = weight[i];
		T->data[i].parent = 0;
		T->data[i].lchild = -1;
		T->data[i].rchild = -1;
	}
	return T;
}

int *selectMin(HFTree* T){
	int min = INF;
	int secondMin = INF;
	int minIndex;
	int secondIndex;
	int i;
	for(i = 0;i < T->length;i++){
		if(T->data[i].parent == 0) {//����ǻ�δ�����齨���������Ľڵ�
			if(T->data[i].weight < min){
				min = T->data[i].weight;
				minIndex = i;
			}
		}
	}
	for(i = 0;i < T->length;i++){
		if(T->data[i].parent == 0 && i != minIndex) {//����ǻ�δ�����齨���������Ľڵ�
			if(T->data[i].weight < secondMin){
				secondMin = T->data[i].weight;
				secondIndex = i;
			}
		}
	}
	int *res = (int *)malloc(sizeof(int) * 2);//��һ����������������Ȩֵ��С���±�
	res[0] = minIndex;
	res[1] = secondIndex;
    return res;
}

void createHFTree(HFTree *T){
	int *res;
	int min;
	int secondMin;
	int length = T->length * 2 - 1;//���Ȩֵ�б���length��Ԫ�أ���ô���յĹ���������2*length - 1���ڵ�
	int i;
	for(i = T->length;i < length;i++){
		res = selectMin(T);
		min = res[0];
		secondMin = res[1];
		T->data[i].weight = T->data[min].weight + T->data[secondMin].weight;
		T->data[i].lchild = min;
		T->data[i].rchild = secondMin;
		T->data[i].parent = 0;
		T->data[min].parent = i;
		T->data[secondMin].parent = i;
		T->length++;//�ڵ�����һ,ÿ�β������µĽڵ����T->data[T->length]��
	}
}

void preOrder(HFTree *T,int index){
	if(index != -1){
		printf("%d ",T->data[index].weight);
		preOrder(T,T->data[index].lchild);
		preOrder(T,T->data[index].rchild);
	}
}
int main(){
	int weight[7] = {5,9,2,7,6,4,10};
	HFTree *T = initTree(weight,7);
	createHFTree(T);
	preOrder(T,T->length - 1);
	printf("\n");
	return 0;
}

