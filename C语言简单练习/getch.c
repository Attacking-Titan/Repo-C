#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
char key_x=7,key_y=7;
char board[15][15];
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
void print()
{
	int i,j;
	system("cls");
	for(i=0;i<15;i++){
	for(j=0;j<15;j++){
	printf("  %c",board[i][j]);
	}
	printf("\n\n");
	}
}
void getxy(void)
{
	while(1){
	 printf("\033[%d;%dH",key_x*2,3*key_y+3);//���λ�ã�(key_y+1)*2����Ϊ������֮���пո�
  	 switch(getch())
  	 {
   	    case 'w':key_x>0 && key_x--;break; //�ϣ��ı���λ��ֵ
   	    case 'o':key_x>0 && key_x--;break; //�� 
   		case 's':key_x<14 && key_x++;break; //��
   		case 'l':key_x<14 && key_x++;break; //�� 
   		case 'd':key_y<14 && key_y++;break; //��
   		case ';':key_y<14 && key_y++;break;//�� 
   		case 'a':key_y>0 && key_y--;break;//��
   		case 'k':key_y>0 && key_y--;break;//��
	 }
	}
}
int main()
{
	init_board();
	while(1){
	 print();
     getxy();
 }
	return 0;
}
