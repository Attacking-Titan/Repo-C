#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fp;
	char file_addr[50];
	printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("�ļ�����ʽ:\n\n");
	printf("�����ı��ļ�:filename.txt\n\n");
	printf("�����������ļ�:filename\n\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("����·����ʽ(�Խ����������ļ�����):\n\n");
	printf("��ĳ�̸�Ŀ¼�����ļ�:�̷�\\\\filename					���磺D:\\\\file\n\n");
	printf("��ĳ��Ŀ¼�µ���Ŀ¼�н����ļ�:�̷�\\\\�ļ�����\\\\...\\\\filename		���磺D:\\\\folder\\\\data\\\\filename\n\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf(">>>ʹ��ǰ����ϸ��ȡ������Ϣ,�س���ʼ�����ļ�");
	system("pause>NULL");
	while(getchar()!='\n')
		continue;
	printf("������Ҫ�������ļ���·��(#��������):\n>>");
	scanf("%s",file_addr);
	while(file_addr[0]!='#'){
	fp = fopen(file_addr,"w");
	fclose(fp);
	printf("����\"%s\"�ɹ�\n",file_addr);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	while(getchar()!='\n')
		continue;
	printf("������Ҫ�������ļ���·��(#��������):\n>>");
	scanf("%s",file_addr);
	}
	return 0;
}
