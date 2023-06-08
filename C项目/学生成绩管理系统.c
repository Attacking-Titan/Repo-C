/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:2023/06/23 11:47
	Description:
*/
#include<stdio.h>
#include<stdlib.h>
/* �������¼�γ���Ϣ */
struct course{
	char *name;//�洢�γ̵�����
	struct course* next;//nextָ��
};
struct course *courses = NULL;

int N = 0;//��¼�γ�����
char buffer[100];//�洢��ʱ�γ���Ϣ

struct student{
	char *name;//����
	int *score;//�ɼ�
	int total;//�ܳɼ�
	struct student *next;
};
struct student *head;

/* ����һ�ſγ� */
struct course *createCourse(char *name){
	int len = getLength(name);//��ȡ�γ����Ƴ���
	int i;
	struct course *course = (struct course *)malloc(sizeof(struct course));//����γ̽ṹ��Ŀռ�
	course->name = (char *)malloc(sizeof(char) * len + 1);//����γ����ƵĿռ�
	course->next == NULL;
	/* ���ƿγ����� */
	for(i = 0;i < len;i++){
		course->name[i] = name[i];
	}
	course->name[len] = '\0';
	return course;
};

/* ��ȡ�ַ������� */
int getLength(char *str){
	if(str == NULL) return -1;
	else {
		int i;
		for(i = 0;str[i] != '\0';i++)
			continue;
		return i;
	}
}

void addCourse(){
	//������ӿγ�����
	int n = 0;
	printf("\t\t��������ӿγ�������");
	scanf("%d",&n);
	if(n <= 0) return;//���nС�ڵ���0��ֹͣ��ӿγ�
	else N += n;
	printf("\t\t������%d�ſγ����ƣ�\n",n);
	struct course *p1 = NULL;
	struct course *p2 = NULL;
	int i = 0;
	if(courses == NULL){
       /* �����һ�ſγ���Ϣ */
       printf("\t\t1��");
	   scanf("%s",buffer);
	   courses = createCourse(buffer);//������һ�ſγ���Ϊ����ͷ�ڵ�
	   courses->next = NULL;
	   if(n == 1) return;
	   for(i = 1;i < n;i++){
	   		if(i == 1) p1 = courses;
			else p2->next = p1;
			p2 = p1;
			printf("\t\t%d��",i + 1);
			scanf("%s",buffer);
			p1 = createCourse(buffer);//�����γ�
	   }
	}
	else {
		for(i = 0;i < n;i++){
	   		if(i == 0) p1 = courses;
			else p2->next = p1;
			p2 = p1;
			printf("\t\t%d:",i + 1);
	   		gets(buffer);
			p1 = createCourse(buffer);//�����γ�
	   }
	}
	p2->next = p1;
	p1->next = NULL;
}

void printCourse(){
	if(courses == NULL){
		printf("\t\t�γ�Ϊ�գ�\n");
		return;
	}
	struct course *p = courses;
	printf("\t\t");
	while(p){
		printf("%s ",p->name);
		p = p->next;
	}
	printf("\n");
}

void createHead(){
	head = (struct student *)malloc(sizeof(struct student));
	head->name = NULL;
	head->score = NULL;
	head->next = NULL;
}

/* �Ǽǳɼ� */
void signIn(){
	int i;
    printf("\t\t������������");
	scanf("%s",buffer);
	struct student *stu = (struct student *)malloc(sizeof(struct student));
	stu->score = (int *)malloc(sizeof(int) * N);//����N��int�ռ�洢N�ſγ̵ĳɼ�
	stu->total = 0;//�ܳɼ���ʼΪ0
	int len = getLength(buffer);
	stu->name = (char *)malloc(sizeof(char) * len);//���ٴ洢�����Ŀռ�
	/* �������� */
	for(i = 0;i < len;i++)
		stu->name[i] = buffer[i];
	stu->name[len] = '\0';
	printf("\t\t%s,�������Ӧ�ɼ���\n",stu->name);
	struct course *p = courses;
	for(i = 0;i < N;i++){
		printf("\t\t%s��",p->name);
		scanf("%d",&(stu->score[i]));
		stu->total += stu->score[i];//�����ܳɼ���
		p = p->next;
	}
	//ͷ�巨���뵽������
	stu->next = head->next;
	head->next = stu;
}

void search(){
	printf("\t\t������������");
	scanf("%s",buffer);
	struct student *p1 = head->next;
	struct course *p2 = courses;
	while(p2){
		if(strcmp(p1->name,buffer) == 0){
			int i;
			for(i = 0;i < N;i++){
				printf("\t\t%s��%d\n",p2->name,p1->score[i]);
				p2 = p2->next;
			}
			printf("\t\t�ܳɼ���%d\n",p1->total);
		}
		p1 = p1->next;
	}
}

void sort(){
	struct student *t = head->next;
	int i,j,n = 0;
    while(t){
		n++;
		t = t->next;
	}//ͳ���ж��ٸ�ѧ��
	t = head->next;
	struct student *p[n];//ָ������
	for(i = 0;i < n;i++) {
		p[i] = t;
		t = t->next;
	}
	/* �������� */
	for(i = 1;i < n;i++) {
		t = p[i];
		for(j = i - 1;j >= 0;j--)
			if(t->total > p[j]->total) p[j + 1] = p[j];
			else break;
		p[j + 1] = t;
	}
	/* ��������� */
		printf("\t\t        ���а�\n ");
	for(i = 0;i < n;i++)
		printf("\t\t��%d��   %-5s   %d\n",i + 1,p[i]->name,p[i]->total);
}

void menu() {
	printf("\n");
	printf("\t\t           �˵�\n");
	printf("\t\t�˳�- - - - - - - - - - 0\n");
    printf("\t\t¼��γ���Ϣ- - - - - - 1\n");
    printf("\t\t�鿴�γ�- - - - - - - - 2\n");
    printf("\t\t�Ǽǳɼ�- - - - - - - - 3\n");
    printf("\t\t��ѯ�ɼ�- - - - - - - - 4\n");
    printf("\t\t�ɼ�����- - - - - - - - 5\n");;
    printf("\t\t>>");
}

int main(){
	createHead();//��ʼ��
	int option;
	while(1){
		menu();
		scanf("%d",&option);
		printf("\n");
		switch(option){
			case 0: printf("\t\t��л����ʹ�ã�"); return 0;
			case 1: addCourse();    break;
			case 2: printCourse();  break;
			case 3: signIn();       break;
			case 4: search();       break;
			case 5: sort();         break;
			default: printf("\t\t�������");
		}
		system("pause>NULL");
		printf("\t\t- - - - - - - - - - - - - - - - - - - - - - -\n");
	}
}

