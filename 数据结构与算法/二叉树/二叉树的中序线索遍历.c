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

void preOrder(TreeNode *T){
	if(T == NULL)return;
	else {
		printf("%c ",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

void inThreadTree(TreeNode *T,TreeNode **pre){
	//�����ǰ���ڵ㲻Ϊ�� 
	if(T){
		inThreadTree(T->lchild,pre);//����������������������������
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
		inThreadTree(T->rchild,pre);//����������������������������
	}
	//�����ָ��Ϊ�գ����� 
	else return; 
}
 
 //��ȡ��������Ҷ�ڵ� 
TreeNode *getFirst(TreeNode *T){
	while(T->ltag == 0)
		T = T->lchild;//�ҵ�����ߵ��Ǹ�Ҷ�ڵ�
	return T;
}

//������������Ҷ�ڵ� 
TreeNode *getNext(TreeNode *node){
	//����ý��ΪҶ�ڵ㣬�������Һ�����ָ�ĵ�ַ 
	if(node -> rtag == 1)
		return node -> rchild;
	//����ý�㲻ΪҶ�ڵ㣬�������Һ��ӵ�����ߵ�Ҷ�ڵ�
	else return getFirst(node -> rchild); 
}

int main()
{
	TreeNode *T,*pre = NULL,*node;
	int index = 0;
	createTree(&T,"ABD##E##CF##G##",&index);
	preOrder(T);
	printf("\n");
	inThreadTree(T,&pre);//�������������� 
	pre -> rtag =1;
	pre -> rchild = NULL;
	for(node = getFirst(T); node != NULL; node = getNext(node)){
		printf("%c ",node->data);
	}
	printf("\n");
	return 0;
}
