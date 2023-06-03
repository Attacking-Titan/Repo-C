#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 100

typedef struct
{
    char name[20];
    char id[20];
    char password[20];
    float balance;
}Account;

Account account[MAX_NUM];
int count = 0;

void menu();
void open_account();
void search_account();
void deposit_account();
void withdraw_account();
void delete_account();

int main()
{
    int choice;
    while(1)
    {
        menu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                open_account();
                break;
            case 2:
                search_account();
                break;
            case 3:
                deposit_account();
                break;
            case 4:
                withdraw_account();
                break;
            case 5:
                delete_account();
                break;
            case 0:
                exit(0);
            default:
                printf("�����������������룡\n");
                break;
        }
    }
    return 0;
}

void menu()
{
    printf("");
    printf("                *****************************\n");
    printf("                *                           *\n");
    printf("                *        1.����             *\n");
    printf("                *        2.��ѯ             *\n");
    printf("                *        3.���             *\n");
    printf("                *        4.ȡ��             *\n");
    printf("                *        5.����             *\n");
    printf("                *        0.�˳�             *\n");
    printf("                *                           *\n");
    printf("                *****************************\n");
    printf("                ����������ѡ��");
}

void open_account()
{
    if(count == MAX_NUM)
    {
        printf("�˻��������޷�������\n");
        return;
    }
    printf("����������������");
    scanf("%s",account[count].name);
    printf("�������������֤�ţ�");
    scanf("%s",account[count].id);
    printf("�������������룺");
    scanf("%s",account[count].password);
    printf("���������Ĵ���");
    scanf("%f",&account[count].balance);
    count++;
    printf("�����ɹ���\n");
}

void search_account()
{
    int i;
    char id[20];
    printf("��������Ҫ��ѯ�����֤�ţ�");
    scanf("%s",id);
    for(i=0;i<count;i++)
    {
        if(strcmp(account[i].id,id) == 0)
        {
            printf("������%s",account[i].name);
            printf("���֤�ţ�%s",account[i].id);
            printf("���룺%s",account[i].password);
            printf("��%.2f\n",account[i].balance);
            break;
        }
    }
    if(i == count)
    {
        printf("���޴��ˣ�\n");
    }
}

void deposit_account()
{
    int i;
    char id[20];
    float money;
    printf("��������Ҫ�������֤�ţ�");
    scanf("%s",id);
    for(i=0;i<count;i++)
    {
        if(strcmp(account[i].id,id) == 0)
        {
            printf("��������Ҫ���Ľ�");
            scanf("%f",&money);
            account[i].balance += money;
            printf("���ɹ���\n");
            break;
        }
    }
    if(i == count)
    {
        printf("���޴��ˣ�\n");
    }
}

void withdraw_account()
{
    int i;
    char id[20];
    float money;
    printf("��������Ҫȡ������֤�ţ�");
    scanf("%s",id);
    for(i=0;i<count;i++)
    {
        if(strcmp(account[i].id,id) == 0)
        {
            printf("��������Ҫȡ��Ľ�");
            scanf("%f",&money);
            if(money > account[i].balance)
            {
                printf("���㣡\n");
            }
            else
            {
                account[i].balance -= money;
                printf("ȡ��ɹ���\n");
            }
            break;
        }
    }
    if(i == count)
    {
        printf("���޴��ˣ�\n");
    }
}

void delete_account()
{
    int i;
    char id[20];
    printf("��������Ҫ���������֤�ţ�");
    scanf("%s",id);
    for(i=0;i<count;i++)
    {
        if(strcmp(account[i].id,id) == 0)
        {
            int j;
            for(j=i;j<count-1;j++)
            {
                account[j] = account[j+1];
            }
            count--;
            printf("�����ɹ���\n");
            break;
        }
    }
    if(i == count)
    {
        printf("���޴��ˣ�\n");
    }
	}
