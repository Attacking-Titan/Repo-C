#include <stdio.h>
#include <stdlib.h>
/*
����:a*a + b*b + c*c = 1000��һ����������6��80��30����������һ���
*/
int main(int argc, char *argv[])
{
	int a,b,c;
  	for(a = 1;a < 32;a++)
    	for(b = a; b < 32;b++)
      		for(c = b; c < 32;c++){
        		if(a * a + b * b + c * c == 1000 && a != 6){
		 			 printf("%d %d %d\n",a,b,c);
        		}
      		}
  return 0;
}
