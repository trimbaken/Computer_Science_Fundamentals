#include<stdio.h>

void find_signs(int number_one, int number_two)
{
	printf("\nInput numbers are [%d] [%d]\n", number_one, number_two);

	unsigned int temp = ((number_one >> ((sizeof(number_one))*8-1)) & 1) ^ ((number_two >>((sizeof(number_two))*8 -1))&1);
	printf("\ntemp [%d]\n", temp);

	if((number_one ^ number_two) <0)
	{
		printf("\nNumbers have opposite signs\n");
	}
	else
	{
		printf("\nNumbers have similar signs\n");
	}
}

int main(void)
{
	int number_one =0;
	int number_two =0;

	printf("\nEnter first number\n");
	scanf("%d",&number_one);
	printf("\nEnter second number\n");
	scanf("%d",&number_two);

	find_signs(number_one, number_two);
	printf("\nProgram to find signs of input numbers\n");
	return 0;
}
