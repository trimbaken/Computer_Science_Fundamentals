#include<stdio.h>
#define MAX_LEN 1001

int output[2] = {0,1};

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

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int input[MAX_LEN];
	int i =0;
	int j =0;
	int l =0;
	int r =0;
	int temp =0;
	int left = 0;
	int right =0;
	int mid =0;
	int prev =0;
	*returnSize = 0;
	printf("\n numsSize [%d], target [%d]\n", numsSize, target);

	for(i =0; i<numsSize; i++)
	{
		input[i] = nums[i];
	}
	sort(input, 0, numsSize-1);
	printf("\nInput Array After Sorting\n");
	for(i =0; i<numsSize; i++)
	{
		printf("[%d] ", input[i]);
	}
	l = 0; r = numsSize-1;
	while(l<r)
	{
		if(input[l] + input[r] == target)
		{
			break;
		}
		if(input[l] + input[r] < target)
		{
			if(r-l > 2)
			{
				left = l;
				right = r;
				mid = 1;
				printf("\n 1 left [%d], right [%d]\n", left, right);
				while(left<right && input[left]+input[right] < target)
				{
					prev = left;
					mid *=2;
					left = l +mid;
				}
				l = prev+1;
			}
			else
			{
				l++;
			}
		}
		else if(input[l] + input[r] > target)
		{
			if(r-l > 2)
			{
				left = l;
				right = r;
				mid = 1;
				prev =r;
				printf("\n 2 left [%d], right [%d]\n", left, right);
				while(left<right && input[left]+input[right] > target)
				{
					prev = right;
					mid *=2;
					right = r - mid;
				}
				r = prev-1;
			}
			else
			{
				r--;
			}
		}
	}
	printf("\nl = [%d], r = [%d]\n", l, r);
	i =0;
	j = numsSize-1;
	*returnSize =0;
	while(*returnSize != 2)
	{
		printf("\n*returnSize %d\n", *returnSize);
		if(nums[i] == input[l] || nums[i] == input[r])
		{
			output[*returnSize] = i;
			*returnSize = (*returnSize) + 1;
		}
		printf("\n*returnSize %d\n", *returnSize);
		if(*returnSize <2 && (nums[j] == input[l] || nums[j] == input[r]))
		{
			output[*returnSize] = j;
			*returnSize = (*returnSize) + 1;
		}
		i++;
		j--;
	}
	if(output[0] > output[1])
	{
		temp = output[0];
		output[0] = output[1];
		output[1] = temp;
	}
	return output;
}

int main(void)
{
	int nums[10] = {1,2,3,4,50,60,70,80,90,100};
	int target = 53;
	int* ret;
	int returnSize =0;

	ret = twoSum(nums, 10, target, &returnSize);
	printf("\n returnSize [%d] index [%d] [%d]\n", returnSize, ret[0], ret[1]);
	printf("\nProgram to find two elements with sum equal to target value\n");
	return 0;
}
