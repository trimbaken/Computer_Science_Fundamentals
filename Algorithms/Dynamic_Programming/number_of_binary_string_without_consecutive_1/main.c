#include<stdio.h>
#include<stdlib.h>

int output[100];
int N;

int get_number_string()
{
	int i =0;
	if(N == 0)
	{
		return 0;
	}
	if(N== 1)
	{
		return 2;
	}
	if(N == 2)
	{
		return 3;
	}
	output[0] = 0;
	output[1] = 2;
	output[2] = 3;

	for(i =3; i<=N; i++)
	{
		output[i] = (output[i-1] + output[i-2]);
	}
	return output[N];
}

int main()
{
	system("clear");
	printf("\nEnter length of string\n");
	scanf("%d",&N);
	printf("\n Number of binary strings without consecutive 1's are[%d]\n", get_number_string());
	printf("\n Program to get number of binary string without consecutive 1's:  \n");
	return 0;
}
