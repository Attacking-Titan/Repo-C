#include <stdio.h>
#include <stdlib.h>
int main(){
    int long long a,b,k,d;
    scanf("%lld %lld",&a,&b);
    if(b>a){
        d=b-a;
        k=d-b%d;
    }
    else{
        d=a-b;
        k=d-a%d;
    }
	//��b>a,�ɸ�����𷨵�gcd(a+k,b+k) = gcd(b + k,a - b)
	//��k = b - b % (a - b)ʱΪʹ��b + kΪa - b�ı�������Сֵ
	//��ʱa+k��b+k�����Լ������Ϊa - b,ʹ��gcd(a+k,b+k)�����ܵĴﵽ����ˣ�ͬʱkҲΪ��С�Ŀ�ȡֵ
    printf("%lld",k);
}
