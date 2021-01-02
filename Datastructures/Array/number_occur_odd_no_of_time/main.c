#include<stdio.h>
#include<stdlib.h>

int input[7] = {1, 2, 3, 2, 3, 1, 3};
int main(void)
{
	system("clear");
	int i;
	int xor_sum = 0;
	for(i =0; i<7; i++)
	{
		xor_sum = xor_sum ^ input[i];
	}
	printf("\n Number which occur odd number of times is [%d] \n", xor_sum);
	printf("\n Program to get number occuring odd number of time  \n");
	return 0;
}
