#include<stdio.h>

void swap(int* nums, int l, int r)
{
	int temp;
	temp = nums[l];
	nums[l] = nums[r];
	nums[r] = temp;

	return;
}

void sortColors(int* nums, int numsSize)
{
	int i, l,r;
	i =0;
	l =0;
	r = numsSize-1;

	while(i<=r)
	{
		if(nums[i] == 2)
		{
			swap(nums, i,r);
			r--;
		}
		else if(nums[i] == 0)
		{
			swap(nums, l, i);
			l++;
			i++;
		}
		else
		{
			i++;
		}
	}
	return;
}

int main(void)
{
	int nums[100];
	int i =0;
	nums[0] = 2;
	nums[1] = 0;
	nums[2] = 2;
	nums[3] = 1;
	nums[4] = 1;
	nums[5] = 0;

	sortColors(nums, 6);
	for(i=0;i<6;i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n Program to sort colors present in input array of integer\n");
	return 0;
}
