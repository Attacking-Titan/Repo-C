/*
    �������ӷ�����key����hash���������õ���hashλ��Ϊ�գ�ֱ�ӽ�key����
    ����������õ�hashλ�������ݣ�������뵽�����ݵĺ��棬�ɴ��γ�������
    �ڷ������ӷ��У�hashֵ��ͬ���ַ��������ͬһ�ű���
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
	char* key;
	int size;//key�Ĵ�С
	struct Node *next;
}Node;

typedef struct HashTable{
	struct Node *list;
	int tableSize;
}HashTable;

/* ���ַ������й�ϣ������һ����ϣֵ */
int hash(const char *key,int tableSize){
	unsigned int hashVal = 0;
	while(*key != '\0'){
		hashVal = (hashVal << 5) + *key++;
	}
	return hashVal % tableSize;
}

/* ��ʼ����ϣ�� */
HashTable *initTable(int tableSize){
	HashTable *table = (HashTable *)malloc(sizeof(HashTable));
	table->list = (Node *)malloc(sizeof(Node) * tableSize);
	int i;
	for(i = 0;i < tableSize;i++){
		(table->list)[i].key = NULL;
		(table->list)[i].size = 0;
		(table->list)[i].next = NULL;
	}
	table->tableSize = tableSize;
	return table;
}

/* �ͷŹ�ϣ�� */
void destroyTable(HashTable *table){
	Node *list = table->list;
	int i;
	for(i = 0;i < table->tableSize;i++){
		Node* node_t = &list[i];
		while(node_t != NULL){
            /* �ͷŽڵ��key */
            if(node_t->size > 0) {
            	free(node_t->key);
			}
			node_t = node_t->next;
		}
	}
	free(list);
	free(table);
}

/* ��ȡ�ַ����ĳ��� */
int getLength(char *str){
	int i = 0;
	int length = 0;
	while(str[i++] != '\0'){
		length++;
	}
	return length;
}

/* ����key�Ƿ��ڹ�ϣ���У�������ڷ���NULL */
Node *find(HashTable* table,char *key){
	Node* pos = &(table->list)[hash(key,table->tableSize)];//��ȡkey��hash���λ��
	/* ����posλ�����ڵı� */
	Node* node_t = pos;
 	while(node_t->key != NULL){
		if(strcmp(node_t->key,key) == 0) return pos;
		node_t = node_t->next;
	}
	return NULL;
}

/* ��key���뵽��ϣ���� */
void insert(HashTable *table,char *key){
	Node *pos = find(table,key);//����key
	if(pos == NULL) {//û���ҵ�key
  		Node *pos = &(table->list)[hash(key,table->tableSize)];
		if(pos->next == NULL){
			pos->key = (char *)malloc(sizeof(char) * getLength(key));//����洢key�Ŀռ�
            strcpy(pos->key,key);
            pos->size = getLength(key);
		}
		else{
			Node *newCell = (Node *)malloc(sizeof(Node));
			newCell->size = getLength(key);
			newCell->key = (char *)malloc(sizeof(char) * newCell->size);//����洢key�Ŀռ�
			strcpy(newCell->key,key);//����key
			/* ͷ�巨 */
			newCell->next = pos->next;
			pos->next = newCell;
		}
	}
	else
		return;//���key�Ѿ����ڹ�ϣ���У�����Ҫ�ٴβ���key
}

/* ������ϣ�� */
void traverseTable(HashTable *table){
	int i;
	Node *list = table->list;
	for(i = 0;i < table->tableSize;i++){
		Node *node = &list[i];
		Node* node_t = node;
		if(node->size > 0){
			while(node_t != NULL){
				printf("%s\n",node_t->key);
				node_t = node_t->next;
			}
		}
	}
}

/* ���� */
char* retrieve(Node *node){
	return node->key;
}

int main(){
	HashTable* table = initTable(10);
	insert(table,"C++");
	insert(table,"Python");
	insert(table,"Java");
	insert(table,"PHP");
	insert(table,"Rust");
	insert(table,"hello,world");
	insert(table,"recursive");
	traverseTable(table);
	printf("����hello,world��%s\n",retrieve(find(table,"hello,world")));
	printf("����PHP��%s\n",retrieve(find(table,"PHP")));
 	destroyTable(table);
	return 0;
}

