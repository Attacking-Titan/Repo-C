#include <stdio.h>
#include <stdlib.h>
/*
��2019 �ֽ��3 ��������ͬ��������֮�ͣ�����Ҫ��ÿ��������������������2��4��һ���ж����ֲ�ͬ�ķֽⷽ����
ע�⽻��3 ��������˳����Ϊͬһ�ַ���������1000+1001+18 ��1001+1000+18 ����Ϊͬһ�֡�
*/
int check(int n)
{
while(n!=0)
{
  if(n%10==2||n%10==4)return 0;
  n/=10;
}
return 1;
}
int main(int argc, char *argv[])
{
  int a,b,c,sum=0;
  //�Ӵ�С����a>=b>=c,��֤���ظ�
  for(a=1;a<=672;a++)//a<2019/3
  {
        for(b=a+1;b<1009;b++)//b<2019/2
        {
            c=2019-a-b;
            if(c<=0||c<=b)continue;
            if(check(a)==1&&check(b)==1&&check(c)==1)sum++;
         }
  }
  printf("%d\n",sum);
  return 0;
}
