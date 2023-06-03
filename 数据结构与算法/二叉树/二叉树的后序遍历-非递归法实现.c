#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	char data;
	struct TreeNode *lchild;//����
	struct TreeNode *rchild;//�Һ���
	_Bool flag;
}TreeNode;

typedef struct stackNode{
	TreeNode *data;//�������ĳ�����
	struct stackNode *next;//ָ��ջ����һ�ڵ�
}stackNode;

stackNode *initStack(void){
	stackNode *S = (stackNode *)malloc(sizeof(stackNode));//Ϊջ��ͷ�����ٿռ�,�˿ռ䲻�������
	S->data = NULL;
	S->next = NULL;
	return S;
}

void makeEmpty(stackNode *S){
	stackNode* node;
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

stackNode *getTop(stackNode *S){
	if(isEmpty(S))return NULL;//���Ϊ�գ����ؿ�ָ��
	else {
		stackNode *node = S->next;//ջָ��ָ��ͷ�ڵ����һ�ڵ�
		return node;//���س�ջ���Ǹ��ڵ�
	}
}

void createTree(TreeNode **T,char *data,int *index){
	char ch = data[*index];
	*index+=1;//ָ���ַ�����ָ��������һ
	if(ch == '#')*T = NULL;//����ַ�Ϊ#�����ָ��NULL
	else {
		*T = (TreeNode *)malloc(sizeof(TreeNode));//Ϊ����ĳ����㿪�ٿռ�
		(*T)->data = ch;//�����ݷ�����������
		(*T)->flag = 0;
		createTree(&(*T)->lchild,data,index);//�ݹ鴴��������
		createTree(&(*T)->rchild,data,index);//�ݹ鴴��������
	}
}

void postOrder(TreeNode *T){
	TreeNode *node = T;
	stackNode *S = initStack();
	while(node || !isEmpty(S)) {
		if(node) {
			push(node,S);
			node = node->lchild;
		}
		else {
			TreeNode *top = getTop(S)->data;
			if(top->rchild && top->rchild->flag == 0){
				top = top->rchild;
				push(top,S);
				node = top->lchild;
			}
			else {
				top = pop(S)->data;
				printf("%c ",top->data);
				top->flag = 1;
			}
		}
	}
}
int main(){
	TreeNode *T;
	int index = 0;
	createTree(&T,"ABCDEFG",&index);
	postOrder(T);
	printf("\n");
	return 0;
}
