#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
int main()
{
	int i,j;
	int left = 0,right = N-1;
	int arr[N];
	//��������
	srand(time(NULL));
	for(i = 0;i < N;i++){
	arr[i]=rand()%1000;
	srand(arr[i]);
	}
	//ԭʼ���ݴ�ӡ
	for(i=0;i<N;i++)
	printf("  %3d  ",arr[i]);
	printf("\n\n"); 
	//����
	while(left < right)
	{
		int min = left;
		int max = right;
		for( i = left;i <= right;i++)
		{
			if(arr[i]<arr[min])min = i;
			if(arr[i]>arr[max])max = i;
		}
		//���ӻ�
		for(j=0;j<N;j++){
			if(j==left && j!=max || j==min)printf(" [%3d] ",arr[j]);
			else if(j==right || j==max)printf("��%3d��",arr[j]);
			else printf("  %3d  ",arr[j]);
		} 
		printf("\n\n");
		//����right��max 
		if(max!=right){
		arr[max]^=arr[right];
		arr[right]^=arr[max];
		arr[max]^=arr[right];
		}
		if(min == right)min=max;//��max=left,min=rightʱ,ֻ�轻��min��max������Ľ����Ѿ�����˸ôν��� 
		//����left��min
		if(min!=left){
		arr[min]^=arr[left];
		arr[left]^=arr[min];
		arr[min]^=arr[left];
		}
		left++;
		right--;
	 } 
	 for(i=0;i<N;i++)
	printf("  %3d  ",arr[i]);
	 return 0; 
}
