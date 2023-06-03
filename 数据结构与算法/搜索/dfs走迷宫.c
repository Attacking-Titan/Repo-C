#include<stdio.h>
#include<stdlib.h>
#define LEN 100
int m,n;
char pos[LEN][LEN];
int sx,sy;//�������
int ex[5] = {-1,-1,-1,-1,-1};//�յ�����
int ey[5] = {-1,-1,-1,-1,-1};//�յ�����
_Bool vis[LEN][LEN] = {0};
int dx[4] = {-1,1,0,0};//��������
int dy[4] = {0,0,-1,1};//��������
int end = 0;

_Bool in(int x,int y){
	return 0 <= x && x < n && 0 <= y && y < m;
}

_Bool dfs(int x,int y){
	vis[x][y] = 1;//����߹��ĵط�
	if(pos[x][y] == 'T') {//�����յ�
		ex[end] = x;
		ey[end] = y;
		pos[x][y] = 'T';
		end++;
		return 1;
	}
	else {
		int i;
		for(i = 0;i < 4;i++){
			int tx = x + dx[i];
			int ty = y + dy[i];
			if(!vis[tx][ty] && in(tx,ty) &&  pos[tx][ty]!='*'){
				//!vis[tx][ty]��(tx,ty)λ��δ���ʹ�
				//in(tx,ty)��(tx,ty)λ�ÿ��Խ���,δԽ��
				//pos[tx][ty]!='*':(tx,ty)λ�ò���ǽ
				if(dfs(tx,ty)) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int main(){
	scanf("%d%d",&m,&n);
	getchar();
	int i,j;
	for(i = 0;i < n;i++){//��
		for(j = 0;j < m;j++){//��
   			scanf(" %c",&pos[i][j]);
		}
	}
	printf("\n");
	for(i = 0;i < n;i++){//��
		for(j = 0;j < m;j++){//��
   			printf("%c ",pos[i][j]);
		}
		putchar('\n');
	}
    for(i = 0;i < n;++i)
		for(j = 0;j < n;++j){
			if(pos[i][j] == 'S') {
				sx = i;
				sy = j;
			}
		}
	if(dfs(sx,sy)) puts("Yes");
		else puts("No");
    for(i = 0;i < 5;i++)
		if(ex[i] != -1) printf("�յ�����(%d,%d)\n",ex[i],ey[i]);
			else break;
	for(i = 0;i < n;i++){
		for(j = 0;j < m;j++)
			printf("%d ",vis[i][j]);
		printf("\n");
	}
	return 0;
}
