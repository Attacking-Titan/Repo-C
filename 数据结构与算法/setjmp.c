#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>
static jmp_buf buf;
void second(void){
	printf("second\n");//��ӡ
	system("pause");
	longjmp(buf,1);//����setjmp�ĵ��ô���ʹ��setjmp�ķ���ֵΪ1
}
void first(void){
	printf("ִ��first\n");
	system("pause");
	second();
	printf("first\n");//������ִ�е�����
}
int main(){
	if(!setjmp(buf)){
		first();//�������ǰ��setfmp����0
	}
	else { //��longjmp��תת�أ�setjmp����1����˽������
		printf("main\n");//��ӡ
	}
	return 0;
}
