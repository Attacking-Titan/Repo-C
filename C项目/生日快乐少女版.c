#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#define I 20
#define R 340
#define N 20
int main()
{
	//system("mode con cols=length lines=width");���ÿ���̨�ĳ��Ϳ�
	//system("mode con cp select=437");���ô���ҳ��
	system("mode con cols=160 lines=80 ");
	system("title �����������ֿ��ף��!");
	char data[20][200]={
	{"\t\t������ף�����ڴ�˵��Ǹ��\n\n"},
	{"\t\tף�㣬����ɽ�ӣ���Ȼ��������ֵ��;Ը�㣬������������Զ�������糣��\n\n"},
	{"\t\tԸ������ů��Ը�㴺������Ը������еƣ�������ɡ��Ը��һ·�ϣ���������飡\n\n"},
	{"\t\tԸ�㱻������������Դ����㲻���ľ��Ŷ�ֻ��һ���龵���յ��Ļ�ϲ���޿ջ�ϲ��\n\n"},
	{"\t\tԸ���δ���������ʣ�����˿̿ɰ���Ŀ�⡣���������õ������У�Ը����������û�����\n\n"},
	{"\t\t��Ը����۾���ֻ���ĵ�Ц�ݣ���Ը�����µ�ÿһ�����ᣬ�����˸ж�����Ը���ÿһ���Σ�����һ���գ�\n\n"},
	{"\t\tԸ���ڱ����ʱ�����������󣬵ֿ����⣻Ը������ãʱ�����������󣬰����������������У��������ģ�����������\n\n"},
	{"\t\t��������������꣬Ը�㿴�����ճ��ӣ������������;����ǧ�������ܱ��ֳ�ϡ����ͣ�Ҫ�Ǽ�ֲ���ȥ�ˣ��һ������ġ�\n\n"},
	("\t\t���˲���ܺã��Լ�һ����Ҳ��Ҫ̫��į��ÿһ����̤ʵ�ߺ��ˡ������Ǹ��Լ����ģ�����Ϊ��˭�źú��������ף����Ͼ��ʷ׳ʵ�������\n\n"),
	{"\t\t�˴���������ͬ��Ը���»�������!\n"},
	{"#"},
	};
	int sign = 1;
	int i,j,e;
	int a;
	//sleep(value);��λs
	//Sleep(value);��λms
	printf("\n\n\n\n");
	{
	//����
	system("color 9A"); Sleep(50);
	system("color 9B"); Sleep(50);
	system("color 9C"); Sleep(50);
	system("color 9D"); Sleep(50);
	system("color 9E"); Sleep(50);
	system("color 9F"); Sleep(50);
	printf("\t\t%s\n\t\t\n",data[0]);
	//ǳ��
	system("color CA"); Sleep(50);
	system("color CB"); Sleep(50);
	system("color CC"); Sleep(50);
	system("color CD"); Sleep(50);
	system("color CE"); Sleep(50);
	system("color CF"); Sleep(50);
	printf("\t\t\t%s\n\t\t\t\n",data[0]);
	//����
	system("color BA"); Sleep(50);
	system("color BB"); Sleep(50);
	system("color BC"); Sleep(50);
	system("color BD"); Sleep(50);
	system("color BE"); Sleep(50);
	system("color BF"); Sleep(50);
	printf("\t\t\t\t%s\n\t\t\t\t\n",data[0]);
	//ǳ��
	system("color EA"); Sleep(50);
	system("color EB"); Sleep(50);
	system("color EC"); Sleep(50);
	system("color ED"); Sleep(50);
	system("color EE"); Sleep(50);
	system("color EF"); Sleep(50);
	printf("\t\t\t\t\t%s\n\t\t\t\t\t\n",data[0]);
	//����
	system("color 3A"); Sleep(50);
	system("color 3B"); Sleep(50);
	system("color 3C"); Sleep(50);
	system("color 3D"); Sleep(50);
	system("color 3E"); Sleep(50);
	system("color 3F"); Sleep(50);
	printf("\t\t\t\t%s\n\t\t\t\t\n",data[0]);
	//����
	system("color FA"); Sleep(50);
	system("color FB"); Sleep(50);
	system("color FC"); Sleep(50);
	system("color FD"); Sleep(50);
	system("color FE"); Sleep(50);
	system("color FF"); Sleep(50);
	printf("\t\t\t%s\n\t\t\t\n",data[0]);
	//����
	system("color 9A"); Sleep(50);
	system("color 9B"); Sleep(50);
	system("color 9C"); Sleep(50);
	system("color 9D"); Sleep(50);
	system("color 9E"); Sleep(50);
	system("color 9F"); Sleep(50);
	printf("\t\t%s\n\t\t\n",data[0]);
	}
	sleep(2);
	for(i = 0;i<10;i++){
		printf("\n\n\n\t\t\t\t");
		for(j = 0;j<10;j++){
		printf(">>> ");
		Sleep(5);
		}
		system("cls");
	}
	//����
	system("color 9A");
	system("color 9B");
	system("color 9C");
	system("color 9D");
	system("color 9E");
	system("color 9F");
	//����
	system("color FA");
	system("color FB");
	system("color FC");
	system("color FD");
	system("color FE");
	system("color FF");
	//ף����
	printf("\n\n\n\n");
	while(data[sign][0]!='#'){
	printf("\t\t%s\n\n",data[sign]);
	sign++;
	//����
	system("color 9A"); Sleep(50);
	system("color 9B"); Sleep(50);
	system("color 9C"); Sleep(50);
	system("color 9D"); Sleep(50);
	system("color 9E"); Sleep(50);
	system("color 9F"); Sleep(50);
	//ǳ��
	system("color CA"); Sleep(100);
	system("color CB"); Sleep(100);
	system("color CC"); Sleep(100);
	system("color CD"); Sleep(100);
	system("color CE"); Sleep(100);
	system("color CF"); Sleep(100);
	//����
	system("color BA"); Sleep(80);
	system("color BB"); Sleep(80);
	system("color BC"); Sleep(80);
	system("color BD"); Sleep(80);
	system("color BE"); Sleep(80);
	system("color BF"); Sleep(80);
	//ǳ��
	system("color EA"); Sleep(60);
	system("color EB"); Sleep(60);
	system("color EC"); Sleep(60);
	system("color ED"); Sleep(60);
	system("color EE"); Sleep(60);
	system("color EF"); Sleep(60);
	//����
	system("color FA"); Sleep(40);
	system("color FB"); Sleep(40);
	system("color FC"); Sleep(40);
	system("color FD"); Sleep(40);
	system("color FE"); Sleep(40);
	system("color FF"); Sleep(40);
	}
	printf("\t\t\t\t����һ��С��ϲ\n");
	printf("\t\t\t\t>>>");
	system("color BC");
	system("pause>NULL");
	printf("\n\n\n\t\t");
	while(1){
	for(i=1,a=I;i<I/2;i++,a--){
		for(j=(int) ( I-sqrt(I*I-(a-i)*(a-i)) );j>0;j--)
			printf(" ");
		for(e=1;e<=2*sqrt(I*I-(a-i)*(a-i));e++)
			printf("\3");
		for(j=(int)( 2*( I-sqrt(I*I-(a-i)*(a-i)) ) );j>0;j--)
			printf(" ");
		for(e=1;e<=2*sqrt(I*I-(a-i)*(a-i));e++)
			printf("\3");
		printf("\n\t\t");
		Sleep(10);
	}
	for(i=1;i<80;i++){
		if(i==25){
			printf("======�ռѻۣ����տ��֣�======");
		i+=30;
		}
	printf("\3");
	}
	printf("\n\t\t");
	for(i=1;i<=R/2;i++){
		if(i%2||i%3) continue;
		for(j=(int) ( R-sqrt(R*R-i*i) );j>0;j--)
			printf(" ");
		for(e=1;e<=2*( sqrt(R*R-i*i) - (R-2*I) );e++){
			printf("\3");
		}
	Sleep(100);
	printf("\n\t\t");
	}
}
}
