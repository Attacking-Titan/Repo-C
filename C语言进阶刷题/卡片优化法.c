#include<stdio.h>
int main(){
	int count,i = 1,t;//countͳ��1���ֵĴ���
	//1һ�������ȱ������
	while(1){
	   t = i;
	   while(t > 0){
			if(t % 10==1) count++;
			if(count>2021) {
				printf("%d",i);
				return;
			}
			t /= 10;
	   }
	   i++;
	}
}
