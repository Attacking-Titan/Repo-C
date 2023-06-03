/*
	FNV-1a ��ϣ��
	FNV-1a��Fowler-Noll-Vo��ϣ������һ�ֱ��壩��һ�������ҷֲ����õĹ�ϣ������
	��ͨ������ϣֵ��һ���ϴ�����������磬16777619����ˣ����뵱ǰ�ַ���ASCII������������չ�ϣֵ��
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

int fnv1aHash(char *str){
	const FNV_PRIME = 0x01000193;
	const FNV_OFFSET = 0x811c9dc5;
	int hash = FNV_OFFSET;
	int length = getLength(str);
	int i;
	for(i = 0;i < length;i++){
		hash ^= str[i];
		hash *= FNV_PRIME;
	}
	return hash;
}

int main(){
	printf("%x\n",fnv1aHash("aaa"));
	printf("%x\n",fnv1aHash("abc"));
	printf("%x\n",fnv1aHash("zzz"));
	printf("%x\n",fnv1aHash("day"));
	return 0;
}

