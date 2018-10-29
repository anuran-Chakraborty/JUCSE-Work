// Program to simulate LRU algorithm
#include<stdio.h>
#include<stdlib.h>

//struct to maintain page number and priority
typedef struct mem_elem
{
	int pageno;
} mem;
mem arr[5];
int count=0;

// Function to insert a new page in the array
void insert(mem ele,int pos,int max_frames)
{
	int i;
	if(count<max_frames)
	{
		arr[count++]=ele;
	}
	else
	{
		if(pos==-1)
			pos=0;
		for(i=pos;i<count-1;i++)
			arr[i]=arr[i+1];
		arr[count-1]=ele;
	}
}

//Function to check if page exists
int exists(int page_no)
{
	int i;
	for(i=0;i<count;i++)
	{
		if(page_no==arr[i].pageno)
			return i;
	}
	return -1;
}

//Function to print the array
void printArr()
{
	int i=0;
	for(;i<count;i++)
		printf("%d ",arr[i].pageno);
	printf("\n");
}

int main()
{
	//Define array of pages
	int parr[]={9, 10, 11, 7, 12, 8, 7, 6, 12, 5, 4, 3, 10, 11, 12, 4, 5, 6, 9, 4, 5};
	int i,j;

	for(j=4;j<=5;j++)
	{
		printf("=============================================\n");
		count=0;
		printf("For %d frames\n",j);
		for(i=0;i<21;i++)
		{
			int pos=exists(parr[i]);
			mem temp={parr[i]};
			printf("Page %d accessed \t",parr[i]);
			insert(temp,pos,j);
			printArr();
		}
		printf("=============================================\n");
	}
	return 0;
}
