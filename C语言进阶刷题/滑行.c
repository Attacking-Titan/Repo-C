#include <stdio.h>
#include <stdlib.h>
int n,m;
int a[105][105];
int step = 0,max = 0;
/* �������� */
int dx[4] = {0,0,-1,1};//��
int dy[4] = {-1,1,0,0};//��

void dfs(int x,int y){
    step++;//����һ��λ�ã�������һ
    int i;
    //��(x,y)������������������
    for(i = 0;i < 4;i++){
      //��Ϊֻ�ܴӸߴ�����ʹ����Բ���Ҫ�ж��Ƿ��߹�����Ϊ�޷���֮ǰ��·
      int X = x + dx[i],Y = y + dy[i];
      if(X >= 0 && X < m && Y >= 0 && Y < n && a[Y][X] < a[y][x]){
        dfs(X,Y);
        step--;//���ݵ�ԭ����λ�ã�������ԭ
      }
      else if(step > max) max = step;//����������
    }
}

int main(int argc, char *argv[])
{
	int i,j;
  	scanf("%d %d",&n,&m);
  	for(i = 0;i < n;i++){
  	  	for(j = 0;j < m;j++){
      		scanf("%d",&a[i][j]);
      	}
	}
  	//������λ���������������
  	for(i = 0;i < n;i++){
   	 	for(j = 0;j < m;j++){
   	 		step = 0;
     		dfs(j,i);
    	}
  	}
  	printf("%d",max);
  	return 0;
}
