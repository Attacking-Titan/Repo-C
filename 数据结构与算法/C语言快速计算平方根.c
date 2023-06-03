#include<stdio.h>
#include<math.h>
float inv_sqrt(float x){
	float xhalf = 0.5 * x;
	int i = *(int *)&x;
	i = 0x5f375a86 - (i >> 1);//���Ž�0x5f375a86,0x5f3759df
	x = *(float *)&i;
	x = x * (1.5 - xhalf * x * x);
	return x;
}//����x = sqrt(x)/1;
//����������float�Ĵ洢��ʽ������һ��ţ�ٵ����Ϳ��԰������С��ǧ��֮һ
int main(){
	int i;
	for(i = 2;i < 50;i++){
		printf("sqrt(%d) = %f\n",i,1/sqrt(i));
		printf("inv_sqrt(%d) = %f\n",i,inv_sqrt(i));
		printf("���%lf\n\n",fabs(1/sqrt(i) - inv_sqrt(i)));
	}
	return 0;
}
