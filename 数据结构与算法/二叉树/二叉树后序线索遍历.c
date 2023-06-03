#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	char data;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
	struct TreeNode *parent;
	int ltag;
	int rtag;
}TreeNode;

void createTree(TreeNode **T,char *data,int *index,TreeNode *parent){
	char ch = data[*index];
	*index += 1;
	if(ch == '#') *T = NULL;
	else {
		*T = (TreeNode *)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		(*T)->ltag = 0;
		(*T)->rtag = 0;
		(*T)->parent = parent;
		createTree(&(*T)->lchild,data,index,*T);
		createTree(&(*T)->rchild,data,index,*T);
	}
}

void postThreadTree(TreeNode *T,TreeNode **pre){
	//�����ǰ���ڵ㲻Ϊ��
	if(T){
		postThreadTree(T->lchild,pre);//����������������������������
		postThreadTree(T->rchild,pre);//����������������������������
		//�����ǰ��������Ϊ�գ�����ָ��ǰ��
		if(T->lchild == NULL){
			T->ltag =1;//��Ǹý�������Ϊ���
			T->lchild = *pre;//����ָ��ǰ��
		}
		//�����ǰ���ǰ����Ϊ����ǰ�����Һ���Ϊ��
		if(*pre != NULL && (*pre)->rchild == NULL){
			(*pre)->rtag =1;//��Ǹý����Һ���Ϊ���
			(*pre)->rchild = T;//�Һ���ָ����
		}
		//����ǰ�ĸ��ڵ㸳��ǰ��ָ��
		*pre = T;
	}
	//�����ָ��Ϊ�գ�����
	else return;
}

 //��ȡ��������Ҷ�ڵ�
TreeNode *getFirst(TreeNode *T){
	while(T->ltag == 0)
		T = T->lchild;//�ҵ�����ߵ��Ǹ�Ҷ�ڵ�
	if(T->rtag == 0) return getFirst(T->lchild);
	return T;
}

//������������Ҷ�ڵ�
TreeNode *getNext(TreeNode *node){
    if(node->rtag == 1) return node->rchild;//����к��
    else {
    	if(node->parent == NULL) return NULL;//����Ǹ��ڵ�
    	else if(node->parent->rchild == node){//������Һ���
    		return node->parent;
		}
		else {//���������
			if(node->parent->rtag == 0) return getFirst(node->parent->rchild);
				else return node->parent;
		}
	}
}

int main()
{
	TreeNode *T,*pre = NULL,*node;
	int index = 0;
	createTree(&T,"ABD#H###CF#I##G##",&index,NULL);
	postThreadTree(T,&pre);//��������������
	for(node = getFirst(T); node != NULL; node = getNext(node)){
		printf("%c ",node->data);
	}
	printf("\n");
	return 0;
}
