#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node_s
{
	int value;
	struct node_s* l_child;
	struct node_s* r_child;
	struct node_s* parent;
}Node;

Node** root = NULL;

Node* create_node(int value)
{
	Node* node = (Node* )malloc(sizeof(Node));

	node->value = value;
	node->l_child = NULL;
	node->r_child = NULL;
	node->parent = NULL;

	return node;
}

bool is_empty()
{
	if(root == NULL)
	{
		printf("\n BST is empty \n");
		return true;
	}
	return false;
}

bool insert_element(int value)
{
	Node* new_node = NULL;
	Node* temp_node = NULL;
	if(root == NULL)
	{
		printf("\n First element  \n");
		root = (Node** )malloc(sizeof(Node*));
		new_node = create_node(value);
		*root = new_node;
	}
	else
	{
		temp_node = *root;
		while(temp_node != NULL)
		{
			if(temp_node->value == value)
			{
				printf("\n Element %d is already present in tree  \n", value);
				return false;
			}
			else if(value < temp_node->value)
			{
				if(temp_node->l_child == NULL)
				{
					new_node = create_node(value);
					temp_node->l_child = new_node;
					new_node->parent = temp_node;
					break;
				}
				else
				{
					temp_node = temp_node->l_child;
				}
			}
			else
			{
				if(temp_node->r_child == NULL)
				{
					new_node = create_node(value);
					temp_node->r_child = new_node;
					new_node->parent = temp_node;
					break;
				}
				else
				{
					temp_node = temp_node->r_child;
				}
			}
		}
	}
	printf("\n inserted %d \n", value);
	return true;
}

Node* search_element(int value)
{
	Node* temp_node = NULL;
	if(is_empty())
	{
		return NULL;
	}
	temp_node = *root;
	while(temp_node != NULL)
	{
		if(temp_node->value == value)
		{
			printf("\n Element %d is present\n", value);
			break;
		}
		else if(value < temp_node->value)
		{
			temp_node = temp_node->l_child;
		}
		else
		{
			temp_node = temp_node->r_child;
		}
	}
	if(temp_node == NULL)
	{
		printf("\n Element %d is not present  \n", value);
		return NULL;
	}
	return temp_node;
}

Node* get_successor(Node* temp_node)
{
	Node* successor = temp_node->r_child;

	while(successor->l_child != NULL)
	{
		successor = successor->l_child;
	}
	return successor;
}

Node* get_predecessor(Node* temp_node)
{
	Node* predecessor = temp_node->l_child;

	while(predecessor->r_child != NULL)
	{
		predecessor = predecessor->r_child;
	}
	return predecessor;
}

void inorder_traval_loop(Node* temp_node)
{
	if(temp_node == NULL)
		return;
	inorder_traval_loop(temp_node->l_child);
	printf("%d ", temp_node->value);
	inorder_traval_loop(temp_node->r_child);

	return;
}

bool inorder_traval()
{
	Node* temp_node = NULL;
	if(is_empty())
	{
		return false;
	}
	temp_node = *root;
	inorder_traval_loop(temp_node);
}

bool delete_element(int value)
{
	Node* temp_node = NULL;
	Node* successor = NULL;
	Node* predecessor = NULL;
	if(is_empty())
	{
		return false;
	}
	temp_node = *root;
	// Delete root node
	if(temp_node->value == value)
	{
		if(temp_node->l_child == NULL && temp_node->r_child == NULL)
		{
			free(root);
			root = NULL;
		}
	}
	else
	{
		while(temp_node != NULL)
		{
			if(temp_node->value == value)
			{
				printf("\n Element %d is present\n", value);
				break;
			}
			else if(value < temp_node->value)
			{
				temp_node = temp_node->l_child;
			}
			else
			{
				temp_node = temp_node->r_child;
			}
		}
	}
	if(temp_node == NULL)
	{
		printf("\n Element %d is not present  \n", value);
		return false;
	}
	if(temp_node->r_child != NULL)
	{
		successor = get_successor(temp_node);
		temp_node->value = successor->value;
		if(temp_node->r_child == successor)
		{
			temp_node->r_child = successor->r_child;
		}
		else
		{
			successor->parent->l_child = successor->r_child;
		}
		free(successor);
	}
	else if(temp_node->l_child != NULL)
	{
		predecessor = get_predecessor(temp_node);
		temp_node->value = predecessor->value;
		if(predecessor == temp_node->l_child)
		{
			temp_node->l_child = predecessor->l_child;
		}
		else
		{
			predecessor->parent->r_child = predecessor->l_child;
		}
		free(predecessor);
	}
	else
	{
		if(temp_node->parent != NULL)
		{
			if(temp_node->parent->l_child == temp_node)
			{
				temp_node->parent->l_child = NULL;
			}
			else
			{
				temp_node->parent->r_child = NULL;
			}
		}
		free(temp_node);
	}
	return true;
}

bool modify_element(int current_value, int new_value)
{
	if(is_empty())
	{
		return false;
	}
	if(delete_element(current_value) == true)
	{
		insert_element(new_value);
	}
	else
	{
		return false;
	}
	return true;
}

void get_smallest_element()
{
	Node* temp_node = *root;

	if(is_empty())
	{
		return;
	}
	if(temp_node->l_child == NULL)
	{
		printf("\n Smallest Element is %d \n", temp_node->value);
	}
	else
	{
		while(temp_node->l_child != NULL)
		{
			temp_node = temp_node->l_child;
		}
		printf("\n Smallest Element is %d \n", temp_node->value);
	}
	return;
}

void get_largest_element()
{
	Node* temp_node = *root;

	if(is_empty())
	{
		return;
	}
	if(temp_node->r_child == NULL)
	{
		printf("\n Largest Element is %d \n", temp_node->value);
	}
	else
	{
		while(temp_node->r_child != NULL)
		{
			temp_node = temp_node->r_child;
		}
		printf("\n Largest Element is %d \n", temp_node->value);
	}
	return;
}

void init()
{
	int operation =0;
	int value =0;
	int current_value =0;
	int new_value =0;
	while(1)
	{
		printf("\n Select operation \n");
		printf("1 Insert Element: \n");
		printf("2 Search Element: \n");
		printf("3 Delete Element: \n");
		printf("4 Modify Element: \n");
		printf("5 Smallest Element: \n");
		printf("6 Largest Element: \n");
		printf("7 Print All Element: \n");
		printf("\n0 Exit: \n");

		printf("\n Enter Operation Number:\n");
		scanf("%d", &operation);
		if(operation < 0 || operation > 7)
		{
			system("clear");
			printf("\n Invalid operation selected  \n");
			continue;
		}
		system("clear");
		switch(operation)
		{
			case 1:
			{
				printf("\n Insert Element  \n");
				printf("Enter Integer Value \n" );
				scanf("%d", &value);
				insert_element(value);
				break;
			}
			case 2:
			{
				printf("\n Search Element  \n");
				printf("Enter Integer Value \n" );
				scanf("%d", &value);
				search_element(value);
				break;
			}
			case 3:
			{
				printf("\n Delete Element  \n");
				printf("\n Enter Integer Value  \n");
				scanf("%d", &value);
				delete_element(value);
				break;
			}
			case 4:
			{
				printf("\n Modify Element  \n");
				printf("\n Enter Integer value which need to modify \n");
				scanf("%d", &current_value);
				printf("\n Enter new Integer value \n");
				scanf("%d", &new_value);
				modify_element(current_value, new_value);
				break;
			}
			case 5:
			{
				get_smallest_element();
				break;
			}
			case 6:
			{
				get_largest_element();
				break;
			}
			case 7:
			{
				printf("\n All elements of tree are: \n");
				inorder_traval();
				printf("\n\n");
				break;
			}

			case 0:
			{
				printf("\n Thanks for using our service:  \n");
				return;
			}
			default:
				break;
		}
	}
}

int main(void)
{
	system("clear");

	init();

	printf("\n Program to implement Binary Search Tree and its operations.  \n\n");
	return 0;
}
