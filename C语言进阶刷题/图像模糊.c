#include <stdio.h>
#include <stdlib.h>
int fun(int arr[][100],int i,int j,int n,int m){
  int sum = arr[i][j];
  int count = 1;
  if(i-1>=0)  {sum+=arr[i-1][j]; count++;}//��
  if(i+1<n)   {sum+=arr[i+1][j]; count++;}//��
  if(j-1>=0)  {sum+=arr[i][j-1]; count++;}//��
  if(j+1<m)   {sum+=arr[i][j+1]; count++;}//��
  if(i-1>=0 && j-1>=0)  {sum+=arr[i-1][j-1]; count++;}//����
  if(i+1<n && j-1>=0)   {sum+=arr[i+1][j-1]; count++;}//����
  if(i-1>=0 && j+1<m)   {sum+=arr[i-1][j+1]; count++;}//����
  if(i+1<n && j+1<m)    {sum+=arr[i+1][j+1]; count++;}//����
  return sum/count;
}

int main(int argc, char *argv[])
{
  // ���ڴ��������Ĵ���
  int n,m,i,j;
  scanf("%d %d",&n,&m);
  int arr[n][100],ans[n][100];
  for(i= 0 ;i < n;i++)
    for(j = 0;j < m;j++)
      scanf("%d",&arr[i][j]);
  for(i = 0;i < n;i++)
    for(j = 0;j< m;j++)
      ans[i][j] = fun(arr,i,j,n,m);
  for(i = 0;i < n;i++){
    for(j = 0;j < m;j++) printf("%d ",ans[i][j]);
    printf("\n");
  }
  return 0;
}
