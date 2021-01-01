#include<stdio.h>
#define MAX_SIZE 100

int lis(int* arr, int n)
{
	int i;
	int j;
	int max =0;
	int list[n];
	for(i=0;i<n;i++)
	{
		list[i] = 1;
	}
	for(i =1; i<n; i++)
	{
		for(j = 0; j<i; j++)
		{
			if(arr[i] >= arr[j] && list[i] < list[j] + 1)
			{
				list[i] = list[j] + 1;
			}
		}
	}
	for(i = 0; i< n; i++)
	{
		if(max < list[i] )
		{
			max = list[i];
		}
	}
	return max;
}

int main(void)
{
	int arr[MAX_SIZE];
	int result =0;
	int i =0;
	int array_size =0;

	printf("\nEnter number of elements\n");
	scanf("%d", &array_size);
	printf("\nEnter all elements of an array\n");
	for(i =0; i<array_size; i++)
	{
		scanf("%d", &arr[i]);
	}
	result = lis(arr, array_size);
	if(result)
	{
		printf("\n Length of largest increasing subsequence is: %d  \n", result);
	}

	printf("\n Program to get Largest Increasing Subsequence:  \n");
	return 0;
}
