#include<stdio.h>


#define MAX_VAL 2121212
int val[101][101];
int graph[101][101];

void initialize(int size)
{
	int i,j;

	for(i =0;i<size;i++)
	{
		for(j=0; j<size; j++)
		{
			graph[i][j] = 0;
			val[i][j] = MAX_VAL;
		}
	}
}

void get_all_pair_shortest_path(int size)
{
	int i,j,k;

	for(i=0; i<size; i++)
	{
		val[i][i] = 0;
	}
	for(k=0;k<size;k++)
	{
		for(i=0;i<size;i++)
		{
			for(j=0; j<size; j++)
			{
				if(val[i][j] > (val[i][k] + val[k][j]))
					val[i][j] = (val[i][k] + val[k][j]);
			}
		}
	}
	return;
}

void get_max_time(int S, int A, int H, int size, int test_cases)
{
	int max =0;
	int i;

	for(i=0; i<size; i++)
	{
		if(i!=S-1 && i!=A-1 && i!=H-1)
		{
			if(max < (val[S-1][i] + val[i][A-1] + val[A-1][i] + val[i][H-1]))
				max = (val[S-1][i] + val[i][A-1] + val[A-1][i] + val[i][H-1]);
		}
	}
	printf("Case #%d\n%d\n",test_cases,max);
}

void print_graph(int size)
{
	int i,j;

	for(i =0; i<size; i++)
	{
		for(j =0; j<size; j++)
		{
			printf("[%d]\t",val[i][j]);
		}
		printf("\n");
	}
	return;
}

int main(void)
{
	int test_cases =0;
	int i,j;
	int N,M;
	int X,Y,C;
	int S,A,H;

	scanf("%d",&test_cases);
	for(i=0; i< test_cases; i++)
	{
		scanf("%d %d",&N,&M);
		initialize(M);
		for(j=0;j<M;j++)
		{
			scanf("%d %d %d",&X,&Y,&C);
			graph[X-1][Y-1] = C;
			graph[Y-1][X-1] = C;
			val[X-1][Y-1] = C;
			val[Y-1][X-1] = C;
		}
		scanf("%d %d %d",&S,&A,&H);
	//	print_graph(N);
		get_all_pair_shortest_path(N);
		print_graph(N);
		get_max_time(S,A,H,N,i+1);
	}
}
