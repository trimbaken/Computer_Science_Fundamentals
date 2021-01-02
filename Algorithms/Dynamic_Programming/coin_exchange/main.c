#include<stdio.h>
#define max(x,y) x>y?x:y

int coin_change(int S[], int sum, int n)
{
	int arr[sum +1][n+1];
	int i =0;
	int j =0;

	for(i = 1; i<=sum; i++)
	{
		arr[i][0] = 0;
	}
	for(j =0; j<=n; j++)
	{
		arr[0][j] = 1;
	}
	for(i= 1; i<=sum; i++)
	{
		for(j =1; j<=n; j++)
		{
			arr[i][j] = arr[i][j-1];
			if(i>=S[j-1])
			{
				arr[i][j] = arr[i][j] +  arr[i- S[j-1]][j] ;
			}
		}
	}
	return arr[i-1][j-1];
}

int main(void)
{
	int S[] = {2,5,3,6};
	int sum = 10;
	int result =0;

	result = coin_change(S, sum, 4);
	printf("\n Number of pssible way to change sum %d are %d  \n", sum, result);

	printf("\n Program to implement coin change problem:  \n");
	return 0;
}
