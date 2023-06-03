#include<stdio.h>
#include<stdlib.h> //ʹ��rand(),����һ����Χ��0~ RAND_MAX֮���α����� 
#include<conio.h> //����̨���������ʹ��getch()
#include<windows.h>//ʹ��system("pause")ʵ����ͣ��
                   //Sleep(200)���ӳ�200���� 
#define High 40//��Ϸ����ߴ� 
#define Width 100
 
// ȫ�ֱ���
int moveDirection;// С���ƶ�λ�ã��������ҷֱ���1��2��3��4��ʾ
int food_x,food_y; // ʳ���λ��
int canvas[High][Width] ={0}; // ��ά����洢��Ϸ�����ж�Ӧ��Ԫ��
                // 0Ϊ�ո�  ��-1Ϊ�߿�#��-2Ϊʳ�� F��1Ϊ��ͷ@������1������Ϊ����*
 
//����ƶ���(x,y)λ��
void gotoxy(int x,int y)
{
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(handle,pos);
}
//���ع��
void HideCursor()
{
    CONSOLE_CURSOR_INFO curInfo; //��������Ϣ�Ľṹ�����
    curInfo.dwSize = 1; //���û��ֵ�Ļ������������Ч
    curInfo.bVisible = FALSE; //���������Ϊ���ɼ�
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨���
    SetConsoleCursorInfo(handle, &curInfo); //���ù����Ϣ
}
 
//һ�����ݳ�ʼ�� ,����С�� 
void startup()
{
    int i,j;
    // ��ʼ���߿�
    for(i=0;i<High;i++)
    {
        canvas[i][0]=-1;
        canvas[i][Width-1]=-1;
    }
    for(j=0;j<Width;j++)
    {
        canvas[0][j]=-1;
        canvas[High-1][j]=-1;
    }
    // ��ʼ����ͷλ��
    canvas[High/2][Width/2]=1;
    
    // ��ʼ������������Ԫ��ֵ�ֱ�Ϊ2,3,4,5....
    for(i=1;i<4;i++)
          canvas[High/2][Width/2-i]=i+1;
 
    // ��ʼС�������ƶ�
    moveDirection=4;
     food_x=rand()%(High-5)+2;
    food_y=rand()%(Width-5)+2;
    canvas[food_x][food_y]=-2;    
}
 
 
// �����ƶ�С��
// ��һ��ɨ������canvas����Ԫ�أ��ҵ�����Ԫ�ض�+1
// �ڶ����ҵ����Ԫ�أ�����β�ͣ��������Ϊ0
// �ҵ�=2��Ԫ�أ�����ͷ�����ٸ���������������ҷ��򣬰Ѷ�Ӧ����һ������ֵ��Ϊ1������ͷ��
void moveSnakeByDirection()// �ƶ�С��
{
    // ��һ��ɨ������canvas����Ԫ�أ��ҵ�����Ԫ�ض�+1
    int i,j;
    for(i=1;i<High-1;i++)// i=1
        for(j=1;j<Width-1;j++)//j=1
            if(canvas[i][j]>0)
            canvas[i][j]++;
            
    // �ڶ����ҵ����Ԫ�أ�����β�ͣ��������Ϊ0        
    int oldTail_i,oldTail_j,oldHead_i,oldHead_j;
    int max=0;    
    
    for(i=1;i<High-1;i++)//i=1
    
        for(j=1;j<Width-1;j++)//j=1
        
            if(canvas[i][j]>0)
            {
                if(max<canvas[i][j])
                {
                    max=canvas[i][j];
                    oldTail_i=i;
                    oldTail_j=j;
                }
                if(canvas[i][j]==2)
                {
                    oldHead_i=i;
                    oldHead_j=j;
                }
            }
    // �ҵ�=2��Ԫ�أ�����ͷ�����ٸ���������������ҷ��򣬰Ѷ�Ӧ����һ������ֵ��Ϊ1������ͷ��
    int newHead_i,newHead_j;
    if(moveDirection==1)    //�� 
    {
        newHead_i=oldHead_i-1;
        newHead_j=oldHead_j;
    }
    if(moveDirection==2)    //�� 
    {
        newHead_i=oldHead_i+1;
        newHead_j=oldHead_j;
    }
    if(moveDirection==3)    //�� 
    {
        newHead_i=oldHead_i;
        newHead_j=oldHead_j-1;
    }
    if(moveDirection==4)    //�� 
    {
        newHead_i=oldHead_i;
        newHead_j=oldHead_j+1;
    }
    // ����ͷ����Ե�ʳ�-2Ϊʳ��F�� 
    if(canvas[newHead_i][newHead_j]==-2)
    {
        canvas[food_x][food_y]=0;
        //����һ���µ�ʳ�� 
        food_x=rand()%(High-5)+2;
        food_y=rand()%(Width-5)+2;
        canvas[food_x][food_y]=-2;// ԭ���ľ���β���ţ������Զ�+1
    } 
    // ����ԭ���ľ���β���������ֳ��Ȳ���
    else
        canvas[oldTail_i][oldTail_j]=0;
        // �Ƿ�С�ߺ�����ײ�����ߺͱ߿�ײ����Ϸʧ��
    if(canvas[newHead_i][newHead_j]>0||canvas[newHead_i][newHead_j]==-1)
    {
        printf("game over!\n");
        system("color 02");
        Sleep(2000);
        system("pause");
        exit(0);
    }
    else
       canvas[newHead_i][newHead_j]=1;
}
 
 
//��ʾ���� 
void show()
{
    gotoxy(0,0); // ����ƶ���ԭ��λ�ã������ػ�����
    int i,j;
    for(i=0;i<High;i++)
    {
        for(j=0;j<Width;j++)
        {
            if(canvas[i][j]==0)
               printf(" ");//    ����ո�
            else if(canvas[i][j]==-1)
               printf("#");//    ����߿�#
            else if(canvas[i][j]==1)
               printf("@");//    �����ͷ@
            else if(canvas[i][j]>1)
               printf("*");//    �������*
            else if(canvas[i][j]==-2)
               printf("F");//    ���ʳ��F
        }
        printf("\n");
    }
    Sleep(90);    
}
 
// ���û������޹صĸ���
void updateWithoutInput()
{
    moveSnakeByDirection();
}
 
// ���û������йصĸ��£�����С���ƶ� 
void updateWithInput()
{
    char input;
    if(kbhit())
    {
        input=getch(); // �ж��Ƿ�������
        if(input=='a')
        {
            moveDirection=3; // λ������
            moveSnakeByDirection();
        }
         else if(input=='d')
        {
            moveDirection=4;// λ������
            moveSnakeByDirection();
        }
        else if(input=='w')
        {
            moveDirection=1;// λ������
            moveSnakeByDirection();
        }
         else if(input=='s')
        {
            moveDirection=2; // λ������
            moveSnakeByDirection();
        }
    }
}
 
 
int main()
{
    startup(); // ���ݳ�ʼ��
    while(1)   // ��Ϸѭ��ִ��
    {
        show();// ��ʾ����
        HideCursor(); //���ع�� 
        updateWithoutInput();// ���û������޹صĸ���
        updateWithInput();   //���û������йصĸ���
    }
    return 0;
}

