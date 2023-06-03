/*
 	Bernstein���㷨:���㷨ͨ��ȡģ������ײ,ʹ��33����������Եõ��ȽϾ��ȵ�ɢ��ֵ,��ȡģ���㽵�������ܡ�
*/

#include<stdio.h>

int getLength(char *str){
	int i = 0;
	int length = 0;
	while(str[i++] != '\0'){
		length++;
	}
	return length;
}

int Bernstein_Hash(char *str,int table_size){
	int hash = 0;
	int length = getLength(str);
	int i;
	for(i = 0;i < length;i++){
		hash = 33 * hash + str[i];
	}
	hash %= table_size;
	return hash;
}

int main(){
	printf("%d\n",Bernstein_Hash("birthday",1000));
	printf("%d\n",Bernstein_Hash("usually",1000));
	printf("%d\n",Bernstein_Hash("Titan",1000));
	return 0;
}

