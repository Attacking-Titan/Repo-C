#include<stdio.h>
#include<float.h>
#include<limits.h>
int main(void){
	int big_int=2147483647;//�з��������������ֵһ��Ϊ2^31-1�� 
	float big_float=3.4e38;//���������ֵһ��Ϊ3.4E38 
	float small_float=10.0/3;//���������ݵ���Чλ��Ϊ��λ 
	printf("The big int data is %d\n",big_int+1);//�����������ֵ��1�����Խ�磬���Ϊ-2147483648�� 
	printf("The big float data is %f\n",big_float*10);//������������ݳ�10���Խ�磬���inf��
	/*�����������ֻ��1��С���ݣ������侫ȷ�����Ʋ������Խ��*/
	printf("The big float data is %f\n",small_float);//��ӡ3.333333����ʧ����
	printf("The MAX float data is %f\n",FLT_MAX);//��ӡ340282346638528859811704183484516925440.000000 
	printf("The max int data is %ld\n",INT_MAX);//��ӡ2147483647 
	return 0; 
}
