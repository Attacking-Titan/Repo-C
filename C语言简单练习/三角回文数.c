#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,a,b;
	//��ο�����֤������
	 while(1){
	 printf("n=");
	 scanf("%d",&n);
	 b=n;
	 a=0;
	 //��������洢������a�� 
	 while(b>0){
	 	a=a*10+b%10; 
	 	b/=10;
	 }
	 if(n==a)printf("%d�ǻ�����\n",n);
	 else printf("%d���ǻ�����\n",n);
	}	
	 
} 
