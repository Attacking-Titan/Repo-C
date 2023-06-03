#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
char board[15][15];//��������
char role='X';//��ʼ��ɫΪX����һ��ɫΪ$
char x=7,y=7;//��ʼ����������(7,7),���λ��(x,y) 

void init_board(void)//��ʼ������ 
{
	int i,j;
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
			board[i][j]='0';
} 

void show_board()//��ӡ���� 
{
	int i,j;
	system("cls");
	for(i=0;i<15;i++)
	{
		printf("                            >>%2d",i+1);//ÿ�п�ͷ20���ո񣬵�������λ�� 
		for(j=0;j<15;j++)
			printf("  %c",board[i][j]);
		printf("  <<\n\n");
	}
	printf("                            > > > > > > > > > > > > > < < < < < < < < < < < < < <\n");
} 

void get_key(void)//��ȡ����,���λ��(x,y),�����ڹ������λ������ 
{
	while(1)
	{
		printf("\033[%d;%dH",2*x+1,3*y+35); 
		switch( getch() )
		{
			//role=X 
			case 'w': x>0 && x--; break;//�� 
			case 's': x<14 && x++; break;//�� 
			case 'a': y>0 && y--; break;//�� 
			case 'd': y<14 && y++; break;//�� 
			//role=$
			case 'o': x>0 && x--; break;//��
			case 'l': x<14 && x++; break;//�� 
			case 'k': y>0 && y--; break;//��
			case ';': y<14 && y++; break;//�� 
			case 32 : {
				if(board[x][y] == '0')//�����λ��û������
				{
				board[x][y]=role;
				return;
				}
			}
			case 13 :{
				if(board[x][y] == '0')//�����λ��û������
				{
				board[x][y]=role;
				return;
				}
			}
		}
	} 
}

int count(go_x,go_y)//�����õ�ĳ������������� 
{
	char X=x,Y=y;//�����ӷ���λ�ÿ�ʼ���� 
	int count=0;//��¼������� 
	while(X>=0 && Y>=0 && count<5)//���û�д����߽����û�г����������������������� 
	{
	if( board[X][Y] == board[X+go_x][Y+go_y] )count++;//������������� 
	else break;//������ֹͣ���� 
	X+=go_x;
	Y+=go_y;
	}
	return count;
} 

_Bool is_win(void)
{
	if( count(1,0)+count(-1,0) >=4 )return 1;//���� 
	if( count(0,1)+count(0,-1) >=4 )return 1;//����
	if( count(1,-1)+count(-1,1) >=4 )return 1;//���Ϻ�����
	if( count(1,1)+count(-1,-1) >=4 )return 1;//���Ϻ�����
	return 0; //ȫ�������϶�������������������������Ϸ 
}

int main()
{
	int i;
	init_board();
	system("color f0"); 
	for(i=0;i<225;i++)//�ܹ�225����λ 
	{
		show_board();
		get_key();
		if( is_win() )//�ж��Ƿ�����ʤ��
		{
			
			system("color 02");
			show_board();
			printf("                                                %c Ӯ�ñ���\n                                                ",role);
			system("pause");
			return 0;
		} 
		role=(role=='X')?'$':'X';//������ɫ 
	}
}
