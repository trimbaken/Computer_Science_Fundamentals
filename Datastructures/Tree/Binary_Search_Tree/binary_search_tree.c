#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node_s
{
	int value;
	struct node_s* l_child;
	struct node_s* r_child;
}Node;

Node** root = NULL;

Node* create_node(int value)
{
	Node* node = (Node* )malloc(sizeof(Node));

	node->value = value;
	node->l_child = NULL;
	node->r_child = NULL;

	return node;
}

bool insert_element(int value)
{
	Node* new_node = create_node(value);
	if(root == NULL)
	{
		printf("\n First element  \n");
		root = (Node** )malloc(sizeof(Node*));
		*root = new_node;
	}
	printf("\n inserted %d \n", value);
	return true;
}

bool search_element(int value)
{
	Node* temp = *root;

	printf("\n root element [%d] \n", temp->value);
	return true;
}

void init()
{
	int operation =0;
	int value =0;
	while(1)
	{
		printf("\n Select operation \n");
		printf("1 Insert Element: \n");
		printf("2 Search Element: \n");
		printf("3 Delete Element: \n");
		printf("4 Modify Element: \n");
		printf("5 Smallest Element: \n");
		printf("6 Largest Element: \n");
		printf("\n0 Exit: \n");

		printf("\n Enter Operation Number:\n");
		scanf("%d", &operation);
		if(operation < 0 || operation > 6)
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
				printf("Enter Integer Value \n" );
				scanf("%d", &value);
				search_element(value);
				printf("\n Search Element  \n");
				break;
			}
			case 3:
			{
				printf("\n Delete Element  \n");
				break;
			}
			case 4:
			{
				printf("\n Modify Element  \n");
				break;
			}
			case 5:
			{
				printf("\n Smallest Element  \n");
				break;
			}
			case 6:
			{
				printf("\n Largest Element  \n");
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
