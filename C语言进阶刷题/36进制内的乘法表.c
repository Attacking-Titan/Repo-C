#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // ���ڴ��������Ĵ���
  char arr[10];
  int n,k,i,j,t,count=0;
  scanf("%d",&n);
  for(i=1;i<n;i++)
    for(j=1;j<=i;j++)
    {
      k=i*j;
      count=0;
      while(k!=0){
      if(k%n<10)arr[count]='0'+k%n;
      else arr[count]='A'+k%n-10;
      count++;
      k/=n;
      }
      arr[count]='\0';

	  //���ڼ������õĽ��Ϊ�Ӹ�λ����λ�����Խ��������洢
      t=0;
      while(t<count-t-1){
      arr[t]=arr[t]^arr[count-t-1];
      arr[count-t-1]=arr[t]^arr[count-t-1];
      arr[t]=arr[t]^arr[count-t-1];
      t++;
      }

      if(i<10)printf("%d*",i);
      else printf("%c*",'A'+i-10);

      if(j<10)printf("%d=",j);
      else printf("%c=",'A'+j-10);

      printf("%s",&arr);
      if(j==i)printf("\n");
      else printf(" ");
    }
  return 0;
}
