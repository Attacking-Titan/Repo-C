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

void freelist(TYPE* f)
{
	TYPE *temp=f;
	while(f!=NULL)
	{
		f=temp;
		temp=f->next;
		free(f);
		f=NULL;
	}
	printf("����ڵ���ȫ�ͷ�\n");
}
int main()
{
	TYPE* head;
	head=create();
	print(head);
	freelist(head);
	head=NULL; 
	return 0;
}
