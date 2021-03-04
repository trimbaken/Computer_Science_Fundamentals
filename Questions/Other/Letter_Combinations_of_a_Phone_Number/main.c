#include<stdio.h>
#include<stdlib.h>

#define MAX_NODE 400
#define MAX_LEN 5

char* key_node[MAX_LEN*2];
char* output[MAX_NODE];
int output_count =0;
int is_init =0;

void init()
{
	int i =0;
	is_init =1;
	key_node[2] = (char*)malloc(sizeof(char)* MAX_LEN);
	key_node[2] = "abc";
	key_node[3] = (char*)malloc(sizeof(char)* MAX_LEN);
	key_node[3] = "def";
	key_node[4] = (char*)malloc(sizeof(char)* MAX_LEN);
	key_node[4] = "ghi";
	key_node[5] = (char*)malloc(sizeof(char)* MAX_LEN);
	key_node[5] = "jkl";
	key_node[6] = (char*)malloc(sizeof(char)* MAX_LEN);
	key_node[6] = "mno";
	key_node[7] = (char*)malloc(sizeof(char)* MAX_LEN);
	key_node[7] = "pqrs";
	key_node[8] = (char*)malloc(sizeof(char)* MAX_LEN);
	key_node[8] = "tuv";
	key_node[9] = (char*)malloc(sizeof(char)* MAX_LEN);
	key_node[9] = "wxyz";

	for(i =0; i<MAX_NODE; i++)
	{
		output[i] = (char*)malloc(sizeof(char)* MAX_LEN);

	}

}

char ** letterCombinations(char * digits, int* returnSize){
/*
	output[0] = (char*)malloc(sizeof(char)* MAX_LEN);
	output[0] = "ab";
	*returnSize =1;
*/
	int i =0;
	int j =0;
	int k =0;
	int a =0;
	int start_index = -1;
	int end_index =-1;
	int temp_index =0;
	int num =0;

	if(digits[0] == '\0')
	{
		*returnSize = 0;
		return NULL;
	}
	if(is_init == 0)
	{
		init();
	}
	num = digits[0] -'0';

	while(key_node[num][i] != '\0')
	{
		end_index++;
		output[end_index][0] = key_node[num][i];
		output[end_index][1] = '\0';
		if(start_index < 0)
			start_index++;
		i++;
	}
	i =1;
	while(digits[i] != '\0')
	{
		num = digits[i] - '0';
		temp_index = end_index+1;
		a = 0;
		while(key_node[num][a] != '\0')
		{
			for(j =start_index; j<=end_index; j++)
			{
				k =0;
				while(output[j][k] != '\0')
				{
					output[temp_index][k] = output[j][k];
					k++;
				}
				output[temp_index][k] = key_node[num][a];
				k++;
				output[temp_index][k] = '\0';
				temp_index++;
			}
			a++;
		}
		start_index = end_index +1;
		end_index = temp_index-1;
		i++;
	}
	*returnSize = end_index - start_index +1;
	return &output[start_index];
}

int main(void)
{
	int returnSize;
	int i =0;
	char** ret = letterCombinations("9999", &returnSize);
	printf("\n returnSize %d \n", returnSize);
	for(i=0; i<returnSize; i++)
	{
		printf("%s ", ret[i]);
	}
	printf("\n Letter Combinations of a Phone Number \n");
	return 0;
}
