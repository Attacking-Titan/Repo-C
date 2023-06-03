/*
	Name:�������ĺ�������ǵݹ��
	Copyright:�ӵ���
	Author:�ӵ���
	Date:21/03/23 16:5721/03/23 16:57
	Description:
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
	char data;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
	_Bool flag;
}TreeNode;

typedef struct stackNode{
	struct TreeNode *data;
	struct stackNode *next;
}stackNode;

stackNode *initStack(){
	stackNode *s = (stackNode *)malloc(sizeof(stackNode));
	s->data = NULL;
	s->next = NULL;
	return s;
}

_Bool isEmpty(stackNode *s){
	return s->next == NULL;
}

void push(TreeNode *T,stackNode *s){
	stackNode *node = (stackNode *)malloc(sizeof(stackNode));
	node->data = T;
	node->next = s->next;
	s->next = node;
}

stackNode *pop(stackNode *s){
	if(isEmpty(s)) return NULL;
	else {
		stackNode *node = s->next;
		s->next = node->next;
		return node;
	}
}

stackNode *getTop(stackNode *s){
	if(isEmpty(s)) return NULL;
	else {
		stackNode *node = s->next;
		return node;
	}
}

void createTree(TreeNode **T,char *data,int *index){
	char ch = data[(*index)++];
	if(ch == '#') *T = NULL;
	else {
		*T = (TreeNode *)malloc(sizeof(TreeNode));
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
		(*T)->data = ch;
		(*T)->flag = 0;
		createTree(&(*T)->lchild,data,index);
		createTree(&(*T)->rchild,data,index);
	}
}

void preOrder(TreeNode *T){
	if(T){
		printf("%c ",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

//�������ķǵݹ������������Ҹ�
//�Ӹ���㿪ʼ��һֱ����������������Ľ��ѹ��ջ�У�ֱ�����Ϊ��
//�ҵ�����ߵĽ��󣬻�ȡջ��Ԫ�أ������ջ�Ľ�����Һ�����δ�����ʹ�������ʸó�ջ�����Һ��ӣ�����ѹ��ջ�У�����Ƿ���
//�Գ�ջ�����Һ����ظ�ǰ��Ĳ�����ֱ�����Ϊ����ջ��Ԫ��û���Һ��ӻ����Һ��ӱ����ʹ��ˣ���ʱ��ջ�����������ջԪ�ص�����
//�ټ�����ȡջ��Ԫ�أ����ظ�ǰ�����Щ������ֱ�����Ϊ����ջΪ��
void postOrder(TreeNode* T){
	TreeNode* node = T;
	stackNode* S = initStack();
	while(node || !isEmpty(S)){//�����㲻Ϊ����ջ��Ϊ��
		if(node){
			push(node,S);//������ѹջ
			node = node->lchild;
		}
		else {//������Ϊ�ջ���ջ��
			TreeNode* top = getTop(S)->data;//��ȡջ��Ԫ��
			if(top->rchild && top->rchild->flag == 0){//������Һ������Һ���δ���ʹ�
				top = top->rchild;
				push(top,S);//���Һ���ѹ��ջ��
				node = top->lchild;//������������
			}
			else {
				top = pop(S)->data;//��ջ
				printf("%c ",top->data);
				top->flag = 1;//��ǳ�ջԪ��
			}//��ʱnode���ǿս�㣬ֱ����ջ�����к��ӵĽ��Ϊֹ
		}
	}
}

int main() {
	TreeNode *T;
	int index = 0;
	createTree(&T,"ABD#F##E##C##",&index);
	preOrder(T);
	putchar('\n');
	postOrder(T);
	return 0;
}


