#include<stdio.h>
#define LIMIT 10000000
int main()
{
	//Program to run for 30s
	int i,j,k;

	for(i=0;i<LIMIT;i++)
		for(j=0;j<LIMIT;j++)
			for(k=0;k<LIMIT;k++);
	return 0;
}