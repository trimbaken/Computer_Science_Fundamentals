#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

char input[100];
int len;
int output[100][100];

void init()
{
	int i =0;
	int j =0;
	for(i =0; i<len; i++)
	{
		for(j=0; j<len; j++)
		{
			output[i][j] = 100;
		}
	}
	for(i =0; i< len; i++)
	{
		output[i][i] = 0;
	}
	return;
}

void print_output_array()
{
	int i=0;
	int j=0;
	printf("\n [%s] [%d] \n", input, len);
	for(i =0; i<len; i++)
	{
		for(j =0; j<len; j++)
		{
			printf("[%d]\t", output[i][j]);
		}
		printf("\n");
	}
}

int is_palindrom(int start, int size)
{
	int i =0;
	int is_palindrom = 1;
	for(i = 0; i<(size/2); i++)
	{
		if(input[start + i] != input[start + size -i])
		{
			is_palindrom = 0;
		}
	}
	return is_palindrom;
}

int get_min_cut()
{
	int i =0;
	int j =0;
	int size =0;
	int is_palindrom_flag;
	len = strlen(input);
	init();

	if(len >1)
	{
		for(i =0; i<len-1; i++)
		{
			output[i][i+1] = 1;
		}
	}
	for(size = 2; size<len; size++ )
	{
		for(i = (len-1-size); i>=0; i-- )
		{
			is_palindrom_flag = 0;
			if((input[i] == input[i+size]) && (size%2 == 0))
			{
				if(is_palindrom(i,size))
				{
					output[i][i+size] = 0;
					is_palindrom_flag = 1;
				}
			}
			if(is_palindrom_flag == 0)
			{
				for(j =i; j<(i+size); j++)
				{
					if(output[i][i+size] > ((output[i][j] + output[j+1][i+size]) +1))
					{
						output[i][i+size] = 1 + (output[i][j] + output[j+1][i+size]);
					}
				}
			}
		}
	}
//	print_output_array();
	return output[0][len-1];
}

int main(void)
{
	system("clear");
	printf("\nEnter String:\n");
	scanf("%s",&input[0]);
	printf("\n Minimum number of cut for palindromic partition: [%d]\n", get_min_cut());

	printf("\n Program to get the minimum number of cur for palindromic partition:\n");
	return 0;
}
