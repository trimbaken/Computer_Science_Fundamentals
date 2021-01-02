#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int size;
int input[100];

struct cost
{
	int row;
	int column;
	int val;
}output[100][100];

int matrix_multiplication()
{
	int i =0;
	int T =0;
	int j =0;
	int min =0;
	int cost =0;
	int temp_row = 0;
	int temp_col = 0;

	for(i =0; i<size; i++)
	{
		output[i][i].row = input[i];
		output[i][i].column = input[i+1];
		output[i][i].val = 0;
	}
	for(T = 1; T<size; T++)
	{
		for(i=0; (i+T)<size; i++)
		{
			min = INT_MAX;
			temp_row =0;
			temp_col = 0;
			for(j=i; j<(i+T); j++)
			{
			cost = output[i][j].val + output[j+1][i+T].val + (output[i][j].row * output[i][j].column * output[j+1][i+T].column);
				if(min > cost)
				{
					temp_row = output[i][j].row;
					temp_col = output[j+1][i+T].column;
					min = cost;
				}
			}
			output[i][i+T].val = min;
			output[i][i+T].row = temp_row;
			output[i][i+T].column = temp_col;
		}
	}
	return output[0][size-1].val;
}

int main(void)
{
	system("clear");
	int i =0;

	scanf("%d",&size);
	for(i=0; i<=size; i++)
	{
		scanf("%d",&input[i]);
	}
	printf("\n optimal cost of matrix multiplication[%d]\n", matrix_multiplication());
	printf("\n Program to get efficent way to multiply given matrices:\n");
	return 0;
}
