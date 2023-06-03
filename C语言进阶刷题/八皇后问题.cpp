#include<stdio.h>
#include<memory.h>
struct map
{
char attack[8][8];//��¼�ᱻ�����ķ�Χ��1������������0�������� 
char queen[8][8];//��¼���ûʺ��λ�ã�'.'����û�з��ã�'Q'������� 
}temp[8],solve[100];
        /*{����  _��  ����  _��  _��  ����  _��  ����} */
static const int dx[8]={ -1 , -1 , -1  , 0  ,  0 ,  1  ,  1 ,  1 };//�����귽�� 
static const int dy[8]={ -1 ,  0 ,  1  , 1  , -1 , -1  ,  0 ,  1 };//�����귽�� 
int count=0;
/*
      _______ ---->x
    .|_|_|_|_|
    .|_|_|_|_|
    .|_|_|_|_|
    .|_|_|_|_|
    .
    y     [i+dx*m][j+dy*n]==(x,y)
*/
 

void print(void)
{
 	int i,j,k;
	for(i=0;i<8;i++)
	{
	  for(j=0;j<8;j++)
	    printf("%c ",temp[7].attack[i][j]);//��ӡ��i�е�attack
	  printf("\t\t");//��attack��queen�Ĵ�ӡ�ָ��� 
	  for(k=0;k<8;k++)
	    printf("%c ",temp[7].queen[i][k]);//��ӡ��i�е�queen 
	  printf("\n");//��ӡ��һ�� 
   }
}


void put_queen(int x,int y,int k)
//�ڵ�k�з���queen,��attack���и��� 
{
 temp[k].queen[x][y]='Q';
 temp[k].attack[x][y]='0';
 for(int i=0;i<8;i++)//���ư˸����� 
     for(int j=1;j<8;j++)//���������� 
     {
     	int nx=x+dx[i]*j;//�����µ��� 
     	if(nx<0||nx>=8)break;//�ж�x�����Ƿ�������� 
     	int ny=y+dy[i]*j;//�����µ��� 
     	if(ny<0||ny>=8)break;//�ж�y�����Ƿ�������� 
        temp[k].attack[nx][ny]='0';
	 }
}
void backtrack(int k)
{
    //��������
    if (k == 8)//�ҵ�һ���
    {
        temp[k]=solve[count];//�����queen�洢��solve
        count++;
        return;
    }
    //һ������µ����Ĵ��� 
    for (int k=0,i = 0; i < 8; i++)//�ڵ�k���л�����̽�ʺ�ɷ��õ�λ��
    {
        if (temp[k].attack[k][i] == 0)//�жϵ�ǰk�е�i���Ƿ���Է��ûʺ�
        {
            put_queen(k,i,k);
            backtrack(k + 1);//�ݹ���̽k+1�еĻʺ��λ��
        }
        k--;
    }
}

int main()
{
   int k=0;
   while(k<8)
   {
   memset(&temp[k].attack,'1',64);
   memset(&temp[k].queen,'.',64); 
   }
   backtrack(0);
   print();
   return 0; 
}
