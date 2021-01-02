#include<stdio.h>
#include<stdlib.h>

int N;
int sum;
int output[100][100];

void init()
{
	int i =0;
	int j =0;
	for(i =0; i<100; i++)
	{
		for(j= 0; j<100; j++)
		{
			output[i][j] =0;
		}
	}
	for(i = 1; i<10 && i<=sum; i++)
	{
		output[i][0] = 1;
	}
	for(i = 10; i<=sum; i++)
	{
		output[i][0] = 0;
	}
	return;
}

void print_output()
{
	int i =0;
	int j =0;

	for(i =0; i<=sum; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("[%d]\t", output[i][j]);
		}
		printf("\n");
	}
	return;
}

int get_number()
{
	int i=0;
	int j =0;
	int digit =0;

	init();

	for(digit =1; digit<N; digit++)
	{
		for(i =1; i<=sum; i++)
		{
			for(j=0; j<10; j++)
			{
				if(i-j >=0)
				{
					output[i][digit] += output[i-j][digit-1];
				}
			}
		}
	}
	print_output();
	return output[sum][N-1];
}

int main(void)
{
	system("clear");

	scanf("%d",&N);
	scanf("%d",&sum);

	printf("\n Total number of n digit number with sum equals to [%d] are [%d]\n", sum, get_number());
	printf("\n Program to count n digit number with sum equals to given value:  \n");
	return 0;
}
