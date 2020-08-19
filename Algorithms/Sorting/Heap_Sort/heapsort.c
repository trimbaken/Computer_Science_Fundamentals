#include<stdio.h>
#include<stdlib.h>

#define INT_MAX 10000

int input_array[INT_MAX];

struct MaxHeap
{
	int size;
	int* array;
};

void swap(int* a, int* b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void printarray(int* array, int size)
{
	int i =0;
	for(i =0; i<size; i++)
	{
		printf("%4d", array[i]);
	}
}

void maxHeapify(struct MaxHeap* maxHeap, int index)
{
	int largest = index;
	int left = index*2 +1;
	int right = index*2 +2;
	if(left < maxHeap->size && maxHeap->array[left] > maxHeap->array[index])
	{
		if(right < maxHeap->size)
		{
			if(maxHeap->array[right] > maxHeap->array[left])
			{
				largest = right;
			}
			else
			{
				largest = left;
			}
		}
		else
		{
			largest = left;
		}
	}
	else if(right < maxHeap->size)
	{
		if(maxHeap->array[right]> maxHeap->array[index])
		{
			largest = right;
		}
	}
	if(largest != index)
	{
		swap(&maxHeap->array[largest], &maxHeap->array[index]);
		maxHeapify(maxHeap, largest);
	}
}

struct MaxHeap* create_max_heap(int* array, int size)
{
	int i =0;
	struct MaxHeap* maxHeap;
	maxHeap = (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
	maxHeap->size = size;
	maxHeap->array = array;
	for(i = (maxHeap->size-2)/2 ; i>=0; --i)
	{
		maxHeapify(maxHeap, i);
	}
	return maxHeap;
}

void heapsort(int* array, int size )
{
	struct MaxHeap* maxHeap = create_max_heap(array, size);
	//	printarray(array, size);
	while(maxHeap->size > 1)
	{
		swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size -1]);
		--maxHeap->size;
		maxHeapify(maxHeap, 0);
	}
	free(maxHeap);
}

int main(void)
{
	system("clear");
	int size = 0;
	int i = 0;

	printf("\n Enter size  of array \n");
	scanf("%d",&size);

	if(size <=0 || size > INT_MAX)
	{
		printf("\n Please enter valid size  \n");
		return 1;
	}
	printf("\n Please enter elements of input array  \n");
	for(i =0; i<size; i++)
	{
		scanf("%d", &input_array[i]);
	}

	printf("\n Array before heapsort  \n");
	printarray(input_array, size);
	heapsort(input_array, size);
	printf("\n Array after heapsort  \n");
	printarray(input_array, size);
	printf("\n Program to sort integer array using Heap Sort \n");
	return 0;
}
