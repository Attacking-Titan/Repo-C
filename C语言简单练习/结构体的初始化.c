#include<stdio.h>
struct stu{
	char name[9];
	int score;
};
int main(){
	struct stu fellow[3] = {
		{
			{"������"},
			100 
		},
		{
			{"����"},
			99 
		},
		{
			{"����"},
			99 
		}
	};
	int i;
	for(i = 0;i<3;i++)
	printf("%s %d\n",fellow[i].name,fellow[i].score);
	return 0;
}
