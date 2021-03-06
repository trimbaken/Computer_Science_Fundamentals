#include<stdio.h>

#define MAX_SIZE 30002

int my_abs(int a, int b, int h)
{
	int ret = a>b?b:a;
	ret -= h;
	printf("\nret [%d]", ret);
	return ret;
}
int trap(int* height, int heightSize){
	int i =0;
	int ret =0;
	int start_index =0;
	int end_index =0;
	int left_height[MAX_SIZE];
	int right_height[MAX_SIZE];

	if(heightSize <= 1)
	{
		return 0;
	}
	left_height[0] = height[0];
	right_height[heightSize-1] = height[heightSize-1];
	for(i=0; i< heightSize; i++)
	{
		//printf(" %d ", height[i]);
		start_index = i;
		end_index = heightSize - i -1;
		printf("\n start_index %d, end_index %d, height %d", start_index, end_index, height[i]);
		if(start_index < end_index)
		{
			if(start_index == 0)
			{
				left_height[start_index] = height[start_index];
				right_height[end_index] = height[end_index];
			}
			else
			{
				left_height[start_index] = (height[start_index] > left_height[start_index-1]?height[start_index]:left_height[start_index-1]);
				right_height[end_index] = (height[end_index]>right_height[end_index+1]?height[end_index]:right_height[end_index+1]);
			}
		}
		else if (start_index == end_index)
		{
			if(height[start_index] < left_height[start_index-1] && height[end_index]<right_height[end_index+1])
			{
				ret += my_abs(left_height[start_index-1], right_height[end_index+1], height[start_index]);
			}
			left_height[start_index] = (height[start_index] > left_height[start_index-1]?height[start_index]:left_height[start_index-1]);
			right_height[end_index] = (height[end_index]>right_height[end_index+1]?height[end_index]:right_height[end_index+1]);
		}
		else
		{
			if(height[start_index] < left_height[start_index-1])
			{
				ret += my_abs(left_height[start_index-1], right_height[start_index], height[start_index]);
			}
			left_height[start_index] = (height[start_index] > left_height[start_index-1]?height[start_index]:left_height[start_index-1]);
			if(height[end_index] < right_height[end_index+1])
			{
				ret += my_abs(left_height[end_index], right_height[end_index+1], height[end_index]);
			}
			right_height[end_index] = (height[end_index]>right_height[end_index+1]?height[end_index]:right_height[end_index+1]);
		}
	}
	for(i =0; i<heightSize; i++)
	{
		printf("\nleft_height[%d] %d, right_height[%d] %d", i, left_height[i], i, right_height[i]);
	}
	return ret;
}

int main(void)
{
	int height[13] = {0,1,0,2,1,0,1,3,2,1,2,1};

	printf("\nTraped water count %d\n", trap(height, 12));
	printf("\n Trapping Rain Water\n");
	return 0;
}
