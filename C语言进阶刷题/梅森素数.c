#include <stdio.h>
//����2��11213�η���һ�ĺ�һ��λ
int main()
{
    int add=0;
    int ans[100]={0},i,j;
    ans[0]=1;
    for(i=0;i<11213;i++)//��ÿ�Ѿ���������Ľ������ѭ����2
	{
        add=0;
        for(j=0;j<100;j++){
              ans[j]=2*ans[j]+add;//��jλ���ֳ�2����ǰһλ�Ľ�λ
              add=ans[j]/10;//��һλ�Ľ�λ
              ans[j]%=10;//�����jλ���
        }
      }
      ans[0] -= 1;
      for(j=99;j>=0;j--){
        printf("%d",ans[j]);
      }
      return 0;
}
