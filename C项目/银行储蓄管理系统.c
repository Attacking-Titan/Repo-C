#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
int N;
int password;

struct consumer
{
	int num;//����
	char name[10];//�ͻ���
 int password;//����
	char address[10];//
	int telephone;//�绰
	float money;//�����Ŀ
}consumer[100];

struct Date
{
	int year;
	int month;
	int day;
}Date[100];

struct deposit//���
{
	int number;
	struct Date acction;
	char category;//����
	int acction_amount;
	char operator_name[5];
}deposit[100];
struct withdrawal//ȡ��
{
	int number;
	struct Date acction;
	char category;
	int acction_amount;
	char operator_name[5];
}withdrawal[100];

int consumer_amount;//�ͻ���Ŀ��ȫ�ֱ���
//---------���˵�--------
void mediu()
{
	printf("\n\n");
	printf("\t\t|============================|\n");
	printf("\t\t|    ��ӭʹ�����д���ϵͳ    |\n");
	printf("\t\t|============================|\n");
	printf("\t\t|    1.����Աģʽ��          |\n");
	printf("\t\t|    2.�û�ģʽ��            |\n");
	printf("\n\n");
	printf("\t\t������������(���븺����������):");
}

void read(){
	FILE *fp = fopen("D:\\data\\info.dat","rb");
	if(fp==NULL) return;
	int i = 0;
	fread(&consumer[i],sizeof(struct consumer),1,fp);
	while(!feof(fp)){
	printf("%10d %10s %10d %10s %10d %f\n",consumer[i].num, consumer[i].name, consumer[i].password, consumer[i].address, consumer[i].telephone,consumer[i].money);//����
	i++;
	fread(&consumer[i],sizeof(struct consumer),1,fp);
	}
	consumer_amount = i;
	//printf("%d\n",consumer_amount);//����
}

//--------����--------
void open_account()
{
	FILE* fp = fopen("D:\\data\\info.dat", "a");
	int i=0;
	printf("\t\t|================================|\n");
	printf("\t\t|              ����              |\n");
	printf("\t\t|================================|\n");
	printf("\t\t�����뿪��������");
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		printf("�������%d���û���ţ�\n", i + 1);
		scanf("%d", &consumer[i].num);
		printf("�������%d���û�������\n", i + 1);
		scanf("%s", consumer[i].name);
 		printf("�������%d���û�֧�����룺\n", i + 1);
		scanf("%d", &consumer[i].password);
		printf("�������%d���û���ַ��\n", i + 1);
		scanf("%s", consumer[i].address);
		printf("�������%d���û��绰��\n", i + 1);
		scanf("%d", &consumer[i].telephone);
		printf("�������%d���û��˻���\n", i + 1);
		scanf("%f", &consumer[i].money);
		system("cls");
	}
	for(i = 0;i<N;i++){
	fwrite(&consumer[i], sizeof(struct consumer), 1, fp);
	}
	fclose(fp);
	fp = NULL;
	printf("\t\t|================================|\n");
	printf("\t\t|            �����ɹ�            |\n");
	printf("\t\t|================================|\n");
	printf("\t\t�����������...\n");
}//complete

//---------��ѯ---------
void make_enquiries()
{
	FILE* fp = fopen("D:\\data\\info.dat", "rb");
	char consumer_name[10];
	struct consumer *p = (struct consumer*)malloc(sizeof(struct consumer));
	printf("\t\t|================================|\n");
	printf("\t\t|              ��ѯ              |\n");
	printf("\t\t|================================|\n");
	printf("�������ѯ�û�����:");
	scanf("%s", consumer_name);
	fread(p,sizeof(struct consumer),1,fp);
	while(!feof(fp)){
		if (strcmp(consumer_name, p->name) == 0){
		printf("%10d %10s %10d %10s %10d %f\n",p->num, p->name, p->password, p->address, p->telephone,p->money);
		break;
		}
		fread(p,sizeof(struct consumer),1,fp);
	}
	free(p);
	fclose(fp);
	printf("\t\t�����������...\n");
}//complete

//---------�޸�-----------
void alter()
{
	FILE *fp =  fopen("D:\\data\\info.dat","wb");
	int n = 0;
	char consumer_name[10];
	printf("\t\t|================================|\n");
	printf("\t\t|          �޸��û���Ϣ          |\n");
	printf("\t\t|================================|\n");
	printf("\t\t�������޸��û�������\n");
	scanf("%s", consumer_name);
	while(n<consumer_amount){
	if (strcmp(consumer_name, consumer[n].name) == 0)
	{
		printf("\t���\t����\t֧ȡ����\t��ַ\t�绰\t�˻����\n");
		printf("%10d %10s %10d %10s %10d %f\n", consumer[n].num, consumer[n].name, consumer[n].password, consumer[n].address, consumer[n].telephone,consumer[n].money);
		scanf("%d%s%d%s%d%f", &consumer[n].num, consumer[n].name, &consumer[n].password, consumer[n].address, &consumer[n].telephone,&consumer[n].money);
		break;
	}
	n++;
	}
	printf("\t\t|================================|\n");
	printf("\t\t|        �޸��û���Ϣ�ɹ�        |\n");
	printf("\t\t|================================|\n");
	for(n = 0;n<consumer_amount;n++){
	printf("\t%5d\t%5s\t%5d\t%5s\t%5d\t%f\n", consumer[n].num, consumer[n].name, consumer[n].password, consumer[n].address, consumer[n].telephone,consumer[n].money); //����
	fwrite(&consumer[n], sizeof(struct consumer), 1, fp);
	}
	fclose(fp);

}

//-----------����-----------
void dele()
{
	int i = 0, k, m;
	int j;
	char consumer_name[5];
	FILE* fp = fopen("xinxi.txt", "r");
	printf("\t\t|================================|\n");
	printf("\t\t|              ����              |\n");
	printf("\t\t|================================|\n");
	while (!feof(fp))
	{
		fread(&consumer[i], sizeof(struct consumer), 1, fp);
		i++;
	}
	fclose(fp);
	printf("\t\t�������û�����:");
	scanf("%s", consumer_name);
	for (j = 0; j < i; j++)
	{
		if (strcmp(consumer_name, consumer[j].name) == 0)
		{
			printf("�Ƿ�ȷ����������1ȷ��/0����)");
			scanf("%d", &k);
			if (k == 1)
			{
				for (m = j; m < i; m++)
					consumer[i] = consumer[i + 1];
				i--;
				//fp = fopen("xinxi.txt", "w");
				//for (m = 0; m < i; m++)
				//	fwrite(&consumer[i], sizeof(struct consumer), 1, fp);
				//fclose(fp);
				printf("\t\t|================================|\n");
				printf("\t\t|            �����ɹ�            |\n");
				printf("\t\t|================================|\n");
			}
			else
				printf("����");
		}
	}
	fclose(fp);
	fp = NULL;
}//ʵ�ֲ��ˣ�������ʾ��ͼ���ɣ���Ҫ�������

//-----------���------------

void con_deposit()
{
	int B = 0;
	float account_amount =0;
	printf("���������");
	scanf("%d", &B);
	account_amount = account_amount + B;
	printf("������ʣ���˻���%d ", &account_amount);

}

//-----------ȡ��-----------

void con_withdrawal()
{
	int C = 0;
	int account_amount = 0;
	printf("������ȡ���");
	scanf("%d", &C);
	account_amount = account_amount + C;
	printf("������ʣ���˻���%d ", &account_amount);

}

//-----------����Աģʽ-------------

	int attendant()
	{
		int j =0;
		printf("\n\n\n\n");
		printf("\t\t|================================|\n");
		printf("\t\t|          ����Աģʽ            |\n");
		printf("\t\t|================================|\n");
		printf("\t\t|          1.������              |\n");
		printf("\t\t|          2.��ѯ��              |\n");
		printf("\t\t|          3.�޸��û���Ϣ��      |\n");
		printf("\t\t|          4.������              |\n");
	    printf("\t\t|          5.�������˵�          |\n");
		printf("���������ѡ��");
		scanf("%d",&j);
		switch (j)
		{
		   case 1:
		   {
			   open_account();
			   break;
		   }
		   case 2:
		   {
			   make_enquiries();
			   break;
		   }
		   case 3:
		   {
			   alter();
			   break;
		   }
		   case 4:
		   {
			   int delete();
			   break;
		   }
		   case 5:
		   {
			   mediu();
			   break;
		   }
		}
		printf("\n\n");
		return j;
	}

//-----------�û�ģʽ---------

	int con()
	{
		int y = 0;
		printf("\n\n\n\n");
		printf("\t\t|================================|\n");
		printf("\t\t|            �û�ģʽ            |\n");
		printf("\t\t|================================|\n");
		printf("\t\t|            1.��ѯ��            |\n");
		printf("\t\t|            2.��            |\n");
		printf("\t\t|            3.ȡ�            |\n");
		printf("\t\t|            4.�������˵�        |\n");
		printf("���������ѡ��");
		scanf("%d",&y);
		switch (y)
		{
		case 1:
		{
			make_enquiries();
			break;
		}
		case 2:
		{
			con_deposit();
			break;
		}
		case 3:
		{
			con_withdrawal();
			break;
		}
		case 4:
		{
			mediu();
			break;
		}
		}
		 printf("\n\n");
         return y;
	}

//------------������-------------

	int main()
	{
	read();
    int x = 1;
    while(x>0){
	mediu();
	scanf("%d", &x);
    switch (x){
		case 1:
  		{
			attendant();//����Ա
			break;
		}
		case 2:
		{
			con();//�û�
			break;
		}
		if(x>=0)
		{
			printf("\n����ʧ�ܣ����ٴ�ѡ�����:\n");
			break;
		}
	  	}
	}
		return 0;
	}
