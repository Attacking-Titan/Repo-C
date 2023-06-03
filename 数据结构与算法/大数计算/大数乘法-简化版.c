/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:23/03/23 21:57
	Description:�������㣬ת10��n�η��ļ���
*/
#include<stdio.h>
#include<memory.h>
#define base 1000
/*����ܼ���ĳ˻����Ϊ85,070,591,730,234,615,828,950,163,710,522,949,636�����33λ���µĻ������ܼ���*/
void bigNumberMultiply(long long x1,long long x2){
	int bit1,bit2,bit;//�ֱ��¼x1��x2�Լ�x1*x2����base���Ƶ�����µ�λ��
	int i,j,count,flag;
	unsigned long long num1,num2;
	if(x1 > 0 && x2 > 0 || x1 < 0 && x2 > 0) flag = 1;
		else flag = 0;
	if(x1 < 0) x1 = -x1;
	if(x2 < 0) x2 = -x2;
	num1 = x1,num2 = x2;
	
	/* ����x1����base�����µ�λ��*/
	for(count = 0,num1 = x1;num1 > 0;count++){
		num1 /= base;
	}
	bit1 = count;
	/* ����x2����base�����µ�λ��*/
	for(count = 0,num2 = x2;num2 > 0;count++){
		num2 /= base;
	}
	bit2 = count;
	/*����x1*x2�Ľ����base�����µ�λ��*/
	bit = bit1 + bit2;
	
	/*����x1��x2��base�����¸�λ�ϵ�����*/
	int n1[bit1],n2[bit2],res[bit];
	memset(res,0,sizeof(res));
	num1 = x1,num2 = x2;
	for(i = 0;i < bit1;i++){
		n1[i] = num1 % base;
		num1 /= base;
	}//x1
	for(i = 0;i < bit2;i++){
		n2[i] = num2 % base;
		num2 /= base;
	}//x2
	for(i = 0;i < bit1;i++){
		for(j = 0;j < bit2;j++){
			res[i + j] += n1[i] * n2[j];
		}
	}//res
		
	/*��res��λ�ϵ����ֽ�λ*/
	for(i = 0;i < bit;i++){
		if(res[i] >= base) {
			res[i + 1] += res[i]/base;
			res[i] %= base;
		}
	}

	/*�Խ������������Ӹ�λ��ʼ��ÿ�����λ���־��ö��Ÿ���*/
	if(flag == 0) printf("-");//������Ϊ�����������������
	if(res[bit - 1] > 0) {
		printf("%d,",res[bit - 1]);
		printf("%03d,",res[bit - 2]);
	}
	else{
		printf("%d,",res[bit - 2]);
	}
	i = bit - 3;
	while(i > 0){
		printf("%03d,",res[i]);
		i--;
	}
	//�����������Ҫ�ж��ţ�����res[0]�������
	printf("%03d",res[0]);
	printf("\n");
}

int main(){
	long long x1,x2;
	printf("x1 = ");
	scanf("%lld",&x1);
	printf("x2 = ");
	scanf("%lld",&x2);
	bigNumberMultiply(x1,x2);
	return 0;
}


