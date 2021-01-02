#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	system("clear");

	int n =16;

	int out;
	out = n>>2 |(n << (32-2)) ;
	printf("\n n = [%d]\n",	out);
	printf("\n Program to rotate set of bits in a given number:\n");
	return 0;
}
