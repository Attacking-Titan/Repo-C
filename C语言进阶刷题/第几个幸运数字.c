#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
  // ���ڴ��������Ĵ���
  long long n = 59084709587505;
  long long i,j,k;
  int ans = 0;
  for(i=1;i<n;i*=3)//��¼����ֻ��3������С��n�ĸ���
    for(j=1;i*j<n;j*=5)//ͳ��ֻ��3��5������С��n�ĸ���
      for(k=1;i*j*k<=n;k*=7)//ͳ��ֻ��3��5��7������С��n�ĸ���
      ans++;
  printf("%d",ans-1);//���ڰ�1ͳ�ƽ�ȥ�ˣ����Ը������һ
  return 0;
}
