#include<stdio.h>

int isSubsetSum(int set[], int n, int sum)
{
	int subset[sum+1][n+1];
	int i;
	int j;

	for(i=0,j=0; j<=n; j++)
	{
		subset[i][j] = 1;
	}
	for(i =1, j=0; i<=sum; i++)
	{
		subset[i][j] = 0;
	}
	for(i =1; i<=sum; i++)
	{
		for(j=1;j<=n;j++)
		{
			subset[i][j] = subset[i][j-1];
			if(i >= set[j-1])
			{
				subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
			}
		}
	}
	for(i=0;i<=sum;i++)
	{
		for(j=0;j<=n;j++)
		{
			printf("%4d",subset[i][j]);
		}
		printf("%4d \n", i);
	}
	return subset[sum][n];
}

int main()
{
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 9;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSum(set, n, sum))
     printf("\n Found a subset with given sum \n");
  else
     printf("\n No subset with given sum \n");
  return 0;
}
