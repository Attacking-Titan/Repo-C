#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // ���ڴ��������Ĵ���
  int n,i,j,count=0;
  scanf("%d",&n);
  char str[n+1][n+1];
  for(i=0;i<n;i++)
  scanf("%s",str[i]);
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  if(str[i][j]=='#')count++; 
  //�ĸ���
  if(str[0][0]=='#' && (str[0][1]=='.' || str[1][0]=='.') )count--;
  if(str[0][n-1]=='#' && (str[0][n-2]=='.' || str[1][n-1]=='.') )count--;
  if(str[n-1][0]=='#' && (str[n-2][0]=='.' || str[n-1][1]=='.') )count--;
  if(str[n-1][n-1]=='#' && (str[n-1][n-2]=='.' || str[n-2][n-1]=='.' ))count--;
  //��һ�к����һ�У�������β��
  for(j=1;j<n-1;j++){
  if(str[0][j]=='#' && (str[0][j-1]=='.' || str[0][j+1]=='.' || str[1][j]=='.'))count--;
  if(str[n-1][j]=='#' && (str[n-1][j-1]=='.' || str[n-1][j+1]=='.' || str[n-2][j]=='.'))count--;
  }
  //��һ�к����һ�� 
  for(i=1;i<n-1;i++)
  {
  	if(str[i][0]=='#' && (str[i][1]=='.' || str[i-1][0]=='.' || str[i+1][0]=='.'))count--;
  	if(str[i][n-1]=='#' && (str[i][n-2]=='.' || str[i-1][n-1]=='.' ||str[i+1][n-1]=='.'))count--;
  }
  for(i=1;i<n-1;i++)
  for(j=1;j<n-1;j++)
  {
    if( str[i][j]=='#' && (str[i][j-1]=='.' || str[i][j+1]=='.' || str[i-1][j]=='.' || str[i+1][j]=='.') )count--;
  }
  printf("%d",count);
  return 0;
}
