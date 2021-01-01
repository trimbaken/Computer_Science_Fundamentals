#include<stdio.h>
#define max(x,y) x>y?x:y
#define MAX_LEN 100

int lcs(char str1[], char str2[], int n, int m)
{
	int arr[n+1][m+1];
	int i =0;
	int j =0;
	for(i=0;i<=n;i++)
	{
		arr[i][0] = 0;
	}
	for(j=0;j<=m;j++)
	{
		arr[0][j] = 0;
	}

	for(i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)
		{
			if(str1[i-1] == str2[j-1])
			{
				arr[i][j] = arr[i-1][j-1] + 1;
			}
			else
			{
				arr[i][j] = max(arr[i][j-1], arr[i-1][j]);
			}
		}
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
	return arr[i-1][j-1];
}

int main(void)
{
	char str1[MAX_LEN];
	char str2[MAX_LEN];
	int result = 0;
	int str1_len =0;
	int str2_len =0;

	printf("\nEnter String One\n");
	scanf("%s", str1);
	printf("\nEnter String Two\n");
	scanf("%s", str2);
	while(str1[str1_len] != '\0')
	{
		str1_len++;
	}
	while(str2[str2_len] != '\0')
	{
		str2_len++;
	}
	result = lcs(str1, str2, str1_len, str2_len);
	printf("\n size of longest common subsequence is = %d  \n", result);
	printf("\n Program to get Longest common subsequence:  \n");
	return 0;
}
