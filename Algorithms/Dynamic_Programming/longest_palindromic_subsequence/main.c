#include<stdio.h>
#define max(x,y) x>y?x:y
#define MAX_SIZE 100

int lps(char S[], int n)
{
	int lps[n][n];
	int i =0;
	int j =0;
	int L = 0;
	int ret =0;
	for(i= 0; i<n;i++)
	{
		for(j =0; j<n; j++)
		{
			if(i==j)
			{
				lps[i][j] = 1;
			}
			else
			{
				lps[i][j] = 0;
			}
		}
	}
	for(L =2; L<=n; L++)
	{
		for(i =0; i<n-L+1; i++)
		{
			j = i+L-1;
			if(S[i] == S[j])
			{
				lps[i][j] = lps[i+1][j-1] + 2;
			}
			else
			{
				lps[i][j] = max(lps[i][j-1], lps[i+1][j]);
			}
			ret = max(ret, lps[i][j]);
		}
	}

	return ret;
}

int main(void)
{
	char S[MAX_SIZE];
	int result =0;
	int len =0;

	printf("\nEnter String\n");
	scanf("%s", S);
	while(S[len] != '\0')
	{
		len++;
	}
	result = lps(S, len);
	printf("\n Length of longest palindromic subsequence is = %d  \n", result);

	printf("\n Program to get longest palindromic subsequence:  \n");
	return 0;
}

