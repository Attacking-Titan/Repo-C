#include<stdio.h>
#include<stdlib.h>
#define size sizeof(TYPE)
#define TYPE struct list
TYPE
{
	int data;
	TYPE*next;
};
int n=0;
TYPE* create(void)
{
    TYPE *head,*p1,*p2;
	if((p1=(TYPE*)malloc(size))==NULL)printf("��������ʧ��");
	printf("���������ݣ�\n");
    scanf("%d",&p1->data);
    while(p1->data!=0)
	{
		n++;
		if(n==1)head=p1;
		else p2->next=p1;
		p2=p1;
		if((p1=(TYPE*)malloc(size))==NULL)printf("��������ʧ��");
		scanf("%d",&p1->data);
	}
	p2->next=NULL;
	printf("�������ɳɹ�\n");
	return head;
}

void print(TYPE* pt)
{
	printf("��ӡ����\n");
    while(pt!=NULL)
    {
    	printf("%d ",pt->data);
    	pt=pt->next;
	}
	printf("\n");
}

void insert(TYPE *it)
{
	int i=1,num;
	TYPE *ip;
	printf("�ڵ�num������ڵ㣬num=");
	scanf("%d",&num);
	while(i<num&&it!=NULL)
	{
	it=it->next;
	i++;
	}
    if((ip=(TYPE *)malloc(size))==NULL)printf("�����ڵ�ɹ�\n");
    printf("������Ҫ���������:");
    scanf("%d",&ip->data);
    ip->next=it->next;
	it->next=ip; 
}

int main()
{
	TYPE* head;
	head=create();
	print(head);
	insert(head);
	print(head); 
}
