#include<stdio.h>
#include<time.h>
int main()
{
	//Program to run for 30s
	int i,j,k;
	clock_t goal = 5000000 + clock();
    while (goal > clock());

	printf("Input\n");
	scanf("%d",&k);

	clock_t goal = 25000000 + clock();
    while (goal > clock());

	return 0;
}