#include<stdio.h>
#include<time.h>
#define MAXSIZE 200
#define dataType int
#define list int
#define node int
#define null 0
struct Space{
	int data;
	int next;//ÿһ��nextָ��һ����ַ
}space[MAXSIZE];

void showSpace(){
	int i;
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - -");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("space:\n");
	for(i = null;i < MAXSIZE;i++){
		printf("%3d->%3d  ",i,space[i].next);
		if((i+1)%10 == null) putchar('\n');
	}
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - -");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - -\n");
}

void initCursorSpace(){
	int i;
	for(i = null;i < MAXSIZE;i++){
		space[i].data = null;
		space[i].next = i + 1;
	}
	space[MAXSIZE-1].next = null;
	space[MAXSIZE-1].data = 0;
}//�α�null�ȼ��ڿ�ָ�룬��ʼ���ռ�������ʵ��������α�ʵ��

int spaceAlloc(){
	int p;
	p = space[null].next;//�����α�
	space[null].next = space[p].next;//�α�nullָ���´�������α�
	printf(">> �����ַ%d�ɹ����´η����ַΪ%d\n",p,space[null].next);
	return p;
}//�α����,ʵ��malloc(),����������ƣ�ͨ���α�null������ռ�

void spaceFree(int p){
	printf("<< ԭ��ַ%d���ͷź�ָ��%d,�´η����ַ%d\n",p,space[null].next,p);
	space[p].next = space[null].next;//p�α�ָ��Ŀռ�����δ����Ŀռ���
	space[null].next = p;//��Ҫ�ͷŵĿռ���뵽δ����Ŀռ��ͷ������null���α���ָ���´���������Ŀռ�
}//ʵ��free(),ͷ�巨����Ҫfree���α���ָ�ռ���뵽δ����Ŀռ��ͷ��

list createList(){
	if(isFull()) return null;
	list L = spaceAlloc();
	space[L].data = null;
	space[L].next = null;
	return L;
}

int isEmpty(list L){
	return space[L].next == null;
}

int isLast(node p,list L){
	return space[p].next == null;
}

int isFull(){
	return space[null].next == null;
}
node find(dataType data,list L){
	int p;
	p = space[L].next;
	while(p && space[p].data != data)
		p = space[p].next;
	return p;
}

node getPre(dataType data,list L){
	node t = L;
	while(t!=null){
		if(space[space[t].next].data == data)
			break;
		t = space[t].next;
	}
	return t;
}

void deleteNode(dataType data,list L){
	node p,t;
	p = getPre(data,L);
	if(p == null) {
		printf("ɾ�����ʧ�ܣ���Ҫɾ��������%d\n",data);
		return;
	}
	printf("ɾ����㣬��ַ%d,����%d\n",space[space[p].next].next,space[space[p].next].data);
	if(!isLast(p,L)){
		t = space[p].next;
		space[p].next = space[t].next;
		spaceFree(t);
		space[L].data--;
	}
}

node insert(dataType data,list L,node p){
	node t;
	t = spaceAlloc();
	if(t == null) {
		printf("Out of space!!!\n");
		return null;
	}
	space[t].data = data;
	space[t].next = space[p].next;
	space[p].next = t;
	space[L].data++;
	printf("�����㣬��ַ%d,����%d\n",p,space[p].data);
	return space[p].next;
}

void traverseList(list L){
	int cnt = null;
	node p = space[L].next;
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("�����й���%d�����:\n",space[L].data);
	while(p != null){
		printf("%3d(%d) -> ",space[p].data,p);
		p = space[p].next;
		cnt++;
		if(cnt % 10 == null) putchar('\n');
	}
	printf("NULL\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
}

int main(){
	void showSpace();
	void initCursorSpace();
	int cursorAlloc();
	void spaceFree(int p);
	list createList();
	int isEmpty(list L);
	int isLast(node p,list L);
	int isFull();
	node find(dataType data,list L);
	node getPre(node p,list L);
	void deleteNode(dataType data,list L);
	node insert(dataType data,list L,node p);
	void traverseList(list L);
	
 	initCursorSpace();
 	int i,d = null;
 	int Delete[20];
	list L = createList();
	node p;
	showSpace();
	printf("isEmpty(L):%s\n",isEmpty(L) ? "true" : "false");
	printf("isLast(L):%s\n",isLast(L,L) ? "true" : "false");
	insert(999,L,L);
	p = L;
	srand(time(NULL));
    for(i = null;i < 15;i++){
		p = insert(rand() % 1000,L,p);
		if(i % 3 == null) Delete[d++] = p;
	}
	insert(998,L,p);
	insert(997,L,find(998,L));
	insert(996,L,find(999,L));
	insert(995,L,find(999,L));
	insert(994,L,find(997,L));
	traverseList(L);
	srand((time_t)rand());
	for(i = null;i < d;i++){
		deleteNode(space[Delete[i]].data,L);
 	}
 	deleteNode(100,L);
 	deleteNode(200,L);
 	deleteNode(300,L);
 	deleteNode(400,L);
 	deleteNode(500,L);
 	deleteNode(600,L);
 	deleteNode(999,L);
 	for(i = null;i < 15;i++){
		p = insert(rand() % 1000,L,p);
		insert(rand() % 1000,L,p);
		if(i % 3 == null) Delete[d++] = p;
	}
	printf("isFull():%s\n",isFull(L) ? "true" : "false");
	traverseList(L);
	showSpace();
	return null;
}
