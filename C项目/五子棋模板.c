#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define true 1
#define false 0 

//��������
char board[15][15];
//��ɫ
char role='X';
//��������
char key_x=7,key_y=7;
//���̳�ʼ��
void init_board(void)
{
 int i,j;
 for(i=0;i<15;i++)
 {
  for(j=0;j<15;j++)
  {
   board[i][j]='0'; 
  }
 }
}

//��ӡ����
void show_board(void)
{
 int i,j;
 system("cls");
 for(i=0;i<15;i++)                                                  
 {
  printf("                   >%2d",i+1);
  for(j=0;j<15;j++)
  {
   printf("  %c",board[i][j]); 
  }
  printf("  <\n\n");
 }
 printf("                   > > > > > > > > > > > > > < < < < < < < < < < < < <\n");
}                                                                             

//����
void get_key(void)
{
 while(1){
     printf("\33[%d;%dH",key_x*2+1,3*key_y+25);//���λ�ã�(key_y+1)*2����Ϊ������֮���пո�
  	 switch(getch())
  	 {
   	    case 'w':key_x>0 && key_x--;break; //��,�ı���λ��ֵ
   	    case 'o':key_x>0 && key_x--;break; //�� 
   		case 's':key_x<14 && key_x++;break; //��
   		case 'l':key_x<14 && key_x++;break; //�� 
   		case 'd':key_y<14 && key_y++;break; //��
   		case ';':key_y<14 && key_y++;break;//�� 
   		case 'a':key_y>0 && key_y--;break;//��
   		case 'k':key_y>0 && key_y--;break;//�� 
   		case 32://�ո�
   		if(board[key_x][key_y] == '0')//�������λ��Ϊ�գ�����
		   {
   			 board[key_x][key_y]=role;
    		 return;
    	   }
		 if(board[key_x][key_y] == 13)//�������λ��Ϊ�գ�����
		   {
   			 board[key_x][key_y]=role;
    		 return;
    	   }
	 }
 }
}

//��¼����λ��ĳ���������ӵĸ���
int count_board(int go_x,int go_y)
{
 int count=0,x,y;
 for(x=key_x+go_x,y=key_y+go_y;
  x>=0 && y>=0 && x<15 && y<15;
  x+=go_x,y+=go_y)//������������ 
 {
  if(board[x][y]==board[key_x][key_y])
  {
   count++; 
  }
  else break;//һ����������������ӣ�ֹͣ���� 
 }
 return count;
}

//�ж��������飬�Ƿ�ʤ��
_Bool is_win(void)
{
 if(count_board(0,-1)+count_board(0,1)>=4)//���ҷ��� 
 {
  return true; 
 }
 if(count_board(-1,0)+count_board(1,0)>=4)//���·��� 
 {
  return true; 
 }
 if(count_board(-1,-1)+count_board(1,1)>=4)//���Ϻ����·��� 
 {
  return true; 
 }
 if(count_board(1,-1)+count_board(-1,1)>=4)//���º����Ϸ��� 
 {
  return true; 
 }
 return false;
}

int main(int argc,const char* argv[])
{
 int i;
 system("color f0");
 init_board();	//��ʼ������
 for(i=0;i<=225;i++)
 {
  show_board();	//��������ӡ����
  get_key();	//����
  if(is_win())	//�Ƿ���������
  {
   system("cls");
   show_board();
   system("color 02");
   printf("                   ��Ϸ������%cӮ��\n",role);
   return 0;
  }
  role=role=='X'?'$':'X';//������ɫ
 }
} 
