#include<stdio.h>
#include<string.h>
int main()
{
  char S[1000],T[1000];
  int i,j,lens,lent,ans = 0;
  gets(S);
  gets(T);
  lens = strlen(S);
  lent = strlen(T);
  //��Ŀ��˼��˵��S�а������ҵ�˳���ܰ�����T����󳤶�
  //T����һ���ַ�Ӧ�õ���һ����Sƥ���λ�õ���һ���ַ�ȥѰ��
    for(i = 0,j = 0;j<lens && i<lent;j++)//˫ָ��
	{
      if(T[i]==S[j]) {
        ans++;//T[i]��ƥ��
        i++;//ƥ����һ��
      }
  }
  printf("%d",ans);
  return 0;
}

