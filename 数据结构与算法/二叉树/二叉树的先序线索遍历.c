/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:21/03/23 20:0521/03/23 20:05
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


void preThreadTree(TreeNode *T,TreeNode **pre){
	//�����ǰ���ڵ㲻Ϊ��
	if(T){
		//�����ǰ��������Ϊ�գ�����ָ��ǰ��
		if(T->lchild == NULL){
			T->ltag = 1;//��Ǹý�������Ϊ���
			T->lchild = *pre;//����ָ��ǰ��
		}
		//�����ǰ���ǰ����Ϊ����ǰ�����Һ���Ϊ��
		if(*pre != NULL && (*pre)->rchild == NULL){
			(*pre)->rtag =1;//��Ǹý����Һ���Ϊ���
			(*pre)->rchild = T;//�Һ���ָ����
		}
		//����ǰ�ĸ��ڵ㸳��ǰ��ָ��
		*pre = T;
		if(T->ltag == 0) preThreadTree(T->lchild,pre);//����������������������������
		if(T->rtag == 0) preThreadTree(T->rchild,pre);//����������������������������
	}
}

TreeNode *getNext(TreeNode *node){
	if(node->ltag == 1 || node->rtag == 1)
	    return node->rchild;
	else
		return node->lchild;
	/*
	������Ĵ����
	if(node->rtag == 1) return node->rchild;
	else {
		if(node->ltag == 0) return node->lchild;
	    	else return node->rchild;
	}
	return node->lchild;
	*/
}

int main(){
	TreeNode *T,*pre = NULL,*node;
	int index = 0;
	createTree(&T,"ABD##E##CF##G##",&index);
	preThreadTree(T,&pre);//��������������
	pre -> rtag =1;
	pre -> rchild = NULL;
	for(node = T;node != NULL;node = getNext(node)){
		printf("%c ",node->data);
	}
	printf("\n");
	return 0;
}

