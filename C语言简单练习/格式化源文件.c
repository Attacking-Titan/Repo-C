#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char file_addr[50],ch;
	start:
	printf("������Ҫ�鿴�Ĵ����ı���ַ:\n>>");
	scanf("%s",file_addr);
	if( (fp = fopen(file_addr,"r"))==NULL ) {
		printf("\n- - - - -\"%s\"�޷���- - - - -",file_addr);
		system("pause>NULL");
		system("cls");
		goto start;
	}
	ch = fgetc(fp);
	while(!feof(fp)) {
		printf("%c",ch);
		ch = fgetc(fp);
	}
	return 0;
}
