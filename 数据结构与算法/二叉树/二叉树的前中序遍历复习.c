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
	struct TreeNode *lchild;//����
	struct TreeNode *rchild;//�Һ���
}TreeNode;

typedef struct stackNode{
	TreeNode *data;//�������ĳ�����
	struct stackNode *next;//ָ��ջ����һ�ڵ�
}stackNode;

void createTree(TreeNode **T,char *data,int *index){
	char ch = data[*index];
	*index+=1;//ָ���ַ�����ָ��������һ
	if(ch == '#')*T = NULL;//����ַ�Ϊ#�����ָ��NULL
	else {
		*T = (TreeNode *)malloc(sizeof(TreeNode));//Ϊ����ĳ����㿪�ٿռ�
		(*T)->data = ch;//�����ݷ�����������
		createTree(&(*T)->lchild,data,index);//�ݹ鴴��������
		createTree(&(*T)->rchild,data,index);//�ݹ鴴��������
	}
}

stackNode *initStack(void){
	stackNode *S = (stackNode *)malloc(sizeof(stackNode));//Ϊջ��ͷ�����ٿռ�,�˿ռ䲻�������
	S->data = NULL;
	S->next = NULL;
	return S;
}

void makeEmpty(stackNode *S){
	stackNode* node = S;
	while(S){
		node = S->next;
		free(S);
		S = node;
	}
}

//������ѹջ
void push(TreeNode *T,stackNode *S){
	stackNode *node = (stackNode *)malloc(sizeof(stackNode));//Ϊջ�ڵ㿪�ٿռ�
	//ͷ�巨
	node->data = T;//�Ƚ����ݷ���ջ�ڵ����������
	node->next =  S->next;//��ջ�ڵ�ָ��ջͷ�ڵ�ָ�����һ�ڵ�
	S->next = node;//ջ��ͷ�ڵ��nextָ��ָ�����Ľڵ�
}

//�ж�ջ�Ƿ�Ϊ��
int isEmpty(stackNode *S){
	if(S->next == NULL)return 1;//���ջ��ͷ�ڵ�����һ�ڵ㣬ջΪ��
	else return 0;
}

//��ջ
stackNode *pop(stackNode *S){
	if(isEmpty(S))return NULL;//���Ϊ�գ����ؿ�ָ��
	else {
		stackNode *node = S->next;//ջָ��ָ��ͷ�ڵ����һ�ڵ�
		S->next = node->next;//ͷ�ڵ��nextָ��ָ����һ�ڵ����һ�ڵ�
		return node;//���س�ջ���Ǹ��ڵ�
	}
}

//�������ķǵݹ�ǰ�������������
//�Ӹ��ڵ㿪ʼ�����������ߣ����ν���Ϊ�յĽ��ѹջ����ѹջʱ����������ݣ�ֱ������Ϊ��
//����Ϊ��ʱ����ջ��ÿ��ջһ����㣬���������Һ��ӣ�
//���Һ����ظ�ǰ�������Ĳ�����ֱ��ջΪ���Ҵ�ʱ���ʵĽ��Ϊ��
void preOrder(TreeNode *T){
	TreeNode* node = T;
	stackNode* S = initStack();
	while(node || !isEmpty(S)){//����㲻Ϊ�ջ���ջ��Ϊ��ʱ��ִ��ǰ�����
		if(node){
			push(node,S);
			printf("%c ",node->data);
			node = node->lchild;//һֱ������
		}
        else{
			node = pop(S)->data;//��ջ
			node = node->rchild;//����ÿһ����ջԪ�ص��Һ���
		}
	}
}

//�������ķǵݹ���������������
//�Ӹ���㿪ʼ�����������ߣ����ν���Ϊ�յĽ��ѹջ��ֱ������Ϊ�գ���ʱ�ҵ�����ߵ��Ǹ����
//������Ϊ��ʱ����ջ��ÿ��ջһ����㣬����ó�ջ�������ݣ��ٷ��ʸó�ջ�����Һ���
//���Һ����ظ�ǰ��Ĳ�����ֱ��ջΪ���Ҵ�ʱ�����ʵĽ��Ϊ��
void inOrder(TreeNode *T){
	TreeNode* node = T;
	stackNode* S = initStack();
	while(node || !isEmpty(S)){
		if(node){
			push(node,S);
			node = node->lchild;
		}
		else {
			node = pop(S)->data;
			printf("%c ",node->data);
			node = node->rchild;//���ʳ�ջ�����Һ���
		}
	}
}
int main(){
	TreeNode *T;
	int index = 0;
	createTree(&T,"ABD##E##CF##G##",&index);//����������
	preOrder(T);//���������������
	printf("\n");
	inOrder(T);//���������������
	return 0;
}
