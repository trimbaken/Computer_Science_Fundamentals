#include<stdio.h>
#include<stdlib.h>

int input[10] = {3,5,7,10,15,20,25,26,30,31};
int sum = 27;
int main(void)
{
	system("clear");
	int i;
	int j;

	i = 0;
	j = 9;
	while(i<10 && j>0)
	{
		if(input[i] + input[j] == sum)
		{
			printf("\n found pair with sum [%d], is %d and %d\n", sum, input[i], input[j]);
			break;
		}
		else if(input[i] + input[j] > sum)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	printf("\n Program to find pair with sum as X\n");
	return 0;
}
