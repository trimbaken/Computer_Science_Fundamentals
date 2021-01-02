#include<stdio.h>

int max(int a, int b)
{
	return (a>b)? a: b;
}
int max_three(int a, int b, int c)
{
	return max(a, max(b,c));
}

int max_cut(int n)
{
	int val[n+1];
	val[0] = val[1] = 0;
	int i,j;
	for(i = 1; i <= n; i++ )
	{
		int max_val = 0;
		for(j = 1; j<= i/2; j++)
		{
			max_val = max_three(max_val, (i-j)*j, j*val[i-j]);
		}
		val[i] = max_val;
		printf("\n val[%d] = %d  \n", i, val[i]);
	}

	return val[n];
}

int main(void)
{
	int i = max_cut(20);
	printf("\n Max Cut value = %d  \n", i);
	printf("\n Programm to cut given rod, such that product of the cut's is maximun  \n");
	return 0;
}
