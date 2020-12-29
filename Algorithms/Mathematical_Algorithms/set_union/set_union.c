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

void union_of_set(int set_one_size, int* set_one, int set_two_size, int* set_two)
{
	int i =0;
	int union_set[MAX_SIZE*2];
	int union_set_count =0;
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
	printf("\nUnion of two set is:\n");
	for(i=0; i<union_set_count; i++)
	{
		printf("%d ", union_set[i]);
	}
	return;
}

int main(void)
{
	int i =0;
	int set_one_size =0;
	int set_one[MAX_SIZE];
	int set_two_size =0;
	int set_two[MAX_SIZE];
	printf("\nEnter size of set one:\n");
	scanf("%d",&set_one_size);
	printf("\nEnter [%d] elements of set one\n", set_one_size);
	for(i =0; i<set_one_size; i++)
	{
		scanf("%d",&set_one[i]);
	}
	printf("\nEnter size of set two:\n");
	scanf("%d",&set_two_size);
	printf("\nEnter [%d] elements of set two\n", set_two_size);
	for(i =0; i<set_two_size; i++)
	{
		scanf("%d",&set_two[i]);
	}
	print_set(set_one, set_one_size);
	print_set(set_two, set_two_size);
	union_of_set(set_one_size, set_one, set_two_size, set_two);
	printf("\n Program to implement two set union operation of set theory:\n");
	return 0;
}
