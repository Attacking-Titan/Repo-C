#include<stdio.h>
int main()
{
	int num;//���
	char name[30];//�γ�����
	char property[7];//�γ����ʣ�������/ѡ�޿�/���޿� 
	short total_period;//��ѧʱ����λ��ʱ 
	short week_lesson;//�ڿ�ѧʱ����λ��ʱ 
	short test_lesson;//ʵ��ѧʱ����λ��ʱ 
	char semester[7];//����ѧ��,���һ�� 
	short credit;//ѧ��
	printf("��� ->���γ����ơ�-> �γ����� -> ��ѧʱ -> �ڿ�ѧʱ -> ʵ��ѧʱ -> ����ѧ�� -> ѧ��\n");
	scanf("%d%30s%6s%hd%hd%hd%6s%hd",&num,name,property,&total_period,&week_lesson,&test_lesson,semester,&credit);
	printf("%-7d %-14s %-12s %-10hd %-10hd %-10hd %-10s %-5hd\n",num,name,property,total_period,week_lesson,test_lesson,semester,credit);
	return 0;
}
