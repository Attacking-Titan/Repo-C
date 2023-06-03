/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:
	Description:
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	char data;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
	int ltag;
	int rtag;
}TreeNode;

void createTree(TreeNode **T,char *data,int *index){
	char ch = data[*index];
	*index += 1;
	if(ch == '#') *T = NULL;
	else {
		*T = (TreeNode *)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		(*T)->ltag = 0;
		(*T)->rtag = 0;
		createTree(&(*T)->lchild,data,index);
		createTree(&(*T)->rchild,data,index);
	}
}

//�������������������������������
//�������������˳��������ö�����
//�ڱ����������Ĺ��̣����յ�����ָ��ýڵ��ǰ�����յ��Һ���ָ��ýڵ�ĺ��
void preThreadTree(TreeNode* T,TreeNode** pre){
	//�����������ٵݹ�����������
	if(T){
		if(T->lchild == NULL) {
			T->lchild = *pre;
			T->ltag = 1;
		}
		if(*pre != NULL && (*pre)->rchild == NULL) {
			(*pre)->rchild = T;
			(*pre)->rtag = 1;
		}
		*pre = T;
		//�ݹ����
		if(T->ltag == 0) preThreadTree(T->lchild,pre);
		if(T->rtag == 0) preThreadTree(T->rchild,pre);
	}
}

TreeNode* getNext(TreeNode* node){
	//����к�̣����غ��
	if(node->rtag == 1) return node->rchild;
	else{//û�к��
		if(node->ltag == 0) return node->lchild;//��������
		    else return node->rchild;//�����Һ���
	}
}
int main(){
	int index = 0;
	TreeNode *T,*pre = NULL,*node;
	createTree(&T,"ABD#G##E##C#FH###",&index);
	preThreadTree(T,&pre);
	pre->rtag = 1;
	pre->rchild = NULL;
	for(node = T;node != NULL;node = getNext(node)){
		printf("%c ",node->data);
	}
	printf("\n");
	return 0;
}

