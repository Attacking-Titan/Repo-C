#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int i;
  char str[201];
  gets(str);//����\n��������
  if(str[0]>='a' && str[0]<='z') {
    printf("%c",str[0]-32);//��һ���ַ�����ĸ���д 
    if(str[i+1]>='0' && str[i+1]<='9') printf("_");//���������������һ��_
  }
  else printf("%c",str[0]);//����ֱ�������һ���ַ�
  for(i = 1;i<strlen(str);i++){
    if(str[i]>='a' && str[i]<='z')//�������ĸ 
	  {
      if(str[i-1]>='0' && str[i-1]<='9') printf("_");//���ǰ�������������_
      if(str[i-1]==' ') printf("%c",str[i]-32);//���������ĸ���д
        else printf("%c",str[i]);//����Сд
      if(str[i+1]>='0' && str[i+1]<='9') printf("_");//��������������������һ��_
    }
	    else if(str[i]==' ' && str[i-1]==' ')continue;//����ո�ǰ�滹�ǿո񣬲���� 
        else printf("%c",str[i]);//����ո�������֣�ֱ�����
  }

  return 0;
}
