#include<stdio.h>
#include<math.h>
#define PR(X,...) printf("Message" #X ":" __VA_ARGS__)

/*
    ͨ��������б��е�������д��ʡ�Ժſ���ʵ�ֺ������ܿɱ�Ĳ���
    Ԥ�����__VA_ARGS__�������滻���֣�����ʡ�ԺŴ���ʲô
*/

int main(){
    double x = 48;
    double y;
    y = sqrt(x);
    PR(1,"x = %g\n",x);
    PR(2,"x = %.2f,y = %.4f\n",x,y);
	return 0;
}

