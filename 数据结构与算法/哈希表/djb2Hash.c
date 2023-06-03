#include<stdio.h>

/*
	DJB2 ��ϣ��
	DJB2����Daniel J. Bernstein�������һ�����Ҹ�Ч�Ĺ�ϣ���������ڽ��ַ���ת��Ϊ��ϣֵ��
	DJB2��ϣ�㷨��һ���ϴ�����������磬5381��Ϊ��ʼֵ����ͨ����ÿ���ַ���ASCII����ǰһ����ϣֵ��˺��ۼӣ��������չ�ϣֵ��
 	���㷨�򵥸�Ч,��ײ���ʽϵ�,��C++ std::string��Ĭ��ɢ���㷨
*/
int getLength(char *str){
	int i = 0;
	int length = 0;
	while(str[i++] != '\0'){
		length++;
	}
	return length;
}

int djb2Hash(char *str){
	int hash = 5;
	int i;
	int length = getLength(str);
	for(i = 0;i < length;i++){
		hash = ((hash << 5) + hash) + str[i];//hash * 33 + str[i];
	}
	return hash;
}

int main(){
	printf("%d\n",djb2Hash("abc"));
	printf("%d\n",djb2Hash("cdf"));
	printf("%d\n",djb2Hash("zzz"));
	return 0;
}

