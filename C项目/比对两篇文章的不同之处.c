/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:26/03/23 15:42
	Description:�ȶ���ƪ�����еĲ�֮ͬ��
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define std "D:\\�ӵ���\\Documents\\ƽ�������--Up_TyrantLucifer.c"
#define ero "D:\\�ӵ���\\Documents\\ƽ�������-AVL��.c"
#define LEN 100000
void check(FILE *fp1,FILE *fp2){
	char stdAtc[LEN];//��׼�ļ���Ҳ�����������ο����ļ�
	char eroAtc[LEN];//�д�����ļ���Ҳ���Ǻͱ�׼�ļ����бȶԣ��ҳ������в�ͬ�ĵط�
	char ch;
	int i,j;
	for(i = 0;!feof(fp1);i++){
		stdAtc[i] = fgetc(fp1);
	}
	stdAtc[i] = '\0';
	for(i = 0;!feof(fp2);i++){
		eroAtc[i] = fgetc(fp2);
	}
	eroAtc[i] = '\0';
	//�ȶ�
	int LEN1 = strlen(stdAtc);
	_Bool flag1,flag2;
	int LEN2 = strlen(eroAtc);
	for(i = 0,j = 0;i < LEN1 && j < LEN2;){
		flag1 = 0,flag2 = 0;
		if(eroAtc[i] == ' ' || eroAtc[i] == '\n' || eroAtc[i] == '\t') {
			i++;
			printf("%c",eroAtc[i]);
		}
			else flag1 = 1;
	    if(stdAtc[j] == ' ' || stdAtc[j] == '\n' || stdAtc[i] == '\t') {
	    	j++;
		}
			else flag2 = 1;
		if(flag1 && flag2){//���eroAtc[i]��stdAtc[i]����Ϊ�ո��\n��\r
			i++;
			j++;
			if(eroAtc[i] == stdAtc[j]) printf("%c",eroAtc[i]);//�ȶԳɹ�
				else printf("?");//�ȶԲ��ɹ�
		}
	}
	fclose(fp1);
	fclose(fp2);
}
int main(){
	FILE *fp1,*fp2;
	fp1 = fopen(std,"r");
	fp2 = fopen(ero,"r");
	check(fp1,fp2);
	return 0;
}

