/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:
	Description:
*/
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int n,i,j,t;
  scanf("%d",&n);
  /* ��n��ʼ�ң���һ���ҵ��������Ӽ�Ϊ��� */
  for(i = 2;i < n;i++){
  	/* ��������� */
	if(n % i == 0){
		t = n / i;
    	/* �ж��Ƿ������� */
    	for(j = 2;j <= sqrt(t);j++){
    	  if(t % j == 0) break;
   		}
   		if(j > sqrt(t)) {
     	 	printf("%d",t);
      		return 0;
    	}
    }
  }
}
