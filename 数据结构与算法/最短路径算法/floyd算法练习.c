#include<stdio.h>
#include<stdlib.h>
#define INF 32768

typedef struct Graph{
	char *vexs;
	int **arcs;
	int vexNum;
	int arcNum;
}Graph;

Graph *initGraph(int vexNum){
	Graph *G = (Graph *)malloc(sizeof(Graph));
	G->vexs = (char *)malloc(sizeof(char));
	G->arcs = (int **)malloc(sizeof(int *));
	int i;
	for(i = 0;i < vexNum;i++){
		G->arcs[i] = (int *)malloc(sizeof(int));
	}
	G->vexNum = vexNum;
	G->arcNum = 0;
	return G;
}

void createGraph(Graph *G,char *vexs,int *arcs){
	int i,j;
	for(i = 0;i < G->vexNum;i++){
		G->vexs[i] = vexs[i];
	}
	for(i = 0;i < G->vexNum;i++){
		for(j = 0;j < G->vexNum;j++){
			G->arcs[i][j] = *(arcs + i * G->vexNum + j);
			if(G->arcs[i][j] != 0 && G->arcs[i][j] != INF){
				G->arcNum++;
			}
		}
	}
	G->arcNum /= 2;
}

void DFS(Graph *G,int *visited,int index){
 	if(visited[index] == 0){
		printf("v%c ",G->vexs[index]);
		visited[index] = 1;
		int i;
		for(i = 0;i < G->vexNum;i++){
			if(G->arcs[index][i] > 0 && G->arcs[index][i] != INF){
				DFS(G,visited,i);
   			}
		}
 	}
}

void showPath(int vexNum,int *d,int *p){
	int i,j,k = 0;
	int cnt;
	/* path������ģ��ջ */
	int path[vexNum];
	int size = 0;
	printf("    �յ�  ");
	for(i = 0;i < vexNum;i++){
		printf("v%d",i + 1);
		for(j = 0;j < vexNum;j++){
			printf("    ");
		}
		printf("    ");
	}
	printf("\n���\n");
	for(i = 0;i < vexNum;i++){
		printf("v%d        ",i + 1);
		for(j = 0;j < vexNum;j++){
			size = 0;
			k = j;
			//���յ㵽�������е�Ӻ�ǰ������ջ
			path[size++] = j;//��ջ�յ�
			while(k != i){
				k = *(p + vexNum * i + k);//vi��vk��ǰ��
				path[size++] = k;//���Ҳ����ջ
			}
			//��ջ�еĵ��ջ
			cnt = 0;//�����ַ���
			while(size > 1){
				printf("v%d->",path[--size] + 1);
				cnt++;
			}
			printf("v%d",path[0] + 1);
			while(cnt <= vexNum){
				printf("    ");
				cnt++;
			}
		}
		printf("\n\n");
	}
}

void floyd(Graph *G){
    int d[G->vexNum][G->vexNum];//d[i][j]��ʾ��i��j����̾���
    int p[G->vexNum][G->vexNum];//p[i][j]��ʾ��i��j�����·����j��ǰ��
    int i,j,k;
    //��ʼ��d�����p����
    for(i = 0;i < G->vexNum;i++){
		for(j = 0;j < G->vexNum;j++){
			d[i][j] = G->arcs[i][j];
			if(d[i][j] > 0 && d[i][j] != INF){
				p[i][j] = i;
			}
			else
				p[i][j] = -1;
		}
    }
    /* floyd�㷨 */
    for(i = 0;i < G->vexNum;i++){//�����м�ڵ�
    	for(j = 0;j < G->vexNum;j++){//�������
    		for(k = 0;k < G->vexNum;k++){//�����յ�
				if(d[j][i] + d[i][k] < d[j][k]){
					d[j][k] = d[j][i] + d[i][k];
					p[j][k] = i;
				}
			}
		}
	}
 	showPath(G->vexNum,(int *)d,(int *)p);
}

int main(){
	Graph *G = initGraph(4);
	/* �涨����������·����Ϊ0�����ɴ��·����ΪINF */
	int arcs[4][4] = {
		  0,  1,INF,  3,
		  1,  0,  2,  2,
		INF,  2,  0,  8,
		  3,  2,  8,  0
	};
	int visited[4] = {0};
	createGraph(G,"1234",(int *)arcs);
	DFS(G,visited,0);
	putchar('\n');
 	floyd(G);
	return 0;
}

