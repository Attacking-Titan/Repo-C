int Get_figure(int *arr,int len){
	int max = 0,i;
	for(i = 0;i < len;i++)
		if(arr[i] > max) max = arr[i];//�����ֵ
	int count = 0;
	while(max){
		count++;
		max/=10;
	}//����λ��
	return count;
}//��ȡ���������ֵ��λ��

//�˺�����ȡ���ڲ���n��Ӧ��finλ�Ƕ���
int Get_Num(int n,int fin)
{
	int i = 0;
	while(i++ < fin)//n�ȶ���finλ���λ
		n /= 10;
	return n % 10;//��ʱ���ʣ������λ������
}

//һ��Ͱ����fin������һ���Ǹ����ĸ�λ��������
void Radix(int *arr,int len,int fin)//ʱ�临�Ӷ�O(n)
{
	int bucket[10][100] = {0};//����10��Ͱ
	int num[10]  = {0};//num[i]����i��Ͱ�ж��ٸ���Чֵ
	int i,j;
	//���������ݴ��������Ӧ��Ͱ�д��
	for(i = 0;i < len;i++)
	{
		int index = Get_Num(arr[i],fin);
		bucket[index][num[index]] = arr[i];
		num[index]++;
	}
	//����0~9��Ͱ��˳��������ѭ�Ƚ��ȳ��Ĺ�������ֵȡ����
	int k = 0;
	for(i = 0;i <= 9;i++){
		for(j = 0;j < num[i];j++)
			arr[k++] = bucket[i][j];//ȡ������ֵ��ǰ����ŵ�arr��
	}
}

//��������(Ͱ����),ʱ�临�Ӷ�(d*n)(�������λ��Ϊd)
void RadixSort(int *arr,int len){
	//assert
	//����Ҫ֪��������������ֵ�ж���λ
	int count = Get_figure(arr,len);
	int i;
	for(i = 0;i < count;i++)
		Radix(arr,len,i);
}
