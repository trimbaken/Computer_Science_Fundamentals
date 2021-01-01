#include<stdio.h>
#include<stdlib.h>

int N;
int output[12][100];
int input[4][3];

void init()
{
	int i =0;
	int j =0;
	int count = 1;
	for(i =0; i<3; i++)
	{
		for(j =0; j<3; j++)
		{
			input[i][j] = count++;
		}
	}
	input[3][0] = 10;
	input[3][1] = 0;
	input[3][2] = 11;

	for(i=0; i<12; i++)
	{
		for(j =0; j<N; j++)
		{
			output[i][j] = 0;
		}
	}
	for(i =0; i<4; i++)
	{
		for(j=0; j<3; j++)
		{
			output[input[i][j]][0] = 1;
		}
	}
	output[input[3][0]][0] = 0;
	output[input[3][2]][0] = 0;
	output[0][0] = 1;

	return;
}

int get_number()
{
	int i =0;
	int j =0;
	int ret =0;
	int size =0;
	init();

	for(size = 1; size<N; size++)
	{
		for(i =0; i<3; i++)
		{
			for(j =0; j<3; j++)
			{
				(j-1)>=0?(output[input[i][j]][size] += output[input[i][j-1]][size-1]):0;
				(i-1)>=0?(output[input[i][j]][size] += output[input[i-1][j]][size-1]):0;
				(j+1)<3?(output[input[i][j]][size] += output[input[i][j+1]][size-1]):0;
				(i+1)<3?(output[input[i][j]][size] += output[input[i+1][j]][size-1]):0;
				output[input[i][j]][size] += output[input[i][j]][size-1];
			}
		}
		output[8][size] += output[0][size-1];
		output[0][size] += output[8][size-1];
		output[0][size] += output[0][size-1];
	}
	for(i =0; i<10; i++)
	{
		ret += output[i][N-1];
	}
	return ret;
}

int main(void)
{
	system("clear");
	printf("\nEnter length of number\n");
	scanf("%d",&N);
	printf("\n Number of possible numbers of length are:[%d]\n", get_number());
	printf("\n Program to number of possible numbers with given length:\n");
	return 0;
}
