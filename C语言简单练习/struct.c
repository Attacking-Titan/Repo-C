#include<stdio.h>
struct Node{
	int data1;
	char data2;
}node[20];
int main(){
	int i,j,k;
	int t1; //������������ʱ��Žṹ�����data1������
	char t2;//������������ʱ�巹�ṹ�����data2������
	//����������data1Ϊ����Ĳο����ݣ��Ƚ�data1�Ĵ�С��ȷ��˭��ǰ��
	for(i = 0;i<20;i++){
		k = i;
		for(j = i;j<20;j++){
			if(node[k].data1 > node[j].data1) k = j;//���ṹ��������data1��С���Ǹ��ṹ����±긳��k
		}
		if(k!=i){
			//����node[k].data1��node[i].data1��ֵ
			t1 = node[k].data1;
			node[k].data1 = node[i].data1;
			node[i].data1 = t1;

			//����node[k].data2��node[i].data2��ֵ
			t2 = node[k].data2;
			node[k].data2 = node[i].data2;
			node[i].data2 = t2;
		}//ÿһ�ν�data1��С�Ľṹ���ŵ�ǰ��
	}
	return 0;}
