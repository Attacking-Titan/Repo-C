#include <stdio.h>
#include <stdlib.h>

/**
 * ͼ����֮�䲻ͨ����ô�ڽӾ����ֵΪMAX
 * ����������Լ�������ôֵΪ0
 */
#define MAX 32767

typedef struct Graph {
    char* vexs;//ָ��������
    int** arcs;//ָ���ڽӾ���Ķ�ά����
    int vexNum;//�ڵ����
    int arcNum;//����
}Graph;

//��¼U���ϵ���Ϣ
typedef struct Edge {
    char vexs;//��¼U���ϵ���С�ߵ���ʼ�ڵ�
    int weight;//��¼��С��
}Edge;

/*
 * ��edge.weight = 0ʱ����������뵽U������
 */
Edge* initEdge(Graph* G, int index) {
    Edge* edge = (Edge*)malloc(sizeof(Edge) * G -> vexNum);//�ܹ�vexnum����С��
    int i;
    for (i = 0; i < G ->vexNum; i++) {
        edge[i].vexs = G -> vexs[index];
        edge[i].weight = G -> arcs[index][i];
    }
    return edge;
}//��index������Ľڵ����U������

int getMinEdge(Edge* edge, Graph* G) {
    int index;
    int min = MAX;
    int i;
    /* ��һ����СȨֵ�ı� */
    for (i = 0; i < G -> vexNum; i++) {
    	//��ǰ�ڵ�û�м���U��������Сֵ���ڴ˱ߵ�Ȩ��
        if (edge[i].weight != 0 && min > edge[i].weight) {
            min = edge[i].weight;
            index = i;
        }
    }
    return index;
}//�����յ�ڵ�

//�Խڵ�index������С������
void prim(Graph* G, int index) {
    int min;
    int i,j;
    Edge* edge = initEdge(G, index);
    for(j = 0;j < G->vexNum;j++){
        	printf("v%c->v%c %d\tv%c->v%c %d\n",edge[j].vexs,G->vexs[j],edge[j].weight,G->vexs[min],G->vexs[j],G->arcs[min][j]);
	}
    for (i = 0; i < G -> vexNum - 1; i++) {
        min = getMinEdge(edge, G);
        printf("v%c --> v%c, weight = %d\n", edge[min].vexs, G -> vexs[min], edge[min].weight);
        edge[min].weight = 0;
        //��edge������¼min�ڵ��״̬
        for (j = 0; j < G -> vexNum; j++) {
            if (G -> arcs[min][j] < edge[j].weight) {//���min->j��ȨֵС�ڴ�ʱedge�м�¼�ĵ�j�ڵ��Ȩֵ
                edge[j].weight = G -> arcs[min][j];//��edge�еĵ����ڵ��Ȩֵ�滻Ϊmin�ڵ㵽���ڵ��Ȩֵ
                edge[j].vexs = G -> vexs[min];//���ڵ��滻��min�ڵ�
            }
        }
        for(j = 0;j < G->vexNum;j++){
        	printf("v%c->v%c %d\tv%c->v%c %d\n",edge[j].vexs,G->vexs[j],edge[j].weight,G->vexs[min],G->vexs[j],G->arcs[min][j]);
		}
		printf("\n");
    }
}

Graph* initGraph(int vexNum) {
	int i;
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G -> vexs = (char*)malloc(sizeof(char) * vexNum);
    G -> arcs = (int**)malloc(sizeof(int*) * vexNum);
    for (i = 0 ; i < vexNum; i++) {
        G -> arcs[i] = (int*)malloc(sizeof(int) * vexNum);
    }
    G -> vexNum = vexNum;
    G -> arcNum = 0;
    return G;
}//��ͼ���ٿռ�

void createGraph(Graph* G, char* vexs, int* arcs) {
	int i,j;
    for (i = 0 ; i < G -> vexNum; i++) {
        G -> vexs[i] = vexs[i];
        for (j = 0; j < G -> vexNum; j++) {
            G -> arcs[i][j] = *(arcs + i * G -> vexNum + j);//�����ڽӾ���
            if (G -> arcs[i][j] != 0 && G -> arcs[i][j] != MAX)
                G -> arcNum ++;
        }
    }
    G -> arcNum /= 2;
}

void DFS(Graph* G, int* visited, int index) {
    printf("%c\t", G -> vexs[index]);
    visited[index] = 1;
    int i;
    for (i = 0; i < G ->vexNum; i++) {
        if (G -> arcs[index][i] > 0 && G -> arcs[index][i] != MAX && !visited[i]) {
            DFS(G, visited, i);
        }
    }
}

int main() {
    Graph* G = initGraph(6);
    int* visited = (int*)malloc(sizeof(int) * G -> vexNum);
    int i;
    for (i = 0; i < G -> vexNum; i++)
        visited[i] = 0;
    int arcs[6][6] = {
        0, 6, 1, 5, MAX, MAX,
        6, 0, 5, MAX, 3, MAX,
        1, 5, 0, 5, 6, 4,
        5, MAX, 5, 0, MAX, 2,
        MAX, 3, 6, MAX, 0, 6,
        MAX, MAX, 4, 2, 6, 0
    };//�ڽӾ���
    createGraph(G, "123456", (int*)arcs);
    DFS(G, visited, 0);
    printf("\n");
    prim(G, 0);
    return 0;
}
