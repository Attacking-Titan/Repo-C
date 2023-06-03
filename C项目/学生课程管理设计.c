#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 9
#define path_classinf "D:\\data\\ѧ���γ̹������\\file\\class_info.txt"
#define path_course "D:\\data\\ѧ���γ̹������\\file\\course.txt"
#define path_stu_course_select "D:\\data\\ѧ���γ̹������\\file\\stu_course_select.txt"

typedef struct class_inf
{
	char num[9];//�γ̴���
	char name[45];//�γ�����
	char property[7];//�γ����ʣ�������/ѡ�޿�/���޿�
	float total_period;//��ѧʱ����λ��ʱ
	float test_lesson;//ʵ��ѧʱ����λ��ʱ
	char semester[10];//����ѧ��,���һ��
	float credit;//ѧ��
	struct class_inf *next;//ָ��ָ����һ���γ�
}class;

struct student
{
	char name[7];//����
	int cou[N];
}stu;

struct courseinf
{
	char course[25];
}cou[N];

class *log_classinf(void)
{
	class *log,*inf,*head = NULL;
	int n = 0;
	if( ( log = (class *)malloc(sizeof(class)) ) == NULL){
		printf("malloc struct class_inf failed\n");
		return;
	}
	printf("\t\t�������#�ٻس�����¼�룺\n\n");
	printf("\t\t���\t\t�γ�����\t\t�γ�����\t\t��ѧʱ\t\tʵ��ѧʱ\t\t����ѧ��\t\tѧ��\n\t\t");
	scanf("%s",log->num);
	if(log->num[0]=='#') return head;//�������#����¼��γ�
	scanf("%s%s%f%f%s%f",
	log->name,log->property,&log->total_period,&log->test_lesson,log->semester,&log->credit);
	printf("\t\t");
	while(1)
	{
	 	n++;
	 	if(n==1)head=log;
	 	else inf->next=log;
	 	inf=log;
	 	//�����µĿռ�
	 	if( ( log = (class *)malloc(sizeof(class)) ) == NULL){
			printf("malloc struct class_inf failed\n");
			return;
		}
		scanf("%s",log->num);
  		if(log->num[0]=='#')break;//�������#����¼��γ�
		scanf("%s%s%f%f%s%f",
		log->name,log->property,&log->total_period,&log->test_lesson,log->semester,&log->credit);
		printf("\t\t");
  		while(getchar()!='\n');
	}
	inf->next=NULL;
	printf("\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -\n");
	system("pause>NULL");
	return head;
}

void print_class(class *head)
{
	if(head==NULL){
	printf("\t\t����Ϣ�ɴ�ӡ!\n");
	printf("\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -\n");
	system("pause>NULL");
	return;
	}
	class *pt=head;
	printf("\t\t%15s%50s%10s%10s%10s%10s%10s\n\n","�γ̴���","�γ�����","�γ�����","��ѧʱ","ʵ��ѧʱ","����ѧ��","ѧ��");
	while(pt){
		printf("\t\t%15s%50s%10s%10.1f%10.1f%10s%10.1f\n\n",
		pt->num,pt->name,pt->property,pt->total_period,pt->test_lesson,pt->semester,pt->credit);
		pt=pt->next;
	}
	printf("\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -\n");
	system("pause>NULL");
}//complete

void save(class *head)
{
	if(head==NULL){
		printf("\t\t����Ϣ�ɱ��棡\n");
	   	printf("\n");
		printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -");
		printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -\n");
		system("pause>NULL");
		return;
	}
	FILE *fp;
	class *p,*pt;
	p = head;
	if( ( fp = fopen(path_classinf,"a+") ) == NULL ){
		printf("open file error\n");
		return;
	}
	printf("\t\tд��:");
	while(p){
		fprintf(fp,"\n%9s%45s%10s%10.1f%10.1f%10s%10.1f",
		p->num,p->name,p->property,p->total_period,p->test_lesson,p->semester,p->credit);
		printf("\n\t\t>>> %s %s %s %.1f %.1f %s %.1f",
		p->num,p->name,p->property,p->total_period,p->test_lesson,p->semester,p->credit);
		p=p->next;
	}
	while(head){
		pt = head;
		head = head->next;
		free(pt);
	}//�ͷſռ�
	fclose(fp);
	printf("\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -\n");
	system("pause>NULL");
}//complete

class *read(void)
{
	FILE *fp;
	class *p,*pt,*head_f;
	int i;
	if( ( fp = fopen(path_classinf,"r") )==NULL ){
		printf("open class_inf.txt error\n");
		return;
	}
	if(( p=(class *)malloc(sizeof(class)) ) == NULL){
		printf("malloc struct class_inf failed\n");
		return;
	}
	fscanf(fp,"%s%s%s%f%f%s%f",
	p->num,p->name,p->property,&p->total_period,&p->test_lesson,p->semester,&p->credit);
	for(i=1;!feof(fp);i++){
		if(i==1)head_f=p;
		else pt->next=p;
		pt=p;
		if(( p=(class *)malloc(sizeof(class)) ) == NULL)
			printf("malloc struct class_inf failed\n");
		fscanf(fp,"%s%s%s%f%f%s%f",
		p->num,p->name,p->property,&p->total_period,&p->test_lesson,p->semester,&p->credit);
		//printf("%-9s%-45s%-7s%-10.1f%-10.1f%-10s%-.1f\n\n",
		//p->num,p->name,p->property,p->total_period,p->test_lesson,p->semester,p->credit);
	}
	pt->next=NULL;
	fclose(fp);
	return head_f;
}//complete

void print_f(class *head)
{
	if(head==NULL){
	printf("\t\t����Ϣ�ɴ�ӡ\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -\n");
	system("pause>NULL");
	return;
	}
	class *pt=head;
	int n = 0;
	printf("\t\t%15s%50s%10s%10s%10s%10s%10s\n\n","�γ̴���","�γ�����","�γ�����","��ѧʱ","ʵ��ѧʱ","����ѧ��","ѧ��");
	while(pt){
		printf("\t\t%15s%50s%10s%10.1f%10.1f%10s%10.1f\n\n",
		pt->num,pt->name,pt->property,pt->total_period,pt->test_lesson,pt->semester,pt->credit);
		pt=pt->next;
		n++;
	}
	printf("\t\t\t�ܹ�%d��γ���Ϣ\n",n);
	while(head){
		pt = head;
		head = head->next;
		free(pt);
	}//�ͷſռ�
	printf("\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -\n");
	system("pause>NULL");
}//complete

void minor(void){
	FILE *fp;
	if( ( fp = fopen(path_classinf,"r") )==NULL ){
		printf("open class_inf.txt error\n");
		return;
	}
	int option = 1;
	class *p = (class *)malloc(sizeof(class));
 	char property[2][5] = {"��ѡ","ѡ��"};
	do{
	printf("\t\t��ѡ��γ�����(��ѡ0/ѡ��1):");
	scanf("%d",&option);
	}while(option!=0 && option !=1);
	printf("\t\t%15s%50s%10s%10s%10s%10s%10s\n\n","�γ̴���","�γ�����","�γ�����","��ѧʱ","ʵ��ѧʱ","����ѧ��","ѧ��");
	fscanf(fp,"%s%s%s%f%f%s%f",
	p->num,p->name,p->property,&p->total_period,&p->test_lesson,p->semester,&p->credit);
	while(!feof(fp)){
		if(strcmp(p->property,property[option])==0) {
			printf("\t\t%15s%50s%10s%10.1f%10.1f%10s%10.1f\n\n",
			p->num,p->name,p->property,p->total_period,p->test_lesson,p->semester,p->credit);
		}
		fscanf(fp,"%s%s%s%f%f%s%f",
		p->num,p->name,p->property,&p->total_period,&p->test_lesson,p->semester,&p->credit);
	}
	free(p);
	fclose(fp);
}

void credit_sort(){
	FILE *fp;
	class *p,*pt,*head_f,*temp;
	int i,j,n = 0;
	if( ( fp = fopen(path_classinf,"r") )==NULL ){
		printf("open class_inf.txt error\n");
		return;
	}
	p=(class *)malloc(sizeof(class));
	fscanf(fp,"%s%s%s%f%f%s%f",
	p->num,p->name,p->property,&p->total_period,&p->test_lesson,p->semester,&p->credit);
	for(i=1;!feof(fp);i++,n++){
		if(i==1) head_f=p;
		else pt->next=p;
		pt=p;
		if(( p=(class *)malloc(sizeof(class)) ) == NULL)
			printf("malloc struct class_inf failed\n");
		fscanf(fp,"%s%s%s%f%f%s%f",
		p->num,p->name,p->property,&p->total_period,&p->test_lesson,p->semester,&p->credit);
	}
	pt->next=NULL;
	class *credit_p[n];
	p = head_f;
	for(i = 0;p;i++){
		credit_p[i] = p;
		p = p->next;
	}
	//����ָ������
	for(i = 1;i<n;i++){
		temp = credit_p[i];
		for(j = i-1;j>=0;j--)
			if(temp->credit > credit_p[j]->credit) credit_p[j+1] = credit_p[j];
				else break;
		credit_p[j+1] = temp;
	}
	//��ӡ
	printf("\t\t%15s%50s%10s%10s%10s%10s%10s\n\n","�γ̴���","�γ�����","�γ�����","��ѧʱ","ʵ��ѧʱ","����ѧ��","ѧ��");
	for(i = 0;i<n;i++){
		printf("\t\t%15s%50s%10s%10.1f%10.1f%10s%10.1f\n\n",
		credit_p[i]->num,credit_p[i]->name,	credit_p[i]->property,credit_p[i]->total_period,credit_p[i]->test_lesson,credit_p[i]->semester,credit_p[i]->credit);
	}
	while(head_f){
		pt = head_f;
		head_f = head_f->next;
		free(pt);
	}//�ͷſռ�
	printf("\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -\n");
	system("pause>NULL");
}

void search()
{
	FILE *fp;
	int i ,j ,flag = 0;
	class *p;
	char str[45];
	if( ( fp = fopen(path_classinf,"r") )==NULL ){
		printf("open class_inf.txt error\n");
		return;
	}
	p = (class *)malloc(sizeof(class));
	printf("\t\t��������������:\n\t\t>>");
	scanf("%s",str);
	while(getchar()!='\n');
	printf("\t\t%15s%50s%10s%10s%10s%10s%10s\n\n","�γ̴���","�γ�����","�γ�����","��ѧʱ","ʵ��ѧʱ","����ѧ��","ѧ��");
	fscanf(fp,"%s%s%s%f%f%s%f",
	p->num,p->name,p->property,&p->total_period,&p->test_lesson,p->semester,&p->credit);
	while(!feof(fp))
	{
		i = 0,j = 0;
		while(i<strlen(str) && j<strlen(p->name)){
			if(str[i]==p->name[j]){
				i++;
				j++;
			}
				else {
				j = j-i+1;
				i = 0;
				}
		}//����ƥ��
		if(i==strlen(str)){
			printf("\t\t%15s%50s%10s%10.1f%10.1f%10s%10.1f\n\n",
			p->num,p->name,p->property,p->total_period,p->test_lesson,p->semester,p->credit);
			flag = 1;
		}
   		fscanf(fp,"%s%s%s%f%f%s%f",
		p->num,p->name,p->property,&p->total_period,&p->test_lesson,p->semester,&p->credit);
	}
	if(flag==0)printf("\t\t�������������!");
	free(p);
	printf("\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -\n");
	system("pause>NULL");
}//complete

void semester_search()
{
	FILE *fp;
	int i ,j ,flag = 0;
	class *p;
	char str[45];
	if( ( fp = fopen(path_classinf,"r") )==NULL ){
		printf("open class_inf.txt error\n");
		return;
	}
	p = (class *)malloc(sizeof(class));
	printf("\t\t������ѧ��:\n\t\t>>");
	scanf("%s",str);
	while(getchar()!='\n');
	printf("\t\t%15s%50s%10s%10s%10s%10s%10s\n\n","�γ̴���","�γ�����","�γ�����","��ѧʱ","ʵ��ѧʱ","����ѧ��","ѧ��");
	fscanf(fp,"%s%s%s%f%f%s%f",
	p->num,p->name,p->property,&p->total_period,&p->test_lesson,p->semester,&p->credit);
	while(!feof(fp))
	{
		i = 0,j = 0;
		while(i<strlen(str) && j<strlen(p->semester)){
			if(str[i]==p->semester[j]){
				i++;
				j++;
			}
				else {
				j = j-i+1;
				i = 0;
				}
		}//����ƥ��
		if(i==strlen(str)){
			printf("\t\t%15s%50s%10s%10.1f%10.1f%10s%10.1f\n\n",
			p->num,p->name,p->property,p->total_period,p->test_lesson,p->semester,p->credit);
			flag = 1;
		}
   		fscanf(fp,"%s%s%s%f%f%s%f",
		p->num,p->name,p->property,&p->total_period,&p->test_lesson,p->semester,&p->credit);
	}
	if(flag==0)printf("\t\t�������������!");
	free(p);
	printf("\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -\n");
	system("pause>NULL");
}//complete

void courseinf(void)
{
	FILE *fp;
	int i,n;
	if( ( fp=fopen(path_course,"r") ) == NULL )
	printf("open course.txt failed\n");
	for(i=0;!feof(fp);i++)
	fscanf(fp,"%s",&cou[i].course);
	n = i;
	for(i=0;i<n;i++)
	printf("%-21s",cou[i].course);
}

void course_select(void)
{
	FILE *fp=fopen(path_stu_course_select,"a");
	int i;
	while(1)
	{
		printf("\t\t\t\t\t\t\t\t----------����#����ѡ��---------\n");
		printf("\t\t����:");
		scanf("%s",stu.name);
		if(stu.name[0]=='#')break;
		printf("\t\t\t\t\t\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
		printf("\t\t\t\t\t\t\t\t* * * ���ڶ�Ӧ�γ�������1��0��1��ʾѡ��0��ʾ��ѡ * * *\n");
		printf("\t\t\t\t\t\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
		courseinf();
		printf("\n>>");
		for(i=0;i<N;i++)
		scanf("%d",&stu.cou[i]);
		printf("\n\t\t\t\t\t\t\t\t- - - - -<%s>ѡ�γɹ�- - - - -\n",stu.name);
		printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -");
		printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -\n");
		fprintf(fp,"%s ",stu.name);
		for(i=0;i<N;i++){
		fprintf(fp,"%d ",stu.cou[i]);
		}
		fprintf(fp,"\n");
	}
}

void search_select()
{
	FILE *fp;
	int i,j;
	char name[7];
	fp=fopen(path_stu_course_select,"r");
	printf("\t\t����\n\t\t>>");
	scanf("%s",name);
	while(!feof(fp)){
		fscanf(fp,"%s",stu.name);
		for(j=0;j<N;j++) fscanf(fp,"%d",&stu.cou[j]);
		if(name[0]==stu.name[0]&&name[1]==stu.name[1]){
			printf("\t\t�𾴵�%s,����������ѡ����Ϣ��\n",name);
			printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -");
			printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -\n");
			courseinf();
			printf("\n    ");
			for(j=0;j<N;j++)
				printf("%-21d",stu.cou[j]);
			printf("\n");
			printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -");
			printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -\n");
		return;
		}
	}
	printf("\t\t�޲�ѯ���\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -\n");
}//complete

void stu_select_inf(void)
{
	FILE *fp;
	int i,j;
	printf("���� ");
	courseinf();
	printf("\n");
	fp=fopen(path_stu_course_select,"r");
	while(!feof(fp)){
		fscanf(fp,"%s",stu.name);
		for(j=0;j<N;j++)
		fscanf(fp,"%d",&stu.cou[j]);
		printf("%-9s",stu.name);
		for(j=0;j<N;j++)
		printf("%-21d",stu.cou[j]);
		printf("\n\n");
	}
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -\n");
	system("pause>NULL");
}

int main()
{
	class *head = NULL,*head_f;
	int option,len,i,admin;
	char str[15];
	system("mode con cols=200 lines=1000");
	while(1)
	{
	 printf("\n\n");
	 printf("\t\t________________________________________________________________________\n") ;
	 printf("\t\t|                                                                      |\n");
	 printf("\t\t| > > > > > > > > > > > > > ѧ���γ̹���ϵͳ < < < < < < < < < < < < < |\n");
	 printf("\t\t|______________________________________________________________________|\n\n") ;
	 printf("\t\t                  �˵�>>>\n");
	 printf("\t\t                  0 - - - - - -�˳�\n\n");
	 printf("\t\t                  1 - - - - - -�鿴ȫ���γ���Ϣ\n\n");
	 printf("\t\t                  2 - - - - - -���γ����ʲ鿴\n\n");
	 printf("\t\t                  3 - - - - - -��ѧ�ֲ鿴\n\n");
	 printf("\t\t                  4 - - - - - -�����γ�\n\n");
	 printf("\t\t                  5 - - - - - -ѡ��\n\n");
	 printf("\t\t                  6 - - - - - -��ѯ��ѡ����ѡ��\n\n");
	 printf("\t\t                  7 - - - - - -��ѧ�ڲ�ѯ\n\n");
	 printf("\t\t                  8 - - - - - -����Աģʽ\n\n");
     printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -");
	 printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - -\n");
	 printf("\t\t>>");
	 scanf("%d",&option);
		if(option==8)
		{
			while(admin!=32768){
    		printf("\t\t________________________________________________________________________\n") ;
			printf("\t\t|                                                                      |\n");
			printf("\t\t| > > > > > > > > > > > > > > >����Աģʽ< < < < < < < < < < < < < < < |\n");
			printf("\t\t|______________________________________________________________________|\n\n") ;
			printf("\t\t\t\t-1- - - - - - - - - - - �˳�����Աģʽ\n\n");
			printf("\t\t\t\t1 - - - - - - - - - - - - - ¼��γ���Ϣ\n\n");
			printf("\t\t\t\t2 - - - - - - - - - - - - - ���鵱ǰ����Ŀγ���Ϣ\n\n");
			printf("\t\t\t\t3 - - - - - - - - - - - - - ���浱ǰ����Ŀγ���Ϣ\n\n");
			printf("\t\t\t\t4 - - - - - - - - - - - - - �鿴ѧ��ѡ����Ϣ\n\n");
			printf("\t\t>>");
			scanf("%d",&admin);
			if(admin==1) head = log_classinf();
				else if(admin==2) print_class(head);
					else if(admin==3) save(head);
						else if(admin==4) stu_select_inf();
							else if(admin==-1) {
								printf("\t\t- - - - -�˳��ɹ�- - - - -\n");
								break;
							}
			system("cls");
			}
		 }
		else switch(option)
		{
			head_f = NULL;
			case 0:return 0;
			case 1:head_f=read();
				   print_f(head_f);  break;
			case 2:minor();          break;
			case 3:credit_sort();    break;
			case 4:search(head_f);   break;
			case 5:course_select();  break;
			case 6:search_select();	 break;
			case 7:semester_search();break;
		}
	}
}
