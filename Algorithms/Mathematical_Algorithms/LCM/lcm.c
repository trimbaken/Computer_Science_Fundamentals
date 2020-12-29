#include<stdio.h>
#define MAX_SIZE 1000

typedef struct binary_tree_s
{
	int node_value;
	int node_count;
	struct binary_tree_s* left_child;
	struct binary_tree_s* right_child;
}binary_tree_t;

binary_tree_t binary_tree[MAX_SIZE];
binary_tree_t* binary_tree_root_node = NULL;
int binary_tree_count =-1;

binary_tree_t* create_binary_tree_node(int node_value)
{
	binary_tree_count++;
	if(binary_tree_count >= MAX_SIZE)
	{
		printf("\nBinary tree is full\n");
		return NULL;
	}
	binary_tree[binary_tree_count].node_value = node_value;
	binary_tree[binary_tree_count].node_count = 1;
	binary_tree[binary_tree_count].left_child = NULL;
	binary_tree[binary_tree_count].right_child = NULL;

	return &binary_tree[binary_tree_count];
}

int search_binary_tree_node(int node_value)
{
	int ret =0;
	binary_tree_t* temp_node = binary_tree_root_node;

	while(temp_node != NULL)
	{
		if(temp_node->node_value == node_value)
		{
			temp_node->node_count++;
			ret = temp_node->node_count;
			break;
		}
		if(node_value < temp_node->node_value)
		{
			temp_node = temp_node->left_child;
		}
		else
		{
			temp_node = temp_node->right_child;
		}
	}
	return ret;
}

int is_binary_tree_node_present(int node_value)
{
	int ret =0;
	binary_tree_t* temp_node = binary_tree_root_node;

	while(temp_node != NULL)
	{
		if(temp_node->node_value == node_value && temp_node->node_count>0)
		{
			temp_node->node_count--;
			ret = 1;
			break;
		}
		if(node_value < temp_node->node_value)
		{
			temp_node = temp_node->left_child;
		}
		else
		{
			temp_node = temp_node->right_child;
		}
	}
	return ret;
}


int insert_binary_tree_node(int node_value)
{
	int ret =0;
	binary_tree_t* temp_node = NULL;
	if(binary_tree_root_node == NULL)
	{
		binary_tree_root_node = create_binary_tree_node(node_value);
		ret =1;
	}
	else
	{
		if(!search_binary_tree_node(node_value))
		{
			temp_node = binary_tree_root_node;
			while(1)
			{
				if(node_value < temp_node->node_value)
				{
					if(temp_node->left_child != NULL)
					{
						temp_node = temp_node->left_child;
					}
					else
					{
						temp_node->left_child = create_binary_tree_node(node_value);
						break;
					}
				}
				else
				{
					if(temp_node->right_child != NULL)
					{
						temp_node = temp_node->right_child;
					}
					else
					{
						temp_node->right_child = create_binary_tree_node(node_value);
						break;
					}
				}
			}
		}
		else
		{
			printf("\nNode is already present\n");
			ret =0;
		}
	}
	return ret;
}

void inorder_traversal(binary_tree_t* tree_node)
{
	if(tree_node == NULL)
	{
		return;
	}
	inorder_traversal(tree_node->left_child);
	printf("%d ", tree_node->node_value);
	inorder_traversal(tree_node->right_child);
	return;
}

void print_set(int* set, int set_size)
{
	int i =0;
	printf("\nAll elements of set are:\n");
	for(i=0; i<set_size; i++)
	{
		printf("%d ", set[i]);
	}
}

void lcm_of_numbers(int set_one_size, int* set_one, int set_two_size, int* set_two)
{
	int i =0;
	int union_set[MAX_SIZE*2];
	int union_set_count =0;
	int lcm =1;

	if(set_one_size ==0 && set_two_size == 0)
	{
		printf("\n Both set are empty\n");
		return;
	}
	for(i =0; i<set_one_size; i++)
	{
		union_set[union_set_count] = set_one[i];
		union_set_count++;
		insert_binary_tree_node(set_one[i]);
	}
	for(i =0; i<set_two_size; i++)
	{
		if(!is_binary_tree_node_present(set_two[i]))
		{
			union_set[union_set_count] = set_two[i];
			union_set_count++;
		}
	}
	for(i=0; i<union_set_count; i++)
	{
		lcm *= union_set[i];
	}
	printf("\nLCM of two number : %d\n", lcm);
	return;
}


void find_prime_factors(int input_number, int* prime_factors, int* set_size)
{
        int i =0;
        int count =0;
//        int prime_factors[1000];
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
                prime_factors[count] = input_number;
                count++;
        }
        printf("\nPrime Factors are :\n");
        for(i =0; i<count; i++)
        {
                printf("[%d]", prime_factors[i]);
        }
	*set_size = count;
}

int main(void)
{
	int i =0;
	int set_one_size =0;
	int set_one[MAX_SIZE];
	int set_two_size =0;
	int set_two[MAX_SIZE];
	int first_number;
	int second_number;
	printf("\nEnter first number:\n");
	scanf("%d",&first_number);
	printf("\nEnter second number\n");
	scanf("%d",&second_number);
	find_prime_factors(first_number, set_one, &set_one_size);
	find_prime_factors(second_number, set_two, &set_two_size);
	print_set(set_one, set_one_size);
	print_set(set_two, set_two_size);
	lcm_of_numbers(set_one_size, set_one, set_two_size, set_two);
	printf("\n Program to implement two set union operation of set theory:\n");
	return 0;
}
