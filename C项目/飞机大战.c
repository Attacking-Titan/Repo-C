#include"stdio.h"
#include"windows.h"    //���ڻ�ȡ���ڵľ������Ļ����
#include"conio.h"      //���ڻ�ȡ�������������
#include"string.h"  
#include"stdlib.h"   
/*�����ṹ��*/
/*���ڴ��û���Ϣ*/ 
typedef struct usepeople
{
    char name[20];//�û��� 
    char mm[20];//���� 
    struct usepeople *next;
}U;
/*�����ʷ��¼*/ 
struct history
{
    char NAME[20];
    int SCORE;
}s[10];
//����ȫ�ֱ���
int o;    //�������а����
char j[20];     //�������а��û���
int h,w;   //���廭��ĸߺͿ� 
int p_x,p_y;       // �����ҷ��ɻ���λ��
int e_x,e_y;       // ����з��ɻ���λ�� 
int b_x,b_y;       //�����ӵ���λ�� 
int score;         //�÷�
int f;              //����ɻ���״̬
int num=1;          //��������������  (�����õ���8��)     
void gotoxy(int x,int y);              //����ƶ���(x,y)λ�� 
void menu1(U *h,int num);                       //�˵�����   
int color(int c);                       //����������ɫ
void explation();                    //��Ϸ�Ҳ���ʾ 
void tip();                         //��Ϸ˵��
void seescore();                      //������ʾ 
void startup();                      //��Ϸ��ʼ�� 
void show();                        //��ʾ��Ϸ���� 
void Fly();                         //���庯���������ӵ��͵��˵��ƶ� 
void Planefly() ;                   //���庯�������Ʒɻ����ƶ����ӵ��ķ���
void gameover(U *h);                  //�����Ϸ��������
U * createpeople(U *h);           //����ע���û�����Ϣ
void create(U *h);                //������һ��ע����Ϣ 
void History_inf(struct history s[],int num); //���ڱ��������ս����Ϣ
void insert(U *h);            //�ڽ�β����ע��������˺� 
U* search(U *h,char *name);  //�����ж��û����û����Ƿ���ȷ 
void deletenum(U *h,char name[]);//ע���û���Ϣ 
void iregister(U *h);        //ע��ҳ�� 
void dengru(U *h,int num);   //����ҳ�� 
void log_in(U *h);               //�����û���Ϣ 
void msort(struct history *a,int n);    //��¼ð������ 
int color(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);        //����������ɫ
    return 0;
}
//ע���û���Ϣ
void deletenum(U *h,char name[])
{
    U *p=h->next;
    while(p&&strcmp(p->name,name)!=0)
    {
        h=p;
        p=p->next;
    }
    if(p)
    {
        h->next=p->next;
        free(p);
    }
}
/*���ù���λ��*/
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
/*��������*/
void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = {1,0};//�ڶ���ֵΪ0��ʾ���ع��
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
/*����ð������*/ 
void msort(struct history *a,int n)
{
    int i,f;
    for(i=1;i<num;i++)
    {
        for(f=num;f>i;f--)
        {
            if(s[f].SCORE>s[f-1].SCORE)
            {
                o=a[f].SCORE;
                a[f].SCORE=a[f-1].SCORE;
                a[f-1].SCORE=o;
                strcpy(j,a[f].NAME);
                strcpy(a[f].NAME,a[f-1].NAME);
                strcpy(a[f-1].NAME,j);
            }
        }
    }
}
//���ڱ��������ս����Ϣ
void History_inf(struct history s[],int num,U* h)
{
	int i; 
    system("cls");
    if(num==1)
    {
        gotoxy(1,1);
        printf("�㻹û�м�¼");
    }
    
    for(i=1;i<num;i++)   //�����for��������һ���ÿһ���û������� 
    {
        gotoxy(15,3+2*i);
        printf("%d:�û���:%s   ",i,s[i].NAME);
        printf("�÷�:%d   ",s[i].SCORE);
    
    }
        gotoxy(1,28);
        printf("��ע����ౣ��8�μ�¼");
        getch();
        system("cls");
        menu1(h,num);  //�����Ժ󷵻ؿ�ʼ���� 
} 
//������һ��ע����Ϣ 
void create(U *h)
{
    U *p,*q=h;
    char name[20];
    printf("�������û���:\n");
    gotoxy(39,12);
    scanf("%s",name);
    while(strcmp(name,"OVER"))
    {
        p=(U*)malloc(sizeof(U));
        strcpy(p->name,name);
        char mm[20];
        gotoxy(39,13);
        printf("����������:����������OVER������\n"); 
        gotoxy(39,14);
        scanf("%s",mm);
        strcpy(p->mm,mm);
        q->next=p;
        q=p;
        gotoxy(39,15);
        scanf("%s",name);
    }
    q->next=NULL;
}
 
U* search(U *h,char *name)
{
    while(h=h->next,h)
    {if(!strcmp(h->name,name))  return h;}
    return NULL;
}
 
U * createpeople(U *h)
{
    U *q;
    q=(U*)malloc(sizeof(U));
W:    printf("������Ҫע����û�����\n");
    scanf("%s",q->name);
    if(search(h,q->name)) {system("cls");printf("���û����Ѵ��ڣ�����\n");_getch();system("cls");goto W;}
    printf("����������룺\n");
    scanf("%s",q->mm);
    q->next=NULL;
    return q;
}
//�ڽ�β����ע��������˺� 
void insert(U *h)  
{
    U *q,*temp;
    q=createpeople(h);
    while(h=h->next,h){if(h->next==NULL)break;}temp=h;
    q->next=temp->next;
    temp->next=q;
}
/*��Ϸ˵��*/
void tip()    
{
    gotoxy(30,5);printf("w���ϣ�s���£�a����d���ң����ո����");
    gotoxy(30,10) ;printf("�����һ�ܵл��ɵ�1��"); 
    gotoxy(30,15);    printf("����㱻�л�ײ�Ͼͻ�����");
}                     
void menu1(U *h,int num)                       //�˵�����   
{
    int n;
    gotoxy(37,10);
    printf("�� �� �� ս"); 
    gotoxy(15,20);
    printf("��������1����ʼ��Ϸ") ;
    gotoxy(55,20);
    printf("��������2���鿴����");
    gotoxy(15,22);
    printf("��������3���鿴��ս��"); 
    gotoxy(55,22);
    printf("��������4���˳���Ϸ"); 
    gotoxy(15,24);
    printf("��������5��ע���˺�");
    gotoxy(55,24);
    printf("��������6������ǩ��"); 
    gotoxy(37,25);
    printf("���������ѡ��"); 
     scanf("%d",&n);
     switch(n)
     {
         case 1:
             {
                 system("cls"); 
             }break;
        case 2:
            {
                system("cls");
                tip(); 
                printf("\n");
                gotoxy(30,17);
                printf("����1 ��������ҳ");
                int a=0; 
                scanf("%d",&a);
                if(a==1) {system("cls");menu1(h,num);}
            }break;
        case 3:
            {
                 History(s,num,h);    
            }break;
        case 4:
            {
                system("cls");
                printf("��ȷ��Ҫ�˳���Ϸ��\n");
                printf("ȷ������1,��ȷ������2\n");
                int a=0;
                scanf("%d",&a);
                if(a==1)    exit(0);
                else {system("cls");menu1(h,num);}
            }break;
        case 5:
            {
                char name[20];
                    system("cls");
                    printf("����Ҫɾ�����ʺ�:");
                    scanf("%s",name);
                    deletenum(h,name);
                    printf("����1 ��������ҳ");
                int a=0; 
                scanf("%d",&a);
                if(a==1)
                 {
                   system("cls");
                   if(h->next==NULL)
                    {iregister(h);dengru(h,num);}
                    else dengru(h,num);menu1(h,num);
                 }    
            }break;
        case 6:
            {
                system("cls");log_in(h);
                gotoxy(42,12);printf("���������������������\n");
                _getch();
                system("cls");
                menu1(h,num);
            }break;
            default:
            {
                gotoxy(37,25);
                printf("�뿴�������\n");
                _getch();
                system("cls");
                menu1(h,num);
            }break;
     }
} 
void startup()      //��Ϸ��ʼ�� 
{
    h=20; //��Ϊ20 
    w=50; //��Ϊ50
    score=0; //�÷ֳ�ʼ�� 
    f=1;  //�ɻ���״̬
    p_x=w/2; //�ɻ�x��λ�� 
    p_y=h-4; //�ɻ�y��λ��
    e_x=2+rand()%w-2;
    e_y=0; 
    b_x=p_x;
    b_y=0;
    HideCursor();   //���ع�� 
}
/*��ʾ��Ϸ����*/
void show()
{
    int i,j;
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            if(f==0)     break;
            else
            {
            if((i==0)||(j==0)||(i==h-1)||(j==w-1))   printf("+");
            else if((i==p_y)&&(j==p_x))     printf("A");
            else if((i==b_y)&&(j==b_x))       printf("!");
            else if((i==e_y)&&(j==e_x))       printf("@");
            else printf(" ");
            }    
        }
    printf("\n");
    }
    if((p_x==e_x)&&(p_y==e_y))    f--;
}               
/*������ʾ  */ 
void seescore(int num)
{
    gotoxy(56,5);printf("w���ϣ�s���£�a����d���ң����ո����");
    gotoxy(56,7);printf("AΪ����ս��"); 
    gotoxy(56,8);printf("@Ϊ�л�");
    gotoxy(2,21);printf("��ĵ÷�Ϊ%d",score);
    s[num].SCORE=score;
} 
 /*��ѭ�����Ƶл��ķ����ٶ�*/ 
void Fly()
{
     static int speed=0;
     if(speed<10) speed++;
     if(speed==10)   
     {
         if(e_y<h)   e_y++;
         else { e_y=0;e_x=2+rand()%w-2;}
        speed=0;
     }
}
void b_Fly()
{
     if(b_y>0)     b_y--;//�����ӵ��ķ���Ч�� 
     if((b_y==e_y)&&(b_x==e_x))      {score++;e_y=0;e_x=2+rand()%w-2;b_y=0;}
}
/*���Ʒɻ����ƶ�*/ 
void Planefly() 
{
    char input;
    if(kbhit()) //kbhit�������ж��Ƿ������� 
    {
        input=getch(); //�������ֵ����input���� 
        if((input=='w')&&(p_y>1)) //�������wsad����Ӧ�ƶ��ɻ���λ�� 
        {
            p_y--;
        }
        if((input=='s')&&(p_y<h-2))
        {
            p_y++;
        }
        if((input=='a')&&(p_x>1))
        {
            p_x--;
        }
        if((input=='d')&&(p_x<w-2))
        {
            p_x++;
        }
        if((input==' ')&&(b_y==0))
        {
            b_x=p_x;
            b_y=p_y;
        }
    }
}          
void gameover(U *h)//��Ϸ������ʾ 
{
    system("cls");int a;
    gotoxy(39,14);printf("����1������ɻ�������2������Ϸ");
    scanf("%d",&a);
    switch(a)
    {
        case 1:{system("cls");}break;
        case 2:{system("cls");exit(0);}break;
        default:{system("cls");printf("�뿴���Ҫ��");_getch();gameover(h);}break;
    }
} 
 
/*������ע��*/ 
void iregister(U *h)
{
    char name[20];
    char mm[20];
    gotoxy(51,6);    printf("ע��") ;
    gotoxy(39,11);     create(h);//ע��
    gotoxy(39,16);
    printf("ע��ɹ�������(�����������)\n");
    HideCursor();
    _getch();system("cls");
} 
void dengru(U *h,int num)
{
    char name[20];char mm[20];
o:  gotoxy(39,16);
    printf("�������û�����\n");
    gotoxy(39,17);
    scanf("%s",name);
    strcpy(s[num].NAME,name);//���û�������ṹ������ 
    gotoxy(39,18);
    printf("���������룺\n");
    gotoxy(39,19);
    scanf("%s",mm);
    if(!search(h,name))  
    {
     system("cls");gotoxy(39,16);printf("û�и��û���Ϣ������ע�ᣡ����(�����������)");
     _getch();system("cls") ;insert(h);system("cls"); goto o; 
    }
    U *temp=search(h,name);//�ж����� 
    if(strcmp(temp->mm,mm)) 
    {system("cls");gotoxy(39,17);printf("����������������룡���������������");_getch();system("cls") ;dengru(h,num);} 
    else{gotoxy(39,20);printf("����ɹ�!!!(���������ʼ��Ϸ)");_getch();system("cls");} 
}   
void log_in(U *h) {
    FILE*fp;
    char name[20];char time[20];
    if ((fp = fopen("d:\\informeation storage.txt", "a+")) == NULL) {
        printf("�ļ������ڣ������ɹ�");
    }
M:    gotoxy(36,9);
    printf("Ϊ��Ϊ�����˺�ǩ�������ٴ������˺�\n");
    gotoxy(42,10);
    scanf("%s", name);
    if(!search(h,name))  {gotoxy(42,11);printf("�����������������");_getch();system("cls");goto M;    }
    fputs(name, fp);
    gotoxy(36,11);
    printf("����������ʱ��\n");
    gotoxy(42,12);
    scanf("%s", time);
    fputs(time, fp);
    fclose(fp);
}
int main ()
{
    system("mode con cols=100 lines=30");  //������100��30�ĳ�������С
    U *head=(U*)malloc(sizeof(U)); //����һ����ͷ������ 
    iregister(head); L:dengru(head,num);menu1(head,num);startup();//��ʼ��
    while(1)
    {
        gotoxy(0,0);show();seescore(num);
        if(f==0)//�жϷɻ���״̬ 
        {
            gameover(head);s[num].SCORE=score;num++;if(num==10) num=1;
            msort(s,num+1);
            goto L;
        }
        b_Fly();Fly();Planefly(); 
    }
    return 0;
 } 
