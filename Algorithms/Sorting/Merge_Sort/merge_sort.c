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
	if(start_index >= end_index)
		return;

	mid = start_index + (end_index - start_index) / 2;
	sort(array, start_index, mid);
	sort(array, mid+1, end_index);

	index = start_index;
	first_half_index = start_index;
	second_half_index = mid+1;
	printf("\n start_index [%d], end_index [%d], index [%d], second_half_index [%d]  \n", start_index, end_index, index, second_half_index);
	while(first_half_index <= mid && second_half_index <= end_index)
	{
		if(array[first_half_index] > array[second_half_index])
		{
			temp_array[index++] = array[second_half_index++];
		}
		else
		{
			temp_array[index++] = array[first_half_index++];
		}
	}
	for(i = first_half_index; i<=mid; i++)
	{
		temp_array[index++] = array[i];
	}
	for(i = second_half_index; i<=end_index; i++)
	{
		temp_array[index++] = array[i];
	}
	for(i =start_index; i<=end_index; i++)
        {
                array[i] = temp_array[i];
		printf("%d ", array[i]);
        }
	return;
}

bool merge_sort(int* input_array)
{
	int i =0;
	int size =0;

	while(size < INT_MAX && input_array[size] != '\n' && input_array[size] != '\0')
	{
		size++;
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
		printf("\n Enter valid size\n");
		return 1;
	}
	printf("Enter %d elements of input array \n", size);
	for(i =0; i<size; i++)
	{
		scanf("%d", &input_array[i]);
	}
	if(merge_sort(input_array) != true)
	{
		printf("\n Merge Sort Fail to sort input array \n");
		return 1;
	}

	printf("\n Input array after sorting \n");
	for(i =0; i<size; i++)
	{
		printf("%d ", input_array[i]);
	}

	printf("\n Program to sort input array of integer using Merge Sort Alorithm\n\n");
	return 0;
}
