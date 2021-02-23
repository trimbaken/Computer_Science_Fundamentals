#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LEN 10003

char ret[MAX_LEN] = "1229";

struct Node
{
	char val;
	struct Node* next;
};
struct Node* node[MAX_LEN][MAX_LEN];

struct Node* create_node(char value)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node ));
	new_node->val = value;
	new_node->next = NULL;

	return new_node;
}

void print_node(struct Node* temp_node)
{
	printf("\n Value of Node is:\n");
	while(temp_node != NULL)
	{
		printf("%c ", temp_node->val);
		temp_node = temp_node->next;
	}
}

int compare_node(struct Node* node_one, struct Node* node_two)
{
//	printf("\n Compare \n");
//	print_node(node_one);
//	print_node(node_two);
	int node_one_len = 0;
	int node_two_len =0;
	struct Node* temp_node = NULL;

	temp_node = node_one;
	while(temp_node != NULL)
	{
		node_one_len++;
		temp_node = temp_node->next;
	}
	temp_node = node_two;
	while(temp_node != NULL)
	{
		node_two_len++;
		temp_node = temp_node->next;
	}
	if(node_one_len<node_two_len)
	{
		return 1;
	}
	else if(node_two_len<node_one_len)
	{
		return 2;
	}
	while(node_one != NULL || node_two != NULL)
	{
	//	printf("\n Size are same\n");
		if(node_one->val < node_two->val)
		{
			return 1;
		}
		else if(node_two->val < node_one->val)
		{
			return 2;
		}
		else
		{
			node_one = node_one->next;
			node_two = node_two->next;
		}
	}
	return 0;
}

void delete_node(int len, int k)
{
	struct Node* delete = NULL;
	struct Node* temp_node = NULL;
	struct Node* new_node = NULL;
	int i =0;
	int j =0;

	for(i=0; i<len; i++)
	{
		for(j =0; j<=k; j++)
		{
			temp_node = node[i][j];
			while(temp_node != NULL)
			{
				new_node = temp_node->next;
				delete = temp_node;
				if(delete != NULL)
				{
					printf("delete %c ", delete->val);
					free(delete);
				}
				temp_node = new_node;
			}
		}
	}
	return;
}

char * removeKdigits(char * num, int k){
	int len = 0;
	int i =0;
	int j=0;
	int min =0;
	int is_training_zero =1;
	struct Node* temp_node = NULL;
	struct Node* max_node = NULL;
	struct Node* new_node = NULL;
	struct Node* new_node_one = NULL;
	struct Node* new_node_two = NULL;
	len = strlen(num);
//	printf("\nnum [%s], len [%d], k [%d]\n", num, len,k);

	if(k == len)
	{
		ret[0] = '0';
		ret[1] = '\0';
		return ret;
	}
	node[0][0] = create_node(num[len-1]);
	for(i =1; i<=k; i++)
	{
		node[0][i] = NULL;
	}
	for(i =1; i<len; i++)
	{
		node[i][0] = create_node(num[len-i-1]);
		temp_node = node[i][0];
		for(j = len-i; j<len; j++)
		{
			new_node = create_node(num[j]);
			temp_node->next = new_node;
			temp_node = new_node;
		}
	}
/*
	for(i =0; i<=k; i++)
	{
		print_node(node[0][i]);
	}
	for(i =0; i<len; i++)
	{
		print_node(node[i][0]);
	}
*/
	for(i =1; i<len; i++)
	{
		for(j =1; j<=k; j++)
		{
			new_node_one = create_node(num[len-i-1]);
//			new_node_two = create_node('0');

//			if(node[i-1][j]->val != '0')
				new_node_one->next = node[i-1][j];
//			if(node[i-1][j-1]->val != '0')
				new_node_two = node[i-1][j-1];

			min = compare_node(new_node_one, new_node_two);
			if(min == 1)
			{
				node[i][j] = new_node_one;
			}
			else if(min == 2)
			{
				node[i][j] = new_node_two;
			}
			else
			{
				node[i][j] = new_node_one;
			}
		}
	}

	for(i =0; i<len; i++)
	{
		for(j=0; j<=k; j++)
		{
			print_node(node[i][j]);
		}
	}

	temp_node = create_node('9');
	max_node = temp_node;
	for(i=1; i<len; i++)
	{
		new_node = create_node('9');
		temp_node->next = new_node;
		temp_node = new_node;
	}
	for(i =0; i<=k; i++)
	{
		min = compare_node(max_node, node[len-1][i]);
		if(min == 2)
		{
			max_node = node[len-1][i];
		}
	}
	temp_node = max_node;
	is_training_zero =1;
	j =0;
	for(i=0; i<len && temp_node != NULL; i++)
	{
		if(temp_node->val == '0' && is_training_zero == 1)
		{
			temp_node = temp_node->next;
		}
		else
		{
			ret[j] = temp_node->val;
			j++;
			temp_node = temp_node->next;
			is_training_zero =0;
		}
	}
	if(j ==0)
	{
                ret[0] = '0';
                ret[1] = '\0';
                return ret;
	}
	ret[j] = '\0';
//	print_node(max_node);
//	delete_node(len, k);
	return ret;
}

int main(void)
{
	char num[MAX_LEN] = "10200";
	char* output = NULL;
	int i =0;
	int k =0;
	k = 1;
	output = removeKdigits(num, k);
	printf("\n Minimum Value After Removing %d digit is :\n",k);
	while(output[i] != '\0')
	{
		printf("%c ", output[i]);
		i++;
	}
	printf("\nProgram to remove K digit from input string to get minimum value number\n");
	return 0;
}
