#include<stdio.h>

int power(int x, int y)
{
	int res =1;

	while(y>0)
	{
		if(y & 1) // if y is odd
		{
			res = res*x;
		}
		y = y >>1; // y = y/2
		x = x*x;
	}
	return res;
}
int main(void)
{
	int x =0;
	int y =0;

	printf("\nEnter value of X\n");
	scanf("%d", &x);
	printf("\nEnter value of Y\n");
	scanf("%d", &y);
	printf("\nPower of %d, %d is %d\n", x,y,power(x,y));
	printf("\nProgram to implement power function x^y in log(y)\n");
	return 0;
}
