#include<stdio.h>
#define max(x,y) ({         \
	typeof(x) _x = (x);    \
	typeof(y) _y = (y);    \
	(void) (&_x == &_y);    \
	_x > _y ? _x : _y; })
//(void) (&_x == &_y); ���ڲ�ͬ���͵�ָ��Ƚϣ������������һ������
//������ֵ�Ƚϣ��ȽϵĽ��û���õ�ʱ��������������棬�˾������������

int main(){
	printf("%f",max(32.4,31.5));
	return 0;
}

