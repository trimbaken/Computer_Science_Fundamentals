#include<stdio.h>
#include<stdbool.h>

#define INT_MAX 10000
int temp_array[INT_MAX];


void sort(int* array, int start_index, int end_index)
{
	int mid =0;
	int index =0;
	int temp =0;
	int first_half_index =0;
	int second_half_index =0;
	int i =0;
	int j =0;
	int pivote = 0;
	if(start_index >= end_index)
		return;

	index = start_index;
	first_half_index = start_index;
	second_half_index = end_index;
	pivote = end_index;
	i = start_index-1;
	for(j = start_index; j<= end_index; j++)
	{
		if(array[j] < array[pivote])
		{
			i++;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
	}
	temp = array[pivote];
	array[pivote] = array[i+1];
	array[i+1] = temp;

	mid = i+1;
	sort(array, start_index, mid-1);
	sort(array, mid+1, end_index);

	return;
}

bool quick_sort(int* input_array, int size)
{
	int i =0;

	if(size == INT_MAX)
	{
		printf("\n Input array size is more then %d, please provide array with size less than %d \n", INT_MAX, INT_MAX);
		return false;
	}

	printf("\n Input array is:  \n");
	for(i =0; i<size; i++)
	{
		printf("%d ", input_array[i]);
	}

	sort(input_array, 0, size-1);
	return true;
}

int main(void)
{
	int size =0;
	int i = 0;
	int input_array[INT_MAX];
	printf("\n Enter size of input array:\n");
	scanf("%d", &size);
	if(size<0 || size>INT_MAX)
	{
		printf("\n Enter valid size in the range 0 to %d \n",INT_MAX);
		return 1;
	}
	printf("Enter %d elements of input array \n", size);
	for(i =0; i<size; i++)
	{
		scanf("%d", &input_array[i]);
	}
	if(quick_sort(input_array, size) != true)
	{
		printf("\n Quick Sort Fail to sort input array \n");
		return 1;
	}

	printf("\n Input array after sorting \n");
	for(i =0; i<size; i++)
	{
		printf("%d ", input_array[i]);
	}

	printf("\n Program to sort input array of integer using Quick Sort Alorithm\n\n");
	return 0;
}
