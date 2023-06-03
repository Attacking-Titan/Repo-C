#include<stdio.h>
#include<stdlib.h>

/*
*   ƽ��������Ķ��壺���������ĸ߶Ȳ����1�Ķ�����������
*   ������������ڶ������У�������ڵ�X��X�����ӵ�ֵС��X��ֵ��X���Һ��ӵ�ֵ����X��ֵ
*/
struct TreeNode{
	int data;
	int height;//�ڵ�ĸ߶�Ϊ�Ըýڵ�Ϊ���ڵ�����ĸ߶ȣ��涨�սڵ�ĸ߶�Ϊ-1
	struct TreeNode* lchild;
	struct TreeNode* rchild;
};
typedef struct TreeNode AVLTree;

void preOrder(AVLTree *T,AVLTree *father,_Bool flag){
	if(T){
		if(father != NULL)
		printf("%d(%d_%s) height:%d\n",T->data,father->data,flag ? "��" : "��",T->height);
		else printf("%d(NULL) height:%d\n",T->data,T->height);
		preOrder(T->lchild,T,1);
		preOrder(T->rchild,T,0);
	}
}

int max(int a,int b){
	return a > b ? a : b;
}

int getHeight(AVLTree *T){
	return T ? T->height : 0;//���T��Ϊ�շ��ظýڵ�ĸ߶ȣ����򷵻�0
}

/* �����������ڵ���ת�������ӵ��Һ��ӵ�λ�� */
void llRotation(AVLTree **T){
	struct TreeNode *root = *T;//��Ҫ������AVL���ĸ��ڵ�
	struct TreeNode *lchild = root->lchild;//���ڵ������
	struct TreeNode *grandson = lchild->rchild;//���ڵ�����ӵ��Һ���
	root->lchild = grandson;
	lchild->rchild = root;
	/* �������ϸ��¸߶ȣ�������rootΪlchild���Һ���*/
	root->height = getHeight(root->lchild) + 1;
	lchild->height = getHeight(lchild->rchild) + 1;
	*T = lchild;//���¸��ڵ�
}

/* ����,�����ڵ���ת�����Һ��ӵ�����λ�� */
void rrRotation(AVLTree **T){
	struct TreeNode *root = *T;//��Ҫ������AVL���ĸ��ڵ�
	struct TreeNode *rchild = root->rchild;//���ڵ���Һ���
	struct TreeNode *grandson = rchild->lchild;//���ڵ���Һ��ӵ�����
	root->rchild = grandson;
	rchild->lchild = root;
	/* �������ϸ��¸߶ȣ�������rootΪrchild������ */
	root->height = getHeight(root->rchild) + 1;
	rchild->height = getHeight(rchild->lchild) + 1;
	*T = rchild;//���¸��ڵ�
}

void AVLInsert(AVLTree **T,int data){
	if(*T == NULL)//�ݹ�������ڴ˽ڵ�����½ڵ�
	{
		*T = (struct TreeNode *)malloc(sizeof(struct TreeNode));
		(*T)->data = data;
		(*T)->height = 0;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
	}//�����ڵ�
	else {
		if(data < (*T)->data) {
			AVLInsert(&(*T)->lchild,data);//���������ݹ�
			/* ����֮ǰT�����Ľڵ㣬���Ըýڵ�Ϊ���������е��� */
			int lHeight = getHeight((*T)->lchild);
			int rHeight = getHeight((*T)->rchild);
			if(lHeight - rHeight == 2){
				/* LL */
				if((*T)->lchild && data < (*T)->lchild->data)
					llRotation(T);
				/* LR */
				else {
					rrRotation(&(*T)->lchild);
					llRotation(T);
				}
			}
		}
		else if(data > (*T)->data) {
			AVLInsert(&(*T)->rchild,data);//���������ݹ�
			/* ����֮ǰT�����Ľڵ㣬���Ըýڵ�Ϊ���������е��� */
			int lHeight = getHeight((*T)->lchild);
			int rHeight = getHeight((*T)->rchild);
			if(rHeight - lHeight == 2){
				/* RR */
				if((*T)->rchild && data > (*T)->rchild->data)
					rrRotation(T);
				/* RL */
				else {
					llRotation(&(*T)->rchild);
					rrRotation(T);
				}
			}
		}
  		/*
		* else{}
		* ���data == (*T)->data,˵��data��AVL�����Ѿ�����
		* �򲻽��в��룬��ΪAVL���������ظ�������
		*/
	}
 	/* ���½ڵ�ĸ߶� */
	(*T)->height = max(getHeight((*T)->lchild),getHeight((*T)->rchild)) + 1;
}

int main(){
	int arr[10] = {7,2,10,14,5,6,3,1,20,8};
	AVLTree *T = NULL;
	int i;
	for(i = 0;i < 10;i++)
		AVLInsert(&T,arr[i]);
	preOrder(T,NULL,0);
	return 0;
}
