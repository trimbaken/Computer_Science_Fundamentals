#include<stdio.h>

void find_prime_factors(int input_number)
{
	int i =0;
	int count =0;
	int prime_factors[1000];
	int max_value_prime = 0;
	max_value_prime = input_number/2;
	while(input_number%2 == 0)
	{
		input_number = input_number/2;
		prime_factors[count] = 2;
		count++;
	}
	if(input_number>0)
	{
		for(i =3; i< max_value_prime; i += 2)
		{
			while(input_number%i == 0)
			{
				input_number = input_number/i;
				prime_factors[count] = i;
				count++;
			}
		}
	}
	if(count == 0)
	{
		printf("\n Input number is prime number\n");
		prime_factors[count] = 1;
		count++;
		prime_factors[count] = input_number;
		count++;
	}
	printf("\nPrime Factors are :\n");
	for(i =0; i<count; i++)
	{
		printf("[%d]", prime_factors[i]);
	}
}

int main(void)
{
	int input_number;
	printf("\nEnter Number\n");
	scanf("%d",&input_number);
	find_prime_factors(input_number);
	printf("\nProgram to find prime factors of input number\n");
	return 0;
}
