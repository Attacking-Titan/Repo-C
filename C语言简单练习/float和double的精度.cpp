#include<stdio.h>
#include<float.h>
int main()
{
	double d_third=1.0/3.0;
	float f_third=1.0/3.0;
	printf("float of one third(6)=%.6f\n",f_third);
	printf("float of one third(12)=%.12f\n",f_third);//С�����6λ��׼ȷ������ֻ��׼ȷһλ 
	//�������ڴ�ӡfloatʱͳһת��Ϊdouble,����ӡʱ��ת�����������float�������ݵľ��� 
	printf("float of one third(16)=%.16f\n",f_third);
	printf("float of one third(lf)=%.16lf\n",f_third);
	printf("double of one third(6)=%.6lf\n",d_third);
	printf("double of one third(12)=%.12lf\n",d_third);
	printf("double of one third(16)=%.16lf\n",d_third);
	printf("double of ont third(20)=%.20lf\n",d_third);//С�����15λ�����ݲ�׼ȷ������ֻ��׼ȷһλ 
	printf("FLT_DIG in float.h is %d\n",FLT_DIG);//float�ľ��� 
	printf("DBL_DIG in float.h is %d\n",DBL_DIG);//double�ľ��� 
	return 0;
}
