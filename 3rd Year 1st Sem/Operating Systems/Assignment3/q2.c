// Program to simulate first fit and best fit
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct holes
{
	int start;
	int size;
	int end;
}holes;
int memory[10000];
holes h_list[1000];
int h=0;

int comparator(const void* a,const void* b)
{
	int l=((holes*)a)->size;
	int r=((holes*)b)->size;

	return (l-r);
}

void init_mem()
{
	int i;
	for(i=0;i<9999;i++)
	{
		memory[i]=-1;
	}
}
// Fill memory from a starting address
void fill_mem(int start,int size,int pr)
{
	int i;
	for(i=start;i<start+size;i++)
		memory[i]=pr;
}

// generate memory map
void gen_mem_map()
{
	printf(" ___________________________________________________\n");
	printf("| Starting\t| Ending\t| Size\t| Category  |\n");
	printf("|---------------------------------------------------|\n");

	int count=0,start=0,i;
	h=0;
	char* str=(char*)malloc(100*sizeof(char));
	for(i=0;i<9999;i++)
	{
		count++;
		if(memory[i]!=memory[i+1])
		{
			if(memory[i]==-1)
			{
				str="Hole\t";
				holes temp={start,count,i};
				h_list[h++]=temp;
				printf("|%d\t\t|%d\t\t|%d\t|Hole%d      |\n",(start+1),(i+1),count,h);
			}
			else
			{
				printf("|%d\t\t|%d\t\t|%d\t|Process%d   |\n",(start+1),(i+1),count,memory[i]);
				
			}
			//Reset
			count=0;
			start=i+1;
		}
	}
	printf(" ---------------------------------------------------\n");
}

// Fill memory using first fit
void fill_first_fit(int psize,int proc)
{
	int i;
	for(i=0;i<h;i++)
	{
		if(h_list[i].size>=psize)
		{
			fill_mem(h_list[i].start,psize,proc);
			break;
		}
	}
}

// Fill memory using best fit
void fill_best_fit(int psize,int proc)
{
	// First sort the holes by size
	int i;
	qsort(h_list,h,sizeof(holes),comparator);

	for(i=0;i<h;i++)
	{
		if(h_list[i].size>=psize)
		{
			fill_mem(h_list[i].start,psize,proc);
			break;
		}
	}
}

int main()
{
	// For first fit
	init_mem();
	gen_mem_map();

	printf("P0 filled\n");
	fill_mem(200,500,0);
	gen_mem_map();

	printf("P1 filled\n");
	fill_mem(1000,400,1);
	gen_mem_map();

	printf("P2 filled\n");
	fill_mem(1600,250,2);
	gen_mem_map();

	printf("P3 filled\n");
	fill_mem(2000,800,3);
	gen_mem_map();

	printf("--------------- Fill using first fit -------------------------\n");
	printf("P4 or Pi filled\n");
	fill_first_fit(150,4);
	gen_mem_map();

	printf("P5 or Pj filled\n");
	fill_first_fit(100,5);
	gen_mem_map();

	printf("P6 or Pk filled\n");
	fill_first_fit(150,6);
	gen_mem_map();

	// For best fit
	printf(" ---------------------------------------------------\n");

	init_mem();
	gen_mem_map();

	printf("P0 filled\n");
	fill_mem(200,500,0);
	gen_mem_map();

	printf("P1 filled\n");
	fill_mem(1000,400,1);
	gen_mem_map();

	printf("P2 filled\n");
	fill_mem(1600,250,2);
	gen_mem_map();

	printf("P3 filled\n");
	fill_mem(2000,800,3);
	gen_mem_map();

	printf("--------------- Fill using best fit -------------------------\n");
	printf("P4 or Pi filled\n");
	fill_best_fit(150,4);
	gen_mem_map();

	printf("P5 or Pj filled\n");
	fill_best_fit(100,5);
	gen_mem_map();

	printf("P6 or Pk filled\n");
	fill_best_fit(150,6);
	gen_mem_map();

	return 0;

}