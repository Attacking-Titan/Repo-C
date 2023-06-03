#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5//���е��������

typedef struct Graph {
    char* vexs;//���
    int** arcs;//��
    int vexNum;//�����
    int arcNum;//����
}Graph;

typedef struct Queue {
    int front;
    int rear;
    int data[MAXSIZE];
}Queue;

Queue* initQueue() {
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->front = Q->rear = 0;
    return Q;
}

int isFull(Queue* Q) {
   return (Q->rear + 1) % MAXSIZE == Q->front;
}

int isEmpty(Queue* Q) {
	return Q->front == Q->rear;
}

int enQueue(Queue* Q, int data) {
    if (isFull(Q)) {
        return 0;
    }
    else {
        Q->data[Q->rear] = data;
        Q->rear = (Q->rear + 1) % MAXSIZE;
        return 1;
    }
}

int deQueue(Queue* Q) {
    if(isEmpty(Q)) {
        return -1;
    }
    else {
        int data = Q->data[Q->front];
        Q->front = (Q->front + 1) % MAXSIZE;
        return data;
    }
}

/* �����㣬��ʼ��ͼ */
Graph* initGraph(int vexNum) {
    Graph* G = (Graph*)malloc(sizeof(Graph));
    /* ����һ��һά����洢��� */
    G -> vexs = (char*)malloc(sizeof(char) * vexNum);
    /* ����һ����ά�ڽ����� */
    G -> arcs = (int**)malloc(sizeof(int*) * vexNum);
    for (int i = 0 ; i < vexNum; i++) {
        G -> arcs[i] = (int*)malloc(sizeof(int) * vexNum);
    }
    G -> vexNum = vexNum;//��ʼ�������
    G -> arcNum = 0;//��ʼ������Ϊ0
    return G;
}

/* �����ڽӾ��󣬴���ͼ */
void createGraph(Graph* G, char* vexs, int* arcs) {
    for (int i = 0 ; i < G -> vexNum; i++) {
        G -> vexs[i] = vexs[i];//��ʶ�����
        for (int j = 0; j < G -> vexNum; j++) {
            G -> arcs[i][j] = *(arcs + i * G -> vexNum + j);//��ͼ���ڽӾ���ֵ
            if (G -> arcs[i][j] != 0)
                G -> arcNum ++;
        }
    }
    G -> arcNum /= 2;//����������ͼ�����Ա�����2
}

void DFS(Graph* G, int* visited, int index) {
    printf("%c\t", G -> vexs[index]);
    visited[index] = 1;//��Ƿ��ʹ��Ľڵ�
    for (int i = 0; i < G ->vexNum; i++) {
    	//�����ͨ�����յ�δ���ʹ�
        if (G -> arcs[index][i] == 1 && !visited[i]) {
            DFS(G, visited, i);//���յ������ȱ���
        }
    }
}

void BFS(Graph* G, int* visited, int index) {
    Queue* Q = initQueue();
    printf("%c\t", G -> vexs[index]);
    visited[index] = 1;
    enQueue(Q, index);//����һ�ڵ㿪ʼ���
    while (!isEmpty(Q)) {//����Ӳ�Ϊ�ռ�������
        int i = deQueue(Q);//����
        /* �����ó��ӽڵ�������ܵ�����յ� */
        for (int j = 0; j < G -> vexNum; j++) {
        	//�����ͨ��δ�����ʹ�
            if (G -> arcs[i][j] == 1 && !visited[j]) {
                printf("%c\t", G -> vexs[j]);//���ʸýڵ�
                visited[j] = 1;//��Ƿ���
                enQueue(Q, j);//�������
            }
        }
    }
}

int main() {
    Graph* G = initGraph(5);
    int* visited = (int*)malloc(sizeof(int) * G -> vexNum);//��ʶ����Ƿ񱻷��ʹ�
    for (int i = 0; i < G -> vexNum; i++)
        visited[i] = 0;
    int arcs[5][5] = {
        0,1,1,1,0,
        1,0,1,1,1,
        1,1,0,0,0,
        1,1,0,0,1,
        0,1,0,1,0
    };
    createGraph(G, "ABCDE", (int *)arcs);
    DFS(G, visited, 0);
    printf("\n");
    for (int i = 0; i < G -> vexNum; i++)
        visited[i] = 0;
    BFS(G, visited, 0);
    printf("\n");
    return 0;
}
