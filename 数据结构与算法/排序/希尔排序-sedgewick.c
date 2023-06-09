#include<stdio.h>
#include<stdlib.h>
#define N 1000
int count = 0;
int step[6] = {0,1,5,19,41,109};

void fillArray(int arr[],int n){
	int i;
	srand(time(NULL));
	for(i = 0;i<n;i++)
		arr[i] = rand()%1000;
}
void showArray(int arr[],int n){
	int i;
	for(i = 0;i<n;i++){
		printf("  %3d  ",arr[i]);
		if((i+1)%10==0) putchar('\n');
	}
	printf("\n");
}

void shell_sort(int arr[],int len){
	int i,j;
	int temp;
	int *gap;
	for(gap = &step[5];*gap>0;gap--)//控制插入的增量，不断缩小增量直至增量为1
		for(i = *gap;i <= len-*gap;i++){
			temp = arr[i];
			for(j = i-*gap;j >= 0 && arr[j]>temp;j-=*gap)//
				arr[j+*gap] = arr[j];//挪位
			arr[j+*gap] = temp;//插入
			count++;
		}
}

int main()
{
	int arr[N];
	fillArray(arr,N);
	showArray(arr,N);
	shell_sort(arr,N);
	showArray(arr,N);
	printf("\t总共插入%d次",count);
	return 0;
}
