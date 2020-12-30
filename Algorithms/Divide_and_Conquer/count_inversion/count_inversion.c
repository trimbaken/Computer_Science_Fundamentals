#include<stdio.h>

#define MAX_SIZE 100

int merge(int input_array[], int left, int right)
{
	int count =0;
	int temp[MAX_SIZE];
	int temp_count =0;
	int i =0;
	int j =0;
	int mid = (left + right)/2;

	printf("\nMerge left [%d], right[%d]\n", left, right);
	for(i =left; i<=right; i++)
	{
		printf("%d ", input_array[i]);
	}
	if(left >= right)
	{
		return 0;
	}
	mid = left + (right-left)/2;
	printf("\nmerge mid %d\n", mid);
	for(i = left; i<= mid; i++)
	{
		for(j = mid+1; j<= right; j++)
		{
			if(input_array[i] > input_array[j])
			{
				//count += (j-(mid+1) +1);
				count++;
				printf("\ncount %d\n", count);
			}
		}
	}
	for(i =left, j= mid+1; i<= mid, j<= right;)
	{
		if(input_array[i] < input_array[j])
		{
			temp[temp_count] = input_array[i];
			temp_count++;
			i++;
		}
		else
		{
			temp[temp_count] = input_array[j];
			temp_count++;
			j++;

		}
	}
	for(; i<= mid; i++)
	{

		temp[temp_count] = input_array[i];
		temp_count++;
	}
	for(;j<=right; j++)
	{
		temp[temp_count] = input_array[j];
		temp_count++;
	}
	for(i =0, j =left; i<temp_count; i++, j++)
	{
		input_array[j] = temp[i];
	}
	return count;
}

int merge_sort_(int input_array[], int left, int right)
{
	int left_inversion =0;
	int right_inversion =0;
	int count_inversion =0;
	int mid =0;
	if(right <= left)
	{
		return 0;
	}
	mid = left + (right-left)/2;
	left_inversion = merge_sort_(input_array, left, mid);
	right_inversion = merge_sort_(input_array, mid+1, right);

	count_inversion = (left_inversion + right_inversion) + merge(input_array, left, right);

	return count_inversion;

}

void count_inversion(int input_array[], int array_size)
{
	printf("\nCount Inversion is [%d]\n", merge_sort_(input_array, 0, array_size-1));
}
int main(void)
{
	int input_array[MAX_SIZE];
	int array_size =0;
	int i =0;

	printf("\nEnter size of array\n");
	scanf("%d", &array_size);
	printf("\nEnter elements of array\n");
	for(i =0; i<array_size; i++)
	{
		scanf("%d", &input_array[i]);
	}

	count_inversion(input_array, array_size);
	printf("\nProgram to identify count inversions in integer array\n");
	return 0;
}
