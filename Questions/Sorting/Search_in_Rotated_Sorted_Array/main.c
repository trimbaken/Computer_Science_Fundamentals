#include<stdio.h>

#define MAX_SIZE 5000

int search(int* nums, int numsSize, int target){
	int index = -1;
	int i =0;
	int l, r, m, t =0;
	int left, right, mid =0;

	for(i=0; i<numsSize; i++)
	{
		printf("%d ", nums[i]);
	}
	left = 0;
	right = numsSize-1;
	if(target == nums[left])
	{
		return left;
	}
	if(target == nums[right])
	{
		return right;
	}
	while(left <= right)
	{
		l = nums[left];
		r = nums[right];
		mid = left +(right-left)/2;
		m = nums[mid];
		t = target;
		printf("\n left [%d], mid [%d], right [%d]\n", left, mid, right);
		if(t == l)
		{
			index = left;
			break;
		}
		if(t == m)
		{
			index = mid;
			break;
		}
		if(t == r)
		{
			index = right;
			break;
		}
		if((t >l && t <m && l>r && l<m) || (t>l && t>m && l>m && l>r) || (t<l && t<m && l>r && l>m))
		{
			left = left +1;
			right = mid-1;
		}
		else if ((t>l && t>m && l>r && l<m) || (t<l && t<m && l>r && l<m) || (t<l && t>m && l>r && l>m))
		{
			left = mid +1;
			right = right-1;
		}
		else if (t>l && t<m)
		{
			left = left +1;
			right = mid-1;
		}
		else if (t>l && t>m)
		{
			left = mid +1;
			right = right-1;
		}
		else
		{
			printf("\nTarget %d not found\n", target);
			break;
		}
	}
	return index;
}

int main(void)
{
	int input[MAX_SIZE];
	int input_size =0;
	int search_element =0;
	int i =0;

	printf("Enter Input Array Size:\n");

	scanf("%d",&input_size);
	for(i=0;i<input_size; i++)
	{
		scanf("%d", &input[i]);
	}
	printf("Enter Element Which Need To Search:\n");
	scanf("%d",&search_element);

	printf("\nSerch Element [%d] is present at indext [%d]\n", search_element, search(input, input_size, search_element));

	printf("\n Program to search element in rotated sorted array \n");
	return 0;
}
