#include<stdio.h>
#include<math.h>
int main()
{
 int count=0,n=10;
 printf("square:\n");
 while(++count<11)//++count����11ʱֹͣѭ�� 
 {
 	printf("%d's square is %d\n",n,n*n);
 	n++;
    //count++;���count������ѭ���������++count 
 }
 n=11; 
 printf("cube:\n");
 while(count++<20)
 {
 	//count++;���count������ѭ����ǰ����count++ 
 	printf("%d's cube is %d\n",n,n*n*n);
 	n++;
 }
 return 0;
}
