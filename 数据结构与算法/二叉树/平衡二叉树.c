#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
	int data;
	int height;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

int getHeight(TreeNode *node){
	return node ? node->height : 0;
}

int max(int a,int b){
	return a > b ? a : b;
}

void rrRotation(TreeNode *node,TreeNode** root){
	TreeNode *temp = node->rchild;
	node->rchild = temp->lchild;
	temp->lchild = node;
	node->height = max( getHeight(node->lchild),getHeight(node->rchild) ) + 1;
	temp->height = max( getHeight(temp->lchild),getHeight(temp->rchild) ) + 1;
	*root = temp;
}

void llRotation(TreeNode* node,TreeNode** root){
	TreeNode* temp = node->lchild;
	node->lchild = temp->rchild;
	temp->rchild = node;
	node->height = max( getHeight(node->lchild),getHeight(node->rchild) ) + 1;
	temp->height = max( getHeight(temp->lchild),getHeight(temp->rchild) ) + 1;
	*root = temp;
}

void AVLInsert(TreeNode** T,int data){
 	if(*T == NULL){
		*T = (TreeNode *)malloc(sizeof(TreeNode));
		(*T)->data = data;
		(*T)->height = 0;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
	}
	else if(data < (*T)->data) {
  		AVLInsert(&(*T) -> lchild, data);
        // �õ���ǰ�ڵ����������ĸ߶�
        int lHeight = getHeight((*T)->lchild);
        int rHeight = getHeight((*T)->rchild);
        // �жϸ߶Ȳ�
        if (lHeight - rHeight == 2) {
            if ((*T)->lchild && data < (*T)->lchild->data) {
                // LL ����
                llRotation(*T, T);
            }
            else {
                // LR ����
                rrRotation((*T)->lchild, &(*T)->lchild);
                llRotation(*T, T);
            }
		}
	}
	else if(data > (*T)->data){
		AVLInsert(&(*T)->rchild,data);
		//�õ���ǰ�ڵ����������ĸ߶�
		int lHeight = getHeight((*T)->lchild);
		int rHeight = getHeight((*T)->rchild);
		//�жϸ߶Ȳ�
		if(rHeight - lHeight == 2){
			if((*T)->rchild && data > (*T)->rchild->data){
        		//RR����
        		rrRotation(*T,T);
			}
			else {
				//RL����
				llRotation((*T)->rchild,&(*T)->rchild);
				rrRotation(*T,T);
			}
		}
	}
	//���¸߶�
	(*T)->height = max( getHeight((*T)->lchild),getHeight((*T)->rchild) ) + 1;
}

void preOrder(TreeNode *T,TreeNode *father,_Bool flag){
	if(T){
		if(father != NULL)
		printf("%d(%d_%s) height:%d\n",T->data,father->data,flag ? "��" : "��",T->height);
		else printf("%d(NULL) height:%d\n",T->data,T->height);
		preOrder(T->lchild,T,1);
		preOrder(T->rchild,T,0);
	}
}

int main(){
	TreeNode *T = NULL;
	int num[10] = {7,2,10,14,5,6,3,1,20,8};
	int i;
	for(i = 0;i < 10;i++){
		AVLInsert(&T,num[i]);
	}
	preOrder(T,NULL,0);
	return 0;
}

