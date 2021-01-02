#include<stdio.h>
#include<stdlib.h>

int input[5] = {1,2,3,4,5};
int N;
int output = 0;
void search(int start, int end)
{
	int middle =0;
	middle = start + (end-start)/2;
	printf("\n Start[%d], middle[%d], end[%d]\n", start, middle, end);
//	if(start == 0 && end == 0)
//	return;
	if(input[start] == N)
	{
		output = start;
		return;
	}
	else if(input[end] == N)
	{
		output = end;
		return;
	}
	else if(input[middle] == N)
	{
		output = middle;
		return;
	}
	else if(N > input[start] && input[start] > input[middle])
	{
		search(start, middle);
		return;
	}
	else if(N > input[start] && N < input[middle])
	{
		search(start, middle);
		return;
	}
	else if(N < input[start] && N < input[middle] && input[start] > input[middle])
	{
		search(start, middle);
		return;
	}
	else
	{
		search(middle, end);
	}
	return;
}
int main(void)
{
	system("clear");
	printf("\n Enter element to be searched:\n");
	scanf("%d", &N);
	search(0,4);
	printf("\n Searched element[%d] is present at index[%d] \n", N, output);
	printf("\n Search in sorted and rotated array  \n");
	return 0;
}
