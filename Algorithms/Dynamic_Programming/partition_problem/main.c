#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int input[100];
int size;
int output[100][100];
int total;

void init()
{
	int i =0;
	int j =0;
	for(i =0; i<=(total/2); i++)
	{
		for(j =0; j<=(total/2); j++)
		{
			output[i][j] = 0;
		}
	}
}

int partition()
{
	int i =0;
	int j =0;
	int k =0;

	total =0;
	for(i =0; i<size; i++)
	{
		total += input[i];
	}
	if((total %2))
	{
		return 0;
	}
	init();
	for(i=0; i<size; i++)
	{
		output[i][input[i]] = 1;
		for(j=0; j<i; j++)
		{
			for(k=0; k<=(total/2); k++)
			{
				if(output[j][k])
				{
					output[i][k+input[i]] = 1;
				}
			}
		}
	}
	for(i=0; i<size; i++)
	{
		if(output[i][total/2])
		{
			return 1;
		}
	}
	return 0;
}

int main(void)
{
	system("clear");
	int i =0;
	printf("\nEnter Size of array\n");
	scanf("%d",&size);
	printf("\nEnter all elements\n");
	for(i =0; i<size; i++)
	{
		scanf("%d",&input[i]);
	}
	printf("\n Equal partition of the array is possible: %d\n", partition());
	printf("\n Program verify partition of given array:\n\n");
	return 0;
}
