#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // ���ڴ��������Ĵ���
  int i,j,k,n,num[10000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%*d:%*d:%*d %d",&num[i]);
  }
  //ѡ������
  for(i=0;i<n-1;i++){
    k=i;
    for(j=i+1;j<n;j++){
      if(num[k]>num[j])k=j;
    }
    if(k!=i){
    num[i]^=num[k];
    num[k]^=num[i];
    num[i]^=num[k];
	}
  }
  //���
  printf("%d\n",num[0]);
  if(n==1)return 0;
  for(i=1;i<n;i++)
  if(num[i]!=num[i-1])printf("%d\n",num[i]);
  return 0;
}
