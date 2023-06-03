#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 81
struct namect{
	char *fname;//ʹ��ָ�� 
	char *lname;
	int letters;
};
void getinfo(struct namect *);//�����ڴ� 
void makeinfo(struct namect *);//�������ֳ��� 
void showinfo(const struct namect *);
void cleanup(struct namect *);//���ú���ʱ�ͷ��ڴ�
char * s_gets(char *st,int n);//���� 
int main(){
	struct namect person;
	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);
	return 0;
} 
void getinfo(struct namect *pst){
	char temp[SIZE];
	printf("please enter your first name.\n");
	s_gets(temp,SIZE);//�����ڴ��Դ洢��
	pst->fname = (char *)malloc(strlen(temp)+1);//������������̬�ڴ���䵽�ڴ���
	strcpy(pst->fname,temp);
	printf("please enter your last name.\n");
	s_gets(temp,SIZE);
	pst->lname = (char *)malloc(strlen(temp)+1);
	strcpy(pst->lname,temp); 
}
void makeinfo(struct namect *pst){
	pst->letters = strlen(pst->fname)+strlen(pst->lname);
}
void showinfo(const struct namect *pst){
	printf("%s %s,your name contain %d letters.\n",
	pst->fname,pst->lname,pst->letters);
}
void cleanup(struct namect *pst){
	free(pst->fname);
	free(pst->lname);
}
char *s_gets(char *st,int n){
	char *ret_val;
	char *find;
	ret_val = fgets(st,n,stdin);
	if(ret_val){
		find = strchr(st,'\n');//���һ��з�
		if(find)
			*find = '\0';//�ڴ˴�����һ�����ַ� 
		else 
			while(getchar()!='\n')//���������е�ʣ�ಿ�� 
				continue;
	}
	return ret_val;
}
//��������
//Floresiensis
//Mann 

