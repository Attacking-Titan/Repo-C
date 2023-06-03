#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct word{
	char Eng[15];
	char meaning[20];
	struct word *next;
}dict;

void menu(void){
	printf("************************************\n");
	printf(">>>>>>>>>>Ӣ��ʵ��Ű�ϵͳ<<<<<<<<<<\n");
	printf("************************************\n");
	printf("      �˵�:\n");
	printf("      ¼��- - - - - - - - - -N\n");
	printf("      ɾ��- - - - - - - - - -D\n");
	printf("      ���- - - - - - - - - -B\n");
	printf("      ����- - - - - - - - - -S\n");
	printf("      A-Z - - - - - - - - - -P\n");
	printf("      ����- - - - - - - - - -R\n");
	printf("      ��ϰ- - - - - - - - - -V\n");
	printf("      ����- - - - - - - - - -T\n"); 
	printf("      �˳�- - - - - - - - - -Q\n");
	printf("      >>");
}

int input(){
 	int n;
	FILE *fp;
	if((fp = fopen("D:\\data\\dictionary.txt","a"))==NULL){
		printf("----��dictionary.txtʧ��!----\n");
		return 0;
	}
	printf("- - - - - - - - - - - - - - - - -\n");
	while(dict.Eng[0]!='#'){
		printf("���ʣ�");
		scanf("%s",dict.Eng);
		printf("���壺");
		scanf("%s",dict.meaning); 
		fprintf(fp,"%15s%20s\n",dict.Eng,dict.meaning);
		printf("- - - - - - - - - - - - - - - - -\n");
	}
	while(getchar()!='\n')
		continue;
	fclose(fp);
	return 1;
}

void del(void){
	FILE *fp;
	int n = 0,i;
	struct word *p1,*p2,*head,*pre,*temp;
	if((fp = fopen("D:\\data\\dictionary.txt","r"))==NULL){
	printf("----��dictionary.txtʧ��!----\n");
	return;
	}
	p1 = (struct word *)malloc(sizeof(struct word));
	fscanf(fp,"%20s%15s",p1->Eng,p1->meaning);
	printf("��ȡ��\n*%s\n",p1->Eng);//���� 
	while(p1->Eng[0]!='#'){
		n++;
		if(n==1) head = p1;
		else p2->next = p1;
		p2 = p1;
		p1 = (struct word *)malloc(sizeof(struct word));
		fscanf(fp,"%15s%20s\n",p1->Eng,p1->meaning);
		printf("*%s\n",p1->Eng);//���� 
	}
	p2->next = NULL;
	fclose(fp);
	p1 = head;//������ͷ��������м�� 
	printf("- - - - - - - - - - - - - - - - -\n");
	while(p1->next!=NULL){
		pre = p1;
		p2 = p1->next;
		//printf("@������%s\n",p1->Eng);//���� 
		while(p2!=NULL){
			//printf("$�Ƚϴ���%s\n",p2->Eng);//���� 
			if(strcmp(p1->Eng,p2->Eng)==0)//��������ظ��ĵ��� 
			{
				temp = p2;
				pre->next = p2->next;//ɾ����� 
				p2 = p2->next;
				free(temp);//�ͷſռ� 
				temp = NULL;
				continue; 
			}
			p2 = p2->next;
			pre = pre->next;
		}
		p1 = p1->next;
		//printf("- - - - - - - - - - - - - - - - -\n");//���� 
	}
	//����������������д�� 
	if((fp = fopen("D:\\data\\dictionary.txt","w"))==NULL){
	printf("----��dictionary.txtʧ��!----\n");
	return;
	}
	p1 = head;
	printf("д�룺\n");
	while(p1!=NULL){
		printf(">>>%s %s\n",p1->Eng,p1->meaning);
		fprintf(fp,"%15s%20s\n",p1->Eng,p1->meaning);
		p1 = p1->next;
	}
	strcpy(dict.Eng,"#");
	strcpy(dict.meaning,"#");
	fprintf(fp,"%15s%20s",dict.Eng,dict.meaning);
	fclose(fp);
	printf("--------ɾ���ظ����ʳɹ���--------\n");
	system("pause>NULL");//���� 
}

void scan(void){
	FILE *fp;
	if((fp = fopen("D:\\data\\dictionary.txt","r"))==NULL){
	printf("--------��dictionary.txtʧ��!--------\n");
	return;
	}	
	printf("����                ����\n");
	while(dict.Eng[0]!='#'){
	fscanf(fp,"%15s%20s",dict.Eng,dict.meaning);
	printf("%-20s%-s\n\n",dict.Eng,dict.meaning);
	}
	fclose(fp);
}

void sort(){
	FILE *fp;
	int n = 0;
	struct word *p1,*p2,*head,*pt,*pre,*_pre,*after;
	//_preָ��p1ǰһ����㣬preָ��ptǰһ����� 
	//afterָ��p1�ĺ�һ����� 
	if((fp = fopen("D:\\data\\dictionary.txt","r"))==NULL){
	printf("      ----��dictionary.txtʧ��!----\n");
	return;
	}
	p1 = (struct word *)malloc(sizeof(struct word));
	fscanf(fp,"%15s%20s",p1->Eng,p1->meaning);
	//printf("*��ȡ>>%s %s\n",p1->Eng,p1->meaning);//���� 
	while(p1->Eng[0]!='#'){
		n++;
		if(n==1) head = p1; 
		else p2->next = p1;
		p2 = p1;
		p1 = (struct word *)malloc(sizeof(struct word));
		fscanf(fp,"%15s%20s",p1->Eng,p1->meaning);
		//printf("*��ȡ>>%s %s\n",p1->Eng,p1->meaning);//���� 
	}
	p2->next = NULL;
	fclose(fp);
	//ͷ�巨����һ�������ͷ��� 
	//printf("@��ʱͷ��㣺%s %s\n",head->Eng,head->meaning);//���� 
	//printf("&�����µ�ͷ���:");//���� 
	pre = (struct word *)malloc(sizeof(struct word));
	strcpy(pre->Eng,"aaa"); 
	strcpy(pre->meaning,"ͷ");
	pre->next = head;
	head = pre; 
	//printf("%s %s\n",head->Eng,head->meaning);
	printf("- - - - - - - -��A-Z��������- - - - - - - -\n");//���� 
	//ѡ������
	_pre = head;
	p1 = head->next;//��ͷ�����һ����ʼ 
	while(p1->next != NULL){
		//printf(" @ ѡ��λ��%s\n",p1->Eng);//���� 
		p2 = p1->next; 
		pt = p1;
		//�������ҳ����ʵ��ֵ�����С���Ǹ����
		while(p2!=NULL){
			if(strcmp(pt->Eng,p2->Eng)>0) pt = p2;//��������ֵ���С��pt->Eng,����ַ����pt 
			p2 = p2->next; 
		}
		//printf(" $ ����ѭ�����ֵ�����С�ʣ�%s\n",pt->Eng); 
		//�ҵ�����Ϊ��С�ֵ���Ľ���ǰһ�����
		if(strcmp(pt->Eng,p1->next->Eng)==0)//��������ֵ�����С�Ľ����p1��һ����� 
		{
			strcpy(dict.Eng,pt->Eng);
			strcpy(dict.meaning,pt->meaning);
			strcpy(pt->Eng,p1->Eng);
			strcpy(pt->meaning,p1->meaning);
			strcpy(p1->Eng,dict.Eng);
			strcpy(p1->meaning,dict.meaning);
			printf("%s <- - - - -> %s\n",p1->Eng,pt->Eng);
			//printf("- - - - - - - - - - - - - - - - - - - - - -\n");//���� 
			_pre = _pre->next;
			p1 = pt;
			continue;
		}
		else if(strcmp(pt->Eng,p1->Eng)!=0){
			p2 = p1;
			//�ҳ�pt��ǰһ����� 
			while(p2!=NULL){
				if(strcmp(p2->next->Eng,pt->Eng)==0){
					pre = p2;
					break;
				}
			p2 = p2->next;
			}
			//�������λ��
			if(p1->next==NULL) after = NULL;
				else after = &(*(*p1).next);
			//��p1�ƶ���pt��λ�� 
			p1->next = pt->next;
			pre->next = p1;
			//��pt�ƶ���p1��λ��
			pt->next = &(*after);
			_pre->next = pt;
			printf("%s <- - - - -> %s\n",_pre->next->Eng,pre->next->Eng);//���� 
		}
		_pre = _pre->next;//��¼p1ǰһ����� 
		p1 = pt->next;
		//printf("pt->next->Eng:%s\n",pt->next->Eng);//���� 
		//printf("- - - - - - - - - - - - - - - - - - - - - -\n");//���� 
		//system("pause>NULL");//���� 
	}
	printf("- - - - - - - - - - - - - - - - - - - - - -\n");
	//������õ����ݴ洢���ļ���
	if((fp = fopen("D:\\data\\dictionary_sort.txt","w"))==NULL){
	printf("----��dictionary_sort.txtʧ��!----\n");
	return;
	}
	p1 = head->next;
	printf("д�룺\n");
	while(p1!=NULL){
		printf(">>>%s %s\n",p1->Eng,p1->meaning);//����
		fprintf(fp,"%15s%20s\n",p1->Eng,p1->meaning); 
		p1 = p1->next;
	}
	strcpy(dict.Eng,"#");
	strcpy(dict.meaning,"#");
	fprintf(fp,"%14s%20s",dict.Eng,dict.meaning);
	fclose(fp);
	printf("-------��A-Z�洢�ֵ�ɹ�!-------\n");
}

void print_sort(void){
	FILE *fp;
	if((fp = fopen("D:\\data\\dictionary_sort.txt","r"))==NULL){
	printf("----��dictionary_sort.txtʧ��!----\n");
	return;
	}
	printf("       ����                  ����\n");
	while(dict.Eng[0]!='#'){
	fscanf(fp,"%15s%20s",dict.Eng,dict.meaning);
	printf("%15s%20s\n\n",dict.Eng,dict.meaning);
	}
	fclose(fp);
	printf("--------��ӡ�ɹ�!--------\n");
} 

void reserve(void){
	FILE *fp,*f;
	if((f = fopen("D:\\data\\dictionary_sort.txt","r"))==NULL){
	printf("----��dictionary_sort.txtʧ��!----\n");
	return;
	}
	if((fp = fopen("D:\\data\\back_up.txt","w"))==NULL){
	printf("----��back_up.txtʧ��!----\n");
	return;
	}
	while(dict.Eng[0]!='#'){
		fscanf(f,"%15s%20s",dict.Eng,dict.meaning);
		printf("%15s\n",dict.Eng);
		fprintf(fp,"%15s%20s\n",dict.Eng,dict.meaning);
	}
	fclose(fp);
	fclose(f);
	printf("--------���ݳɹ�--------\n");
}

void review(void){
	FILE *fp;
	char option[6];
	int i,count,add; 
	system("cls");
	if((fp = fopen("D:\\data\\dictionary.txt","r"))==NULL){
	printf("------��dictionary.txtʧ��!------\n");
	return;
	}
	printf("�ף���ѡ����Ҫ��ϰ�ĵ��ʸ�����\n>>");
	scanf("%d",&count);
	for(i = 0;i<count;i++){
		printf(">>>�Ѹ�ϰ��%d\n",i);
		fscanf(fp,"%15s%20s",dict.Eng,dict.meaning);
		printf("���ʣ�%s\n",dict.Eng);
		system("pause>NULL");
		printf("����:%s\n",dict.meaning); 
		system("pause>NULL");
		system("cls");
	}
	printf("�ף����Ѿ���ϰ��%d������\n",count);
	while(1){
		printf("���Ƿ�Ҫ������ϰ�������ĵ����أ�(Y/N)\n�����Ҫ���¸�ϰǰ��ĵ��ʣ������˵\"�õ�\"\n>>");
		scanf("%s",option);
		while(getchar()!='\n')
			continue;
		if(option[0]=='Y') {
			printf("�ף���ѡ����Ҫ��ϰ�ĵ��ʸ�����\n>>");
			scanf("%d",&add);
			for(i = 0;i<add;i++){
				printf(">>>�Ѹ�ϰ��%d\n",i);
				fscanf(fp,"%15s%20s",dict.Eng,dict.meaning);
				printf("���ʣ�%s\n",dict.Eng);
				system("pause>NULL");
				printf("����:%s\n",dict.meaning);
				system("pause>NULL");
				system("cls");
			}
			count+=add;
			printf("��ϲ���Ѹ�ϰ��%d������\n",count);
		}
		else if(strcmp(option,"�õ�")==0){
			fclose(fp);
			if((fp = fopen("D:\\data\\dictionary.txt","r"))==NULL){
			printf("------��dictionary.txtʧ��!------\n");
			return;
			}
			printf("�ף���ѡ����Ҫ��ϰ�ĵ��ʸ�����\n>>");
			scanf("%d",&count);
			for(i = 0;i<count;i++){
				printf(">>>�Ѹ�ϰ��%d\n",i);
				fscanf(fp,"%15s%20s",dict.Eng,dict.meaning);
				printf("���ʣ�%s\n",dict.Eng);
				system("pause>NULL");
				printf("����:%s\n",dict.meaning); 
				system("pause>NULL");
				system("cls");
			}
			printf("�ף����Ѿ���ϰ��%d������\n",count);
		} 
		else {
			printf("��л�׵Ĺ�ˣ���ӭ�´ι���!\n");
			return;
		}
	}
}

void typing(void){
	FILE *fp;
	char option[3],prac[20],_prac[20];
	int i,num;
	float t = 0.0;
	system("cls");
	if((fp = fopen("D:\\data\\dictionary.txt","r"))==NULL){
	printf("------��dictionary.txtʧ��!------\n");
	return;
	}
	printf("�ף���ӭ��ʹ�ô���ϵͳ����ѡ��ģʽ(Ӣ��/����/��Ӣ):\n");
	printf("Ӣ��- - - - - - - - - - - - - -En\n");
	printf("����- - - - - - - - - - - - - -Ch\n");
	printf("��Ӣ- - - - - - - - - - - - - -EC\n>>");
	scanf("%s",option);
	while(getchar()!='\n')
		continue;
	if(strcmp(option,"En")==0){
		printf("�ף�����������Ҫ��ϰ�ĵ�����:\n>>");
		scanf("%d",&num);
		for(i = 0;i<num;i++){
			fscanf(fp,"%15s%20s",dict.Eng,dict.meaning);
			printf("%s\t",dict.Eng);
			scanf("%s",prac);
			while(getchar()!='\n')
				continue;
			if(strcmp(prac,dict.Eng)==0) t++;
		}
		printf("�ף�������ȷ����%.2f%%,��ȷƴд%.0f��������ƴд%d��\n",(100*t)/num,t,num-t);
	}
	else if(strcmp(option,"Ch")==0){
		printf("�ף�����������Ҫ��ϰ�ĵ�����:\n>>");
		scanf("%d",&num);
		for(i = 0;i<num;i++){
			fscanf(fp,"%15s%20s",dict.Eng,dict.meaning);
			printf("%s\t",dict.meaning);
			scanf("%s",prac);
			while(getchar()!='\n')
				continue;
			if(strcmp(prac,dict.meaning)==0) t++;
		}
		printf("�ף�������ȷ����%.2f%%,��ȷƴд%.0f��������ƴд%d��\n",(100*t)/num,t,num-t);
	}
	else{
		printf("�ף�����������Ҫ��ϰ�ĵ�����:\n>>");
		scanf("%d",&num);
		for(i = 0;i<num;i++){
			fscanf(fp,"%15s%20s",dict.Eng,dict.meaning);
			printf("%s %s\t",dict.Eng,dict.meaning);
			scanf("%s%s",prac,_prac);
			while(getchar()!='\n')
				continue;
			printf("- - - - - - - - - - - - - - - - - - - - -\n");
			if(strcmp(prac,dict.Eng)==0 && strcmp(_prac,dict.meaning)==0) t++;
		}
		printf("�ף�������ȷ����%.2f%%,��ȷƴд%.0f��������ƴд%d��\n",(100*t/num),t,num-t);
	}
	printf("��,������ϰ��������ӭ���ٴι���\n");
	system("pause>NULL");
}

int main(){
	char option;
	while(1){
		menu();
		scanf("%c",&option);
		getchar();
		switch(option){
		case 'N':
		if(input()==1)printf("--------¼��ɹ�!--------\n");
			else printf("--------¼��ʧ��!--------\n");
		break;
		case 'D':del();break;
		case 'B':scan();break;
		case 'S':sort();break;
		case 'P':print_sort();break;
		case 'R':reserve();break;
		case 'V':review();break;
		case 'T':typing();break;
		case 'Q':printf("\n---------��л����ʹ��!---------\n");return 0;
		default:
		printf("----ѡ�������������������!----\n");
		while(getchar()!='\n')
			continue;
		}
	}
}
