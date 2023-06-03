/*
    ������������ʹ��������ͬ������(�ϴ�)����ɢ��,�������õ�ɢ���Ժ͵���ײ��,����Ҳ���š�
*/

#include<stdio.h>
#define PRIME 5
#define MORE_PRIME 7

int getLength(char *str){
	int i = 0;
	int length = 0;
	while(str[i++] != '\0'){
		length++;
	}
	return length;
}

int GeomIncreHash(char *str,int table_size){
	int hash = 0;
	int length = getLength(str);
	int i;
	for(i = 0;i < length;i++){
		hash *= PRIME;
		hash = hash ^ (str[i] * MORE_PRIME);
	}
	hash %= table_size;
}

int main(){
	printf("%d\n",GeomIncreHash("aaa",1000));
	printf("%d\n",GeomIncreHash("cute",1000));
	printf("%d\n",GeomIncreHash("nice",1000));
	printf("%d\n",GeomIncreHash("function",1000));
	return 0;
}

