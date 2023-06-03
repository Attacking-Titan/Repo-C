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
	int size;
}HashTable;

/* ���ַ������й�ϣ������һ����ϣֵ */
int hash(const char *key,int tableSize){
	unsigned int hashVal = 0;
	while(*key != '\0'){
		hashVal = (hashVal << 5) + *key++;
	}
	return hashVal % tableSize;
}

int reHash(int hash,HashTable *table){
	int i,index;
	index = hash;
	for(i = 1;(table->list)[index].key != NULL;i++){
		index += i * i;
		if(index >= table->tableSize){
			index %= table->tableSize;
		}
	}
	return index;
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
	table->size = 0;
	return table;
}

/* �ͷŹ�ϣ�� */
void destroyTable(HashTable *table){
	Node *list = table->list;
	int i;
	for(i = 0;i < table->tableSize;i++){
			Node* node_t = &list[i];
            /* �ͷŽڵ��key */
			Node *next = node_t->next;
            free(node_t->key);
			node_t = node_t->next;
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
	Node *pos = table->list;
	int i;
	for(i = 0;i < table->tableSize;i++){
		if(pos->key != NULL && strcmp(pos->key,key) == 0) return pos;
		pos = &(table->list)[i];
	}
	return NULL;
}

/* ��key���뵽��ϣ���� */
void insert(HashTable *table,char *key){
	if(table->size > table->tableSize * 0.5) printf("��ϣ��ռ䲻�㣡\n");
	Node *pos = find(table,key);//����key
	if(pos == NULL) {//û���ҵ�key
		int index = hash(key,table->tableSize);
  		Node *pos = &(table->list)[index];
		if(pos->key != NULL) pos = &(table->list)[reHash(index,table)];
		/* ����key */
		pos->key = (char *)malloc(sizeof(char) * getLength(key));//����洢key�Ŀռ�
        strcpy(pos->key,key);
        pos->size = getLength(key);
        table->size++;
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
		if(node->size > 0){
			printf("%s\n",node->key);
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
	insert(table,"caculate");
	insert(table,"nice");
	traverseTable(table);
	printf("����hello,world��%s\n",retrieve(find(table,"hello,world")));
	printf("����PHP��%s\n",retrieve(find(table,"PHP")));
 	destroyTable(table);
	return 0;
}

