#include<stdio.h>

int reverse(int x){
	int ret =0;
	int len =0;
	int temp =0;
	int is_negative =0;
	int num[10];
	int i =0;
	int m =0;
	int max_positive[11] = {2,1,4,7,4,8,3,6,4,8};
	int max_negative[11] = {2,1,4,7,4,8,3,6,4,7};
	int int_max_negative = -2147483648;

	if(x == int_max_negative)
	{
		printf("\nMax Negative\n");
		return 0;
	}
	if(x<0)
	{
		is_negative =1;
		temp = 0-x;
	}
	else
	{
		temp =x;
	}
	while(temp>0)
	{
		num[len] = temp%10;
		len++;
		temp = temp/10;
	}
	m =1;
	if(len == 10 && is_negative ==1)
	{
		for(i =0; i<10; i++)
		{
			if(num[i] < max_negative[i])
				break;
			if(num[i] > max_negative[i])
				return 0;
		}
	}
	else if(len == 10 && is_negative ==0)
	{
		for(i =0; i<10; i++)
		{
			if(num[i] < max_positive[i])
				break;
			if(num[i] > max_positive[i])
				return 0;
		}
	}
	for(i=len-1; i>=0; i--)
	{
		ret += num[i]*m;
		if(i ==0)
			break;
		m *= 10;
	}
	if(is_negative == 1)
	{
		ret = 0-ret;
	}
	return ret;

}

int main(void)
{
	int x = 123;

	printf("\n Reverse of %d is %d \n", x, reverse(x));
	printf("\n Reverse of %d is %d \n", -123, reverse(-123));
	printf("\n Reverse of %d is %d \n", 0, reverse(0));
	printf("\n Reverse of %d is %d \n", 1, reverse(1));
	printf("\n Reverse of %d is %d \n", -1, reverse(-1));
	printf("\n Reverse of %d is %d \n", -2147483412, reverse(-2147483412));
	printf("\n Reverse of %lld is %d \n", -2147483648, reverse(-2147483648));
	printf("\nProgram to Reverse Integer\n");
	return 0;
}
